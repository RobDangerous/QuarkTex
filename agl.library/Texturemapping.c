#include "../gl/gl.h"

void glTexGend(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLdouble param __asm("fp0")) { LOG; _glTexGend(coord, pname, param); }
void glTexGenf(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; _glTexGenf(coord, pname, param); }
void glTexGeni(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; _glTexGeni(coord, pname, param); }
void glTexGendv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLdouble *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP64(params, 1); }
	else { SWAP64(params, 4); }
	_glTexGendv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP64(params, 1); }
	else { SWAP64(params, 4); }
}
void glTexGenfv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexGenfv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glTexGeniv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexGeniv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glGetTexGendv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLdouble *params __asm("a0")) {
	LOG;
	_glGetTexGendv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP64(params, 1); }
	else { SWAP64(params, 4); }
}
void glGetTexGenfv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	_glGetTexGenfv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glGetTexGeniv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	_glGetTexGeniv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glTexEnvf(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; _glTexEnvf(target, pname, param); }
void glTexEnvi(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; _glTexEnvi(target, pname, param); }
void glTexEnvfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexEnvfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glTexEnviv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexEnviv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glGetTexEnvfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	_glGetTexEnvfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glGetTexEnviv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	_glGetTexEnviv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
}
void glTexParameterf(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; _glTexParameterf(target, pname, param); }
void glTexParameteri(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; _glTexParameteri(target, pname, param); }
void glTexParameterfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	_glTexParameterfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
}
void glTexParameteriv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	_glTexParameteriv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
}
void glGetTexParameterfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	_glGetTexParameterfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
}
void glGetTexParameteriv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	_glGetTexParameteriv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
}
void glGetTexLevelParameterfv(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum pname __asm("d2"), GLfloat *params __asm("a0")) {
	LOG;
	_glGetTexLevelParameterfv(target, level, pname, memoffset + (long) params);
	SWAP32(params, 1);
}
void glGetTexLevelParameteriv(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum pname __asm("d2"), GLint *params __asm("a0")) {
	LOG;
	_glGetTexLevelParameteriv(target, level, pname, memoffset + (long) params);
	SWAP32(params, 1);
}
void glTexImage1D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint components __asm("d2"), GLsizei width __asm("d3"), GLint border __asm("d4"), GLenum format __asm("d5"), GLenum type __asm("d6"), GLvoid *pixels __asm("a0")) {
	LOG;
	switch (type) {
	case GL_UNSIGNED_SHORT:
	case GL_SHORT:
		SWAP16(pixels, width);
		break;
	case GL_UNSIGNED_INT:
	case GL_INT:
	case GL_FLOAT:
		SWAP32(pixels, width);
		break;
	}
	_glTexImage1D(target, level, components, width, border, format, type, memoffset + (long) pixels);
	switch (type) {
	case GL_UNSIGNED_SHORT:
	case GL_SHORT:
		SWAP16(pixels, width);
		break;
	case GL_UNSIGNED_INT:
	case GL_INT:
	case GL_FLOAT:
		SWAP32(pixels, width);
		break;
	}
}
void glTexImage2D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint components __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4"), GLint border __asm("d5"), GLenum format __asm("d6"), GLenum type __asm("d7"), GLvoid *pixels __asm("a0")) {
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
	_glTexImage2D(target, level, components, width, height, border, format, type, memoffset + (long) pixels);
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
void glGetTexImage(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum format __asm("d2"), GLenum type __asm("d3"), GLvoid *pixels __asm("a0")) {
	LOG;
	_glGetTexImage(target, level, format, type, memoffset + (long) pixels);
	switch (type) {
	case GL_UNSIGNED_SHORT:
	case GL_SHORT:
		/*SWAP16(pixels, width * height);*/
		break;
	case GL_UNSIGNED_INT:
	case GL_INT:
	case GL_FLOAT:
		/*SWAP32(pixels, width * height);*/
		break;
	}
}