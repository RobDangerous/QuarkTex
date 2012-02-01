#include "../gl/gl.h"

GLboolean glIsList(GLuint list __asm("d0")) {
	LOG;
	return _glIsList(list);
}
void glDeleteLists(GLuint list __asm("d0"), GLsizei range __asm("d1")) {
	LOG;
	_glDeleteLists(list, range);
}
void glGenLists(GLsizei range __asm("d0")) {
	LOG;
	_glGenLists(range);
}
void glNewList(GLuint list __asm("d0"), GLenum mode __asm("d1")) {
	LOG;
	_glNewList(list, mode);
}
void glEndList(void) {
	LOG;
	_glEndList();
}
void glCallList(GLuint list __asm("d0")) {
	LOG;
	_glCallList(list);
}
void glCallLists(GLsizei n __asm("d0"), GLenum type __asm("d1"), void *lists __asm("a0")) {
	LOG;
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
}
void glListBase(GLuint base __asm("d0")) {
	LOG;
	_glListBase(base);
}