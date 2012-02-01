#include "../gl/gl.h"

void glMatrixMode(GLenum mode __asm("d0")) { LOG; PUSHREGS; _glMatrixMode(mode); POPREGS; }
void glOrtho(GLdouble left __asm("fp0"), GLdouble right __asm("fp1"),  GLdouble bottom __asm("fp2"), GLdouble top __asm("fp3"), GLdouble near_val __asm("fp4"), GLdouble far_val __asm("fp5")) { LOG; PUSHREGS; _glOrtho(left, right, bottom, top, near_val, far_val); POPREGS; }
void glFrustum(GLdouble left __asm("fp0"), GLdouble right __asm("fp1"), GLdouble bottom __asm("fp2"), GLdouble top __asm("fp3"), GLdouble near_val __asm("fp4"), GLdouble far_val __asm("fp5")) { LOG; PUSHREGS; _glFrustum(left, right, bottom, top, near_val, far_val); POPREGS; }
void glViewport(GLint x __asm("d0"), GLint y __asm("d1"), GLsizei width __asm("d2"), GLsizei height __asm("d3")) { LOG; PUSHREGS; _glViewport(x, y, width, height); POPREGS; }
void glPushMatrix(void) { LOG; PUSHREGS; _glPushMatrix(); POPREGS; }
void glPopMatrix(void) { LOG; PUSHREGS; _glPopMatrix(); POPREGS; }
void glLoadIdentity(void) { LOG; PUSHREGS; _glLoadIdentity(); POPREGS; }
void glLoadMatrixd(GLdouble *m __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(m, 16);
	_glLoadMatrixd(memoffset + (long) m);
	SWAP64(m, 16);
POPREGS; }
void glLoadMatrixf(GLfloat *m __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(m, 16);
	_glLoadMatrixf(memoffset + (long) m);
	SWAP32(m, 16);
POPREGS; }
void glMultMatrixd(GLdouble *m __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(m, 16);
	_glMultMatrixd(memoffset + (long) m);
	SWAP64(m, 16);
POPREGS; }
void glMultMatrixf(GLfloat *m __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(m, 16);
	_glMultMatrixf(memoffset + (long) m);
	SWAP32(m, 16);
POPREGS; }
void glRotated(GLdouble angle __asm("fp0"), GLdouble x __asm("fp1"), GLdouble y __asm("fp2"), GLdouble z __asm("fp3")) { LOG; PUSHREGS; _glRotated(angle, x, y, z); POPREGS; }
void glRotatef(GLfloat angle __asm("fp0"), GLfloat x __asm("fp1"), GLfloat y __asm("fp2"), GLfloat z __asm("fp3")) { LOG; PUSHREGS; _glRotatef(angle, x, y, z); POPREGS; }
void glScaled(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) { LOG; PUSHREGS; _glScaled(x, y, z); POPREGS; }
void glScalef(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) { LOG; PUSHREGS; _glScalef(x, y, z); POPREGS; }
void glTranslated(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) { LOG; PUSHREGS; _glTranslated(x, y, z); POPREGS; }
void glTranslatef(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) { LOG; PUSHREGS; _glTranslatef(x, y, z); POPREGS; }