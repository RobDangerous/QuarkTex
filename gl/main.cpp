#include <fstream>
#include <string>
#include <list>
#include <stdexcept>
#include <functional>
#include <algorithm>

using std::string;
using std::ofstream;

std::ifstream glFuncs("glFuncs.txt");

class Type {
	string type;
public:
	void parse() {
		glFuncs >> type;
	}
	void print(ofstream& out) {
		out << "GL" << type;
	}
	bool isVoid() { return type == "void"; }
	bool isDouble() { return (type == "double") || (type == "clampd"); }
};

class FunctionName {
	string name;
public:
	void parse() {
		char c;
		for (glFuncs >> c; c != '('; glFuncs >> c) name += c;
		glFuncs.putback(c);
	}
	void print(ofstream& out) {
		out << name;
	}
};

class ArgumentName {
	string name;
public:
	void parse() {
		char c;
		for (glFuncs >> c; c != ',' && c != ')'; glFuncs >> c) name += c;
		glFuncs.putback(c);
	}
	void print(ofstream& out) {
		out << name;
	}
};

class ArgumentList {
	std::list<Type*> types;
	std::list<ArgumentName*> names;
public:
	void parse() {
		char c;
		glFuncs >> c;
		if (c != '(') throw std::runtime_error("( expected");
		glFuncs >> c;
		if (c == ')') return;
		glFuncs.putback(c);
		for (;;) {
			Type* type = new Type;
			ArgumentName* name = new ArgumentName;
			type->parse();
			name->parse();
			types.push_back(type);
			names.push_back(name);
			glFuncs >> c;
			if (c == ',') continue;
			if (c == ')') break;
			throw std::runtime_error(", or ) expected");
		}
	}
	void print(ofstream& out) {
		out << '(';
		if (types.empty()) out << "void";
		else {
			int fp = 0;
			int d = 1;
			int a = 1;
			std::list<Type*>::iterator typeit = types.begin();
			std::list<ArgumentName*>::iterator nameit = names.begin();
			for (;;) {
				(*typeit)->print(out);
				out << " ";
				(*nameit)->print(out);
				if ((*typeit)->isDouble()) {
					out << " __asm(\"fp" << fp << "\")";
					++fp;
					if (d < 7) d += 2;
					else if (d == 7) { ++d; ++a; }
					else a += 2;
				}
				else {
					if (d < 8) { out << " __asm(\"d" << d << "\")"; ++d; }
					else { out << " __asm(\"a" << a << "\")"; ++a; }
				}
				++typeit; ++nameit;
				if (typeit != types.end()) out << ", ";
				else break;
			}
		}
		out << ')';
	}
	bool hasDoubles() {
		for (std::list<Type*>::iterator it = types.begin(); it != types.end(); ++it) if ((*it)->isDouble()) return true;
		return false;
	}
	void fpuasm(ofstream& out) {
		out << std::endl << "asm volatile (\"" << std::endl;
		out << "move.l a5,_a5" << std::endl;
		int d = 1;
		int a = 1;
		int fp = 0;
		for (std::list<Type*>::iterator it = types.begin(); it != types.end(); ++it) {
			if ((*it)->isDouble()) {
				out << "fmove.d fp" << fp << ",_fp" << fp << std::endl;
				++fp;
				if (d < 7) d += 2;
				else if (d == 7) { ++d; ++a; }
				else a += 2;
			}
			else {
				if (d < 8) ++d;
				else ++a;
			}
		}
		d = a = 1;
		fp = 0;
		for (std::list<Type*>::iterator it = types.begin(); it != types.end(); ++it) {
			if ((*it)->isDouble()) {
				out << "move.l _fp" << fp << ",";
				if (d < 8) { out << "d" << d; ++d; }
				else { out << "a" << a; ++a; }
				out << "\\nmove.l _fp" << fp << ",";
				if (d < 8) { out << "d" << d; ++d; }
				else { out << "a" << a; ++a; }
				out << std::endl;
				++fp;
			}
			else {
				if (d < 8) ++d;
				else ++a;
			}
		}
		out << "\");" << std::endl;
	}
};

class Function {
	Type returnType;
	FunctionName functionName;
	ArgumentList argumentList;
public:
	void parse() {
		returnType.parse();
		functionName.parse();
		argumentList.parse();
		string s;
		glFuncs >> s;
		if (s != ";") throw std::runtime_error("; expected");
	}
	void print(ofstream& out) {
		returnType.print(out);
		out << " ";
		functionName.print(out);
		argumentList.print(out);
		out << ';' << std::endl;
	}
	void staticDeclare(ofstream& glc) {
		functionName.print(glc);
		glc << "," << std::endl;
	}
	void DLLfunc(ofstream& glc) {
		functionName.print(glc);
		glc << " = DLLfunc(gl, \"gl";
		functionName.print(glc);
		glc << "\");" << std::endl;
	}
	void definitions(ofstream& glc) {
		returnType.print(glc);
		glc << " _gl";
		functionName.print(glc);
		argumentList.print(glc);
		if (returnType.isVoid()) {
			glc << " {";
			if (argumentList.hasDoubles()) argumentList.fpuasm(glc);
			glc << "EXEC(";
			functionName.print(glc);
			glc << ");" << std::endl;
			if (argumentList.hasDoubles()) glc << "asm volatile (\"move.l _a5,a5\");" << std::endl;
			glc << "}" << std::endl;
		}
		else {
			glc << " {";
			if (argumentList.hasDoubles()) argumentList.fpuasm(glc);
			glc << "EXEC_RET(";
			functionName.print(glc);
			glc << ");" << std::endl;
			if (argumentList.hasDoubles()) glc << "asm volatile (\"move.l _a5,a5\");" << std::endl;
			glc << "return ret; }" << std::endl;
		}
	}
	void declarations(ofstream& glh) {
		returnType.print(glh);
		glh << " _gl";
		functionName.print(glh);
		argumentList.print(glh);
		glh << ";" << std::endl;
	}
};

int main() {
	std::list<Function*> functions;
	typedef std::list<Function*>::iterator iterator;
	while (glFuncs.peek() != std::char_traits<char>::eof()) {
		Function* function = new Function;
		function->parse();
		functions.push_back(function);
	}
	ofstream glstatic("glstatichandles.auto.c");
	for (iterator it = functions.begin(); it != functions.end(); ++it) (*it)->staticDeclare(glstatic);

	ofstream gldll("glDLLfunc.auto.c");
	for (iterator it = functions.begin(); it != functions.end(); ++it) (*it)->DLLfunc(gldll);
	ofstream gldef("gldefinitions.auto.c");
	for (iterator it = functions.begin(); it != functions.end(); ++it) (*it)->definitions(gldef);

	ofstream glh("gldeclarations.auto.h");
	for (iterator it = functions.begin(); it != functions.end(); ++it) (*it)->declarations(glh);
}