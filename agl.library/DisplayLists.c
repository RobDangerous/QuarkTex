#include "../gl/gl.h"

GLboolean glIsList(GLuint list __asm("d0")) {
	LOG;
	return _glIsList(list);
}
void glDeleteLists(GLuint list __asm("d0"), GLsizei range __asm("d1")) {
	LOG;
	PUSHREGS;
	_glDeleteLists(list, range);
	POPREGS;
}
void glGenLists(GLsizei range __asm("d0")) {
	LOG;
	PUSHREGS;
	_glGenLists(range);
	POPREGS;
}
void glNewList(GLuint list __asm("d0"), GLenum mode __asm("d1")) {
	LOG;
	PUSHREGS;
	_glNewList(list, mode);
	POPREGS;
}
void glEndList(void) {
	LOG;
	PUSHREGS;
	_glEndList();
	POPREGS;
}
void glCallList(GLuint list __asm("d0")) {
	LOG;
	PUSHREGS;
	_glCallList(list);
	POPREGS;
}
void glCallLists(GLsizei n __asm("d0"), GLenum type __asm("d1"), void *lists __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (type) {
	case GL_SHORT:
	case GL_UNSIGNED_SHORT:
		SWAP16(lists, n);
		break;
	case GL_INT:
	case GL_UNSIGNED_INT:
	case GL_FLOAT:
		SWAP32(lists, n);
	}
	_glCallLists(n, type, memoffset + (long) lists);
	switch (type) {
	case GL_SHORT:
	case GL_UNSIGNED_SHORT:
		SWAP16(lists, n);
		break;
	case GL_INT:
	case GL_UNSIGNED_INT:
	case GL_FLOAT:
		SWAP32(lists, n);
	}
	POPREGS;
}
void glListBase(GLuint base __asm("d0")) {
	LOG;
	PUSHREGS;
	_glListBase(base);
	POPREGS;
}