#include "../gl/gl.h"

void glMap1d(GLenum target __asm("d0"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1"), GLint stride __asm("d1"), GLint order __asm("d2"), GLdouble *points __asm("a0")) {
	LOG;
	switch (target) {
	case GL_MAP1_INDEX:
	case GL_MAP1_TEXTURE_COORD_1:
		SWAP64(points, order + stride * order);
	case GL_MAP1_TEXTURE_COORD_2:
		SWAP64(points, order * 2 + stride * order);
	case GL_MAP1_VERTEX_3:
	case GL_MAP1_NORMAL:
	case GL_MAP1_TEXTURE_COORD_3:
		SWAP64(points, order * 3 + stride * order);
	case GL_MAP1_VERTEX_4:
	case GL_MAP1_COLOR_4:
	case GL_MAP1_TEXTURE_COORD_4:
		SWAP64(points, order * 4 + stride * order);
	}
	_glMap1d(target, u1, u2, stride, order, memoffset + (unsigned) points);
	switch (target) {
	case GL_MAP1_INDEX:
	case GL_MAP1_TEXTURE_COORD_1:
		SWAP64(points, order + stride * order);
	case GL_MAP1_TEXTURE_COORD_2:
		SWAP64(points, order * 2 + stride * order);
	case GL_MAP1_VERTEX_3:
	case GL_MAP1_NORMAL:
	case GL_MAP1_TEXTURE_COORD_3:
		SWAP64(points, order * 3 + stride * order);
	case GL_MAP1_VERTEX_4:
	case GL_MAP1_COLOR_4:
	case GL_MAP1_TEXTURE_COORD_4:
		SWAP64(points, order * 4 + stride * order);
	}
}
void glMap1f(GLenum target __asm("d0"), GLfloat u1 __asm("fp0"), GLfloat u2 __asm("fp1"), GLint stride __asm("d1"), GLint order __asm("d2"), GLfloat *points __asm("a0")) {
	LOG;
	switch (target) {
	case GL_MAP1_INDEX:
	case GL_MAP1_TEXTURE_COORD_1:
		SWAP32(points, order + stride * order);
	case GL_MAP1_TEXTURE_COORD_2:
		SWAP32(points, order * 2 + stride * order);
	case GL_MAP1_VERTEX_3:
	case GL_MAP1_NORMAL:
	case GL_MAP1_TEXTURE_COORD_3:
		SWAP32(points, order * 3 + stride * order);
	case GL_MAP1_VERTEX_4:
	case GL_MAP1_COLOR_4:
	case GL_MAP1_TEXTURE_COORD_4:
		SWAP32(points, order * 4 + stride * order);
	}
	_glMap1f(target, u1, u2, stride, order, memoffset + (unsigned) points);
	switch (target) {
	case GL_MAP1_INDEX:
	case GL_MAP1_TEXTURE_COORD_1:
		SWAP32(points, order + stride * order);
	case GL_MAP1_TEXTURE_COORD_2:
		SWAP32(points, order * 2 + stride * order);
	case GL_MAP1_VERTEX_3:
	case GL_MAP1_NORMAL:
	case GL_MAP1_TEXTURE_COORD_3:
		SWAP32(points, order * 3 + stride * order);
	case GL_MAP1_VERTEX_4:
	case GL_MAP1_COLOR_4:
	case GL_MAP1_TEXTURE_COORD_4:
		SWAP32(points, order * 4 + stride * order);
	}
}
void glMap2d(GLenum target __asm("d0"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1"), GLint ustride __asm("d1"), GLint uorder __asm("d2"), GLdouble v1 __asm("fp2"), GLdouble v2 __asm("fp3"), GLint vstride __asm("d3"), GLint vorder __asm("d4"), GLdouble *points __asm("a0")) {
	LOG;
	switch (target) {
	case GL_MAP2_INDEX:
	case GL_MAP2_TEXTURE_COORD_1:
		SWAP64(points, (uorder + vorder) + ustride * uorder + vstride * vorder);
	case GL_MAP2_TEXTURE_COORD_2:
		SWAP64(points, (uorder + vorder) * 2 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_3:
	case GL_MAP2_NORMAL:
	case GL_MAP2_TEXTURE_COORD_3:
		SWAP64(points, (uorder + vorder) * 3 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_4:
	case GL_MAP2_COLOR_4:
	case GL_MAP2_TEXTURE_COORD_4:
		SWAP64(points, (uorder + vorder) * 4 + ustride * uorder + vstride * vorder);
	}
	_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, memoffset + (unsigned) points);
	switch (target) {
	case GL_MAP2_INDEX:
	case GL_MAP2_TEXTURE_COORD_1:
		SWAP64(points, (uorder + vorder) + ustride * uorder + vstride * vorder);
	case GL_MAP2_TEXTURE_COORD_2:
		SWAP64(points, (uorder + vorder) * 2 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_3:
	case GL_MAP2_NORMAL:
	case GL_MAP2_TEXTURE_COORD_3:
		SWAP64(points, (uorder + vorder) * 3 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_4:
	case GL_MAP2_COLOR_4:
	case GL_MAP2_TEXTURE_COORD_4:
		SWAP64(points, (uorder + vorder) * 4 + ustride * uorder + vstride * vorder);
	}
}
void glMap2f(GLenum target __asm("d0"), GLfloat u1 __asm("fp0"), GLfloat u2 __asm("fp1"), GLint ustride __asm("d1"), GLint uorder __asm("d2"), GLfloat v1 __asm("fp2"), GLfloat v2 __asm("fp3"), GLint vstride __asm("d3"), GLint vorder __asm("d4"), GLfloat *points __asm("a0")) {
	LOG;
	switch (target) {
	case GL_MAP2_INDEX:
	case GL_MAP2_TEXTURE_COORD_1:
		SWAP32(points, (uorder + vorder) + ustride * uorder + vstride * vorder);
	case GL_MAP2_TEXTURE_COORD_2:
		SWAP32(points, (uorder + vorder) * 2 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_3:
	case GL_MAP2_NORMAL:
	case GL_MAP2_TEXTURE_COORD_3:
		SWAP32(points, (uorder + vorder) * 3 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_4:
	case GL_MAP2_COLOR_4:
	case GL_MAP2_TEXTURE_COORD_4:
		SWAP32(points, (uorder + vorder) * 4 + ustride * uorder + vstride * vorder);
	}
	_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, memoffset + (unsigned) points);
	switch (target) {
	case GL_MAP2_INDEX:
	case GL_MAP2_TEXTURE_COORD_1:
		SWAP32(points, (uorder + vorder) + ustride * uorder + vstride * vorder);
	case GL_MAP2_TEXTURE_COORD_2:
		SWAP32(points, (uorder + vorder) * 2 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_3:
	case GL_MAP2_NORMAL:
	case GL_MAP2_TEXTURE_COORD_3:
		SWAP32(points, (uorder + vorder) * 3 + ustride * uorder + vstride * vorder);
	case GL_MAP2_VERTEX_4:
	case GL_MAP2_COLOR_4:
	case GL_MAP2_TEXTURE_COORD_4:
		SWAP32(points, (uorder + vorder) * 4 + ustride * uorder + vstride * vorder);
	}
}
void glGetMapdv(GLenum target __asm("d0"), GLenum query __asm("d1"), GLdouble *v __asm("a0")) {
	LOG;
	//_glGetMapdv(target, query, v);
}
void glGetMapfv(GLenum target __asm("d0"), GLenum query __asm("d1"), GLfloat *v __asm("a0")) {
	LOG;
	//_glGetMapfv(target, query, v);
}
void glGetMapiv(GLenum target __asm("d0"), GLenum query __asm("d1"), GLint *v __asm("a0")) {
	LOG;
	//_glGetMapiv(target, query, v);
}
void glEvalCoord1d(GLdouble u __asm("fp0")) { LOG; _glEvalCoord1d(u); }
void glEvalCoord1f(GLfloat u __asm("fp0")) { LOG; _glEvalCoord1f(u); }
void glEvalCoord1dv(GLdouble *u __asm("a0")) {
	LOG;
	SWAP64(u, 1);
	_glEvalCoord1dv(memoffset + (unsigned) u);
	SWAP64(u, 1);
}
void glEvalCoord1fv(GLfloat *u __asm("a0")) {
	LOG;
	SWAP32(u, 1);
	_glEvalCoord1fv(memoffset + (unsigned) u);
	SWAP32(u, 1);
}
void glEvalCoord2d(GLdouble u __asm("fp0"), GLdouble v __asm("fp1")) { LOG; _glEvalCoord2d(u, v); }
void glEvalCoord2f(GLfloat u __asm("fp0"), GLfloat v __asm("fp1")) { LOG; _glEvalCoord2f(u, v); }
void glEvalCoord2dv(GLdouble *u __asm("a0")) {
	LOG;
	SWAP64(u, 2);
	_glEvalCoord2dv(memoffset + (unsigned) u);
	SWAP64(u, 2);
}
void glEvalCoord2fv(GLfloat *u __asm("a0")) {
	LOG;
	SWAP32(u, 2);
	_glEvalCoord2fv(memoffset + (unsigned) u);
	SWAP32(u, 2);
}
void glMapGrid1d(GLint un __asm("d0"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1")) { LOG; _glMapGrid1d(un, u1, u2); }
void glMapGrid1f(GLint un __asm("d0"), GLfloat u1 __asm("fp0"), GLfloat u2 __asm("fp1")) { LOG; _glMapGrid1f(un, u1, u2); }
void glMapGrid2d(GLint un __asm("d0"), GLdouble u1 __asm("fp0"), GLdouble u2 __asm("fp1"), GLint vn __asm("d1"), GLdouble v1 __asm("fp2"), GLdouble v2 __asm("fp3")) { LOG; _glMapGrid2d(un, u1, u2, vn, v1, v2); }
void glMapGrid2f(GLint un __asm("d0"), GLfloat u1 __asm("fp0"), GLfloat u2 __asm("fp1"), GLint vn __asm("d1"), GLfloat v1 __asm("fp2"), GLfloat v2 __asm("fp3")) { LOG; _glMapGrid2f(un, u1, u2, vn, v1, v2); }
void glEvalPoint1(GLint i __asm("d0")) { LOG; _glEvalPoint1(i); }
void glEvalPoint2(GLint i __asm("d0"), GLint j __asm("d1")) { LOG; _glEvalPoint2(i, j); }
void glEvalMesh1(GLenum mode __asm("d0"), GLint i1 __asm("d1"), GLint i2 __asm("d2")) { LOG; _glEvalMesh1(mode, i1, i2); }
void glEvalMesh2(GLenum mode __asm("d0"), GLint i1 __asm("d1"), GLint i2 __asm("d2"), GLint j1 __asm("d3"), GLint j2 __asm("d4")) { LOG; _glEvalMesh2(mode, i1, i2, j1, j2); }