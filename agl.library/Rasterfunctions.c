#include "../gl/gl.h"	

void glPixelZoom(GLfloat xfactor __asm("fp0"), GLfloat yfactor __asm("fp1")) { LOG; _glPixelZoom(xfactor, yfactor); }
void glPixelStoref(GLenum pname __asm("d0"), GLfloat param __asm("fp0")) { LOG; _glPixelStoref(pname, param); }
void glPixelStorei(GLenum pname __asm("d0"), GLint param __asm("d1")) { LOG; _glPixelStorei(pname, param); }
void glPixelTransferf(GLenum pname __asm("d0"), GLfloat param __asm("fp0")) { LOG; _glPixelTransferf(pname, param); }
void glPixelTransferi(GLenum pname __asm("d0"), GLint param __asm("d1")) { LOG; _glPixelTransferi(pname, param); }
void glPixelMapfv(GLenum map __asm("d0"), GLint mapsize __asm("d1"), GLfloat *values __asm("a0")) {
	LOG;
	SWAP32(values, mapsize);
	_glPixelMapfv(map, mapsize, memoffset + (long) values);
	SWAP32(values, mapsize);
}
void glPixelMapuiv(GLenum map __asm("d0"), GLint mapsize __asm("d1"), GLuint *values __asm("a0")) {
	LOG;
	SWAP32(values, mapsize);
	_glPixelMapuiv(map, mapsize, memoffset + (long) values);
	SWAP32(values, mapsize);
}
void glPixelMapusv(GLenum map __asm("d0"), GLint mapsize __asm("d1"), GLushort *values __asm("a0")) {
	LOG;
	SWAP16(values, mapsize);
	_glPixelMapusv(map, mapsize, memoffset + (long) values);
	SWAP16(values, mapsize);
}
void glGetPixelMapfv(GLenum map __asm("d0"), GLfloat *values __asm("a0")) {
	int mapsize;
	LOG;
	switch (map) {
	case GL_PIXEL_MAP_I_TO_I:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_I_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_S_TO_S:
		_glGetIntegerv(GL_PIXEL_MAP_S_TO_S_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_R:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_R_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_G:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_G_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_B:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_B_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_A:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_A_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_R_TO_R:
		_glGetIntegerv(GL_PIXEL_MAP_R_TO_R_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_G_TO_G:
		_glGetIntegerv(GL_PIXEL_MAP_G_TO_G_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_B_TO_B:
		_glGetIntegerv(GL_PIXEL_MAP_B_TO_B_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_A_TO_A:
		_glGetIntegerv(GL_PIXEL_MAP_A_TO_A_SIZE, memoffset + (long) &mapsize);
		break;
	}
	_glGetPixelMapfv(map, memoffset + (long) values);
	SWAP32(values, mapsize);
}
void glGetPixelMapuiv(GLenum map __asm("d0"), GLuint *values __asm("a0")) {
	int mapsize;
	LOG;
	switch (map) {
	case GL_PIXEL_MAP_I_TO_I:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_I_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_S_TO_S:
		_glGetIntegerv(GL_PIXEL_MAP_S_TO_S_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_R:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_R_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_G:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_G_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_B:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_B_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_A:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_A_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_R_TO_R:
		_glGetIntegerv(GL_PIXEL_MAP_R_TO_R_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_G_TO_G:
		_glGetIntegerv(GL_PIXEL_MAP_G_TO_G_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_B_TO_B:
		_glGetIntegerv(GL_PIXEL_MAP_B_TO_B_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_A_TO_A:
		_glGetIntegerv(GL_PIXEL_MAP_A_TO_A_SIZE, memoffset + (long) &mapsize);
		break;
	}
	_glGetPixelMapuiv(map, memoffset + (long) values);
	SWAP32(values, mapsize);
}
void glGetPixelMapusv(GLenum map __asm("d0"), GLushort *values __asm("a0")) {
	int mapsize;
	LOG;
	switch (map) {
	case GL_PIXEL_MAP_I_TO_I:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_I_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_S_TO_S:
		_glGetIntegerv(GL_PIXEL_MAP_S_TO_S_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_R:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_R_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_G:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_G_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_B:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_B_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_I_TO_A:
		_glGetIntegerv(GL_PIXEL_MAP_I_TO_A_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_R_TO_R:
		_glGetIntegerv(GL_PIXEL_MAP_R_TO_R_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_G_TO_G:
		_glGetIntegerv(GL_PIXEL_MAP_G_TO_G_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_B_TO_B:
		_glGetIntegerv(GL_PIXEL_MAP_B_TO_B_SIZE, memoffset + (long) &mapsize);
		break;
	case GL_PIXEL_MAP_A_TO_A:
		_glGetIntegerv(GL_PIXEL_MAP_A_TO_A_SIZE, memoffset + (long) &mapsize);
		break;
	}
	_glGetPixelMapusv(map, memoffset + (long) values);
	SWAP16(values, mapsize);
}
void glBitmap(GLsizei width __asm("d0"), GLsizei height __asm("d1"), GLfloat xorig __asm("fp0"), GLfloat yorig __asm("fp1"), GLfloat xmove __asm("fp2"), GLfloat ymove __asm("fp3"), GLubyte *bitmap __asm("a0")) { LOG; _glBitmap(width, height, xorig, yorig, xmove, ymove, memoffset + (long) bitmap); }
void glReadPixels(GLint x __asm("d0"), GLint y __asm("d1"), GLsizei width __asm("d2"), GLsizei height __asm("d3"), GLenum format __asm("d4"), GLenum type __asm("d5"), GLvoid *pixels __asm("a0")) {
	LOG;
	_glReadPixels(x, y, width, height, format, type, memoffset + (long) pixels);
	switch (type) {
	case GL_UNSIGNED_SHORT:
	case GL_SHORT:
		SWAP16(pixels, width * height);
		break;
	case GL_UNSIGNED_INT:
	case GL_INT:
	case GL_FLOAT:
		SWAP32(pixels, width * height);
		break;
	}
}
void glDrawPixels(GLsizei width __asm("d0"), GLsizei height __asm("d1"), GLenum format __asm("d2"), GLenum type __asm("d3"), GLvoid *pixels __asm("a0")) {
	LOG;
	switch (type) {
	case GL_UNSIGNED_SHORT:
	case GL_SHORT:
		SWAP16(pixels, width * height);
		break;
	case GL_UNSIGNED_INT:
	case GL_INT:
	case GL_FLOAT:
		SWAP32(pixels, width * height);
		break;
	}
	_glDrawPixels(width, height, format, type, memoffset + (long) pixels);
	switch (type) {
	case GL_UNSIGNED_SHORT:
	case GL_SHORT:
		SWAP16(pixels, width * height);
		break;
	case GL_UNSIGNED_INT:
	case GL_INT:
	case GL_FLOAT:
		SWAP32(pixels, width * height);
		break;
	}
}
void glCopyPixels(GLint x __asm("d0"), GLint y __asm("d1"), GLsizei width __asm("d2"), GLsizei height __asm("d3"), GLenum type __asm("d4")) { LOG; _glCopyPixels(x, y, width, height, type); }