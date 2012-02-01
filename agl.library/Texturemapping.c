#include "../gl/gl.h"

void glTexGend(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLdouble param __asm("fp0")) { LOG; PUSHREGS; _glTexGend(coord, pname, param); POPREGS; }
void glTexGenf(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glTexGenf(coord, pname, param); POPREGS; }
void glTexGeni(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; PUSHREGS; _glTexGeni(coord, pname, param); POPREGS; }
void glTexGendv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLdouble *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP64(params, 1); }
	else { SWAP64(params, 4); }
	_glTexGendv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP64(params, 1); }
	else { SWAP64(params, 4); }
POPREGS; }
void glTexGenfv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexGenfv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glTexGeniv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexGeniv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glGetTexGendv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLdouble *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexGendv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP64(params, 1); }
	else { SWAP64(params, 4); }
POPREGS; }
void glGetTexGenfv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexGenfv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glGetTexGeniv(GLenum coord __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexGeniv(coord, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_GEN_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glTexEnvf(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glTexEnvf(target, pname, param); POPREGS; }
void glTexEnvi(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; PUSHREGS; _glTexEnvi(target, pname, param); POPREGS; }
void glTexEnvfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexEnvfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glTexEnviv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
	_glTexEnviv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glGetTexEnvfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexEnvfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glGetTexEnviv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexEnviv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_ENV_MODE) { SWAP32(params, 1); }
	else { SWAP32(params, 4); }
POPREGS; }
void glTexParameterf(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glTexParameterf(target, pname, param); POPREGS; }
void glTexParameteri(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; PUSHREGS; _glTexParameteri(target, pname, param); POPREGS; }
void glTexParameterfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	_glTexParameterfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
POPREGS; }
void glTexParameteriv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	_glTexParameteriv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
POPREGS; }
void glGetTexParameterfv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexParameterfv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
POPREGS; }
void glGetTexParameteriv(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexParameteriv(target, pname, memoffset + (long) params);
	if (pname == GL_TEXTURE_BORDER_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
POPREGS; }
void glGetTexLevelParameterfv(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum pname __asm("d2"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexLevelParameterfv(target, level, pname, memoffset + (long) params);
	SWAP32(params, 1);
POPREGS; }
void glGetTexLevelParameteriv(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum pname __asm("d2"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
	_glGetTexLevelParameteriv(target, level, pname, memoffset + (long) params);
	SWAP32(params, 1);
POPREGS; }
void glTexImage1D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint components __asm("d2"), GLsizei width __asm("d3"), GLint border __asm("d4"), GLenum format __asm("d5"), GLenum type __asm("d6"), GLvoid *pixels __asm("a0")) {
	LOG; PUSHREGS;
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
POPREGS; }
void glTexImage2D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint components __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4"), GLint border __asm("d5"), GLenum format __asm("d6"), GLenum type __asm("d7"), GLvoid *pixels __asm("a0")) {
	LOG; PUSHREGS;
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
POPREGS; }
void glGetTexImage(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum format __asm("d2"), GLenum type __asm("d3"), GLvoid *pixels __asm("a0")) {
	LOG; PUSHREGS;
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
POPREGS; }