#include "../gl/gl.h"

void glGenTextures(GLsizei n __asm("d0"), GLuint *textures __asm("a0")) {
	LOG;
	PUSHREGS;
	_glGenTextures(n, memoffset + (long) textures);
	SWAP32(textures, n);
	POPREGS;
}
void glDeleteTextures(GLsizei n __asm("d0"), GLuint *textures __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(textures, n);
	_glDeleteTextures(n, memoffset + (long) textures);
	SWAP32(textures, n);
	POPREGS;
}
void glBindTexture(GLenum target __asm("d0"), GLuint texture __asm("d1")) {
	LOG;
	PUSHREGS;
	_glBindTexture(target, texture);
	POPREGS;
}
void glPrioritizeTextures(GLsizei n __asm("d0"), GLuint *textures __asm("a0"), GLclampf *priorities __asm("a1")) {
	LOG;
	PUSHREGS;
	SWAP32(textures, n);
	SWAP32(priorities, n);
	_glPrioritizeTextures(n, memoffset + (long) textures, memoffset + (long) priorities);
	SWAP32(textures, n);
	SWAP32(priorities, n);
	POPREGS;
}
void glAreTexturesResident(GLsizei n __asm("d0"), GLuint *textures __asm("a0"), GLboolean *residences __asm("a1")) {
	LOG
	PUSHREGS;
	SWAP32(textures, n);
	_glAreTexturesResident(n, memoffset + (long) textures, memoffset + (long) residences);
	SWAP32(textures, n);
	POPREGS;
}
void glIsTexture(GLuint texture __asm("d0")) { LOG _glIsTexture(texture); }
void glTexSubImage1D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint xoffset __asm("d2"), GLsizei width __asm("d3"), GLenum format __asm("d4"), GLenum type __asm("d5"), GLvoid *pixels __asm("a0")) {
	LOG;
	PUSHREGS;
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
	_glTexSubImage1D(target, level, xoffset, width, format, type, memoffset + (long) pixels);
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
	POPREGS;
}
void glTexSubImage2D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint xoffset __asm("d2"), GLint yoffset __asm("d3"), GLsizei width __asm("d4"), GLsizei height __asm("d5"), GLenum format __asm("d6"), GLenum type __asm("d7"), GLvoid *pixels __asm("a0")) {
	LOG;
	PUSHREGS;
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
	_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, memoffset + (long) pixels);
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
	POPREGS;
}
void glCopyTexImage1D(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum internalformat __asm("d2"), GLint x __asm("d3"), GLint y __asm("d4"), GLsizei width __asm("d5"), GLint border __asm("d6")) {
	LOG;
	PUSHREGS;
	_glCopyTexImage1D(target, level, internalformat, x, y, width, border);
	POPREGS;
}
void glCopyTexImage2D(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum internalformat __asm("d2"), GLint x __asm("d3"), GLint y __asm("d4"), GLsizei width __asm("d5"), GLsizei height __asm("d6"), GLint border __asm("d7")) {
	LOG;
	PUSHREGS;
	_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
	POPREGS;
}
void glCopyTexSubImage1D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint xoffset __asm("d2"), GLint x __asm("d3"), GLint y __asm("d4"), GLsizei width __asm("d5")) {
	LOG;
	PUSHREGS;
	_glCopyTexSubImage1D(target, level, xoffset, x, y, width);
	POPREGS;
}
void glCopyTexSubImage2D(GLenum target __asm("d0"), GLint level __asm("d1"), GLint xoffset __asm("d2"), GLint yoffset __asm("d3"), GLint x __asm("d4"), GLint y __asm("d5"), GLsizei width __asm("d6"), GLsizei height __asm("d7")) {
	LOG;
	PUSHREGS;
	_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
	POPREGS;
}