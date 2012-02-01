#include "../gl/gl.h"

void glMatrixMode(GLenum mode __asm("d0")) { LOG; _glMatrixMode(mode); }
void glOrtho(GLdouble left __asm("fp0"), GLdouble right __asm("fp1"),  GLdouble bottom __asm("fp2"), GLdouble top __asm("fp3"), GLdouble near_val __asm("fp4"), GLdouble far_val __asm("fp5")) { LOG; _glOrtho(left, right, bottom, top, near_val, far_val); }
void glFrustum(GLdouble left __asm("fp0"), GLdouble right __asm("fp1"), GLdouble bottom __asm("fp2"), GLdouble top __asm("fp3"), GLdouble near_val __asm("fp4"), GLdouble far_val __asm("fp5")) { LOG; _glFrustum(left, right, bottom, top, near_val, far_val); }
void glViewport(GLint x __asm("d0"), GLint y __asm("d1"), GLsizei width __asm("d2"), GLsizei height __asm("d3")) { LOG; _glViewport(x, y, width, height); }
void glPushMatrix(void) { LOG; _glPushMatrix(); }
void glPopMatrix(void) { LOG; _glPopMatrix(); }
void glLoadIdentity(void) { LOG; _glLoadIdentity(); }
void glLoadMatrixd(GLdouble *m __asm("a0")) {
	LOG;
	SWAP64(m, 16);
	_glLoadMatrixd(memoffset + (long) m);
	SWAP64(m, 16);
}
void glLoadMatrixf(GLfloat *m __asm("a0")) {
	LOG;
	SWAP32(m, 16);
	_glLoadMatrixf(memoffset + (long) m);
	SWAP32(m, 16);
}
void glMultMatrixd(GLdouble *m __asm("a0")) {
	LOG;
	SWAP64(m, 16);
	_glMultMatrixd(memoffset + (long) m);
	SWAP64(m, 16);
}
void glMultMatrixf(GLfloat *m __asm("a0")) {
	LOG;
	SWAP32(m, 16);
	_glMultMatrixf(memoffset + (long) m);
	SWAP32(m, 16);
}
void glRotated(GLdouble angle __asm("fp0"), GLdouble x __asm("fp1"), GLdouble y __asm("fp2"), GLdouble z __asm("fp3")) { LOG; _glRotated(angle, x, y, z); }
void glRotatef(GLfloat angle __asm("fp0"), GLfloat x __asm("fp1"), GLfloat y __asm("fp2"), GLfloat z __asm("fp3")) { LOG; _glRotatef(angle, x, y, z); }
void glScaled(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) { LOG; _glScaled(x, y, z); }
void glScalef(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) { LOG; _glScalef(x, y, z); }
void glTranslated(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) { LOG; _glTranslated(x, y, z); }
void glTranslatef(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) { LOG; _glTranslatef(x, y, z); }