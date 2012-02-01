#include "../gl/gl.h"

void glBegin(GLenum mode __asm("d0")) {
	LOG;
	PUSHREGS;
	_glBegin(mode);
	POPREGS;
}
void glEnd(void) {
	LOG;
	PUSHREGS;
	_glEnd();
	POPREGS;
}
void glVertex2d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) {
	LOG;
	PUSHREGS;
	_glVertex2d(x, y);
	POPREGS;
}
void glVertex2f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1")) {
	LOG;
	PUSHREGS;
	_glVertex2f(x, y);
	POPREGS;
}
void glVertex2i(GLint x __asm("d0"), GLint y __asm("d1")) {
	LOG;
	PUSHREGS;
	_glVertex2i(x, y);
	POPREGS;
}
void glVertex2s(GLshort x __asm("d0"), GLshort y __asm("d1")) {
	LOG;
	PUSHREGS;
	_glVertex2s(x, y);
	POPREGS;
}
void glVertex3d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {
	LOG;
	PUSHREGS;
	_glVertex3d(x, y, z);
	POPREGS;
}
void glVertex3f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) {
	LOG;
	PUSHREGS;
	_glVertex3f(x, y, z);
	POPREGS;
}
void glVertex3i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2")) {
	LOG;
	PUSHREGS;
	_glVertex3i(x, y, z);
	POPREGS;
}
void glVertex3s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2")) {
	LOG;
	PUSHREGS;
	_glVertex3s(x, y, z);
	POPREGS;
}
void glVertex4d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) {
	LOG;
	PUSHREGS;
	_glVertex4d(x, y, z, w);
	POPREGS;
}
void glVertex4f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2"), GLfloat w __asm("fp3")) {
	LOG;
	PUSHREGS;
	_glVertex4f(x, y, z, w);
	POPREGS;
}
void glVertex4i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2"), GLint w __asm("d3")) {
	LOG;
	PUSHREGS;
	_glVertex4i(x, y, z, w);
	POPREGS;
}
void glVertex4s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2"), GLshort w __asm("d3")) {
	LOG;
	PUSHREGS;
	_glVertex4s(x, y, z, w);
	POPREGS;
}
void glVertex2dv(GLdouble *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP64(v, 2);
	_glVertex2dv(memoffset + (long) v);
	SWAP64(v, 2);
	POPREGS;
}
void glVertex2fv(GLfloat *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 2);
	_glVertex2fv(memoffset + (long) v);
	SWAP32(v, 2);
	POPREGS;
}
void glVertex2iv(GLint *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 2);
	_glVertex2iv(memoffset + (long) v);
	SWAP32(v, 2);
	POPREGS;
}
void glVertex2sv(GLshort *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP16(v, 2);
	_glVertex2sv(memoffset + (long) v);
	SWAP16(v, 2);
	POPREGS;
}
void glVertex3dv(GLdouble *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP64(v, 3);
	_glVertex3dv(memoffset + (long) v);
	SWAP64(v, 3);
	POPREGS;
}
void glVertex3fv(GLfloat *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 3);
	_glVertex3fv(memoffset + (long) v);
	SWAP32(v, 3);
	POPREGS;
}
void glVertex3iv(GLint *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 3);
	_glVertex2iv(memoffset + (long) v);
	SWAP32(v, 3);
	POPREGS;
}
void glVertex3sv(GLshort *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP16(v, 3);
	_glVertex2sv(memoffset + (long) v);
	SWAP16(v, 3);
	POPREGS;
}
void glVertex4dv(GLdouble *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP64(v, 4);
	_glVertex4dv(memoffset + (long) v);
	SWAP64(v, 4);
	POPREGS;
}
void glVertex4fv(GLfloat *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 4);
	_glVertex4fv(memoffset + (long) v);
	SWAP32(v, 4);
	POPREGS;
}
void glVertex4iv(GLint *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 4);
	_glVertex4iv(memoffset + (long) v);
	SWAP32(v, 4);
	POPREGS;
}
void glVertex4sv(GLshort *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP16(v, 4);
	_glVertex4sv(memoffset + (long) v);
	SWAP16(v, 4);
	POPREGS;
}
void glNormal3b(GLbyte nx __asm("d0"), GLbyte ny __asm("d1"), GLbyte nz __asm("d2")) {
	LOG;
	PUSHREGS;
	_glNormal3b(nx, ny, nz);
	POPREGS;
}
void glNormal3d(GLdouble nx __asm("fp0"), GLdouble ny __asm("fp1"), GLdouble nz __asm("fp2")) {
	LOG;
	PUSHREGS;
	_glNormal3d(nx, ny, nz);
	POPREGS;
}
void glNormal3f(GLfloat nx __asm("fp0"), GLfloat ny __asm("fp1"), GLfloat nz __asm("fp2")) {
	LOG;
	PUSHREGS;
	_glNormal3f(nx, ny, nz);
	POPREGS;
}
void glNormal3i(GLint nx __asm("d0"), GLint ny __asm("d1"), GLint nz __asm("d2")) {
	LOG;
	PUSHREGS;
	_glNormal3i(nx, ny, nz);
	POPREGS;
}
void glNormal3s(GLshort nx __asm("d0"), GLshort ny __asm("d1"), GLshort nz __asm("d2")) {
	LOG;
	PUSHREGS;
	_glNormal3s(nx, ny, nz);
	POPREGS;
}
void glNormal3bv(GLbyte *v __asm("a0")) {
	LOG;
	PUSHREGS;
	_glNormal3bv(memoffset + (long) v);
	POPREGS;
}
void glNormal3dv(GLdouble *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP64(v, 3);
	_glNormal3dv(memoffset + (long) v);
	SWAP64(v, 3);
	POPREGS;
}
void glNormal3fv(GLfloat *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 3);
	_glNormal3fv(memoffset + (long) v);
	SWAP32(v, 3);
	POPREGS;
}
void glNormal3iv(GLint *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(v, 3);
	_glNormal3iv(memoffset + (long) v);
	SWAP32(v, 3);
	POPREGS;
}
void glNormal3sv(GLshort *v __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP16(v, 3);
	_glNormal3sv(memoffset + (long) v);
	SWAP16(v, 3);
	POPREGS;
}
void glIndexd(GLdouble c __asm("fp0")) {
	LOG;
	PUSHREGS;
	_glIndexd(c);
	POPREGS;
}
void glIndexf(GLfloat c __asm("fp0")) {
	LOG;
	PUSHREGS;
	_glIndexf(c);
	POPREGS;
}
void glIndexi(GLint c __asm("d0")) {
	LOG;
	PUSHREGS;
	_glIndexi(c);
	POPREGS;
}
void glIndexs(GLshort c __asm("d0")) {
	LOG;
	PUSHREGS;
	_glIndexs(c);
	POPREGS;
}
void glIndexub(GLubyte c __asm("d0")) {
	LOG;
	PUSHREGS;
	_glIndexub(c);
	POPREGS;
}
void glIndexdv(GLdouble *c __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP64(c, 1);
	_glIndexdv(memoffset + (long) c);
	SWAP64(c, 1);
	POPREGS;
}
void glIndexfv(GLfloat *c __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(c, 1);
	_glIndexfv(memoffset + (long) c);
	SWAP32(c, 1);
	POPREGS;
}
void glIndexiv(GLint *c __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP32(c, 1);
	_glIndexiv(memoffset + (long) c);
	SWAP32(c, 1);
	POPREGS;
}
void glIndexsv(GLshort *c __asm("a0")) {
	LOG;
	PUSHREGS;
	SWAP16(c, 1);
	_glIndexsv(memoffset + (long) c);
	SWAP16(c, 1);
	POPREGS;
}
void glIndexubv(GLubyte *c __asm("a0")) {
	LOG;
	PUSHREGS;
	_glIndexubv(memoffset + (long) c);
	POPREGS;
}
void glColor3b(GLbyte red __asm("d0"), GLbyte green __asm("d1"), GLbyte blue __asm("d2")) {
	LOG;
	PUSHREGS;
	_glColor3b(red, green, blue);
	POPREGS;
}
void glColor3d(GLdouble red __asm("fp0"), GLdouble green __asm("fp1"), GLdouble blue __asm("fp2")) {
	LOG;
	PUSHREGS;
	_glColor3d(red, green, blue);
	POPREGS;
}
void glColor3f(GLfloat red __asm("fp0"), GLfloat green __asm("fp1"), GLfloat blue __asm("fp2")) {
	LOG;
	PUSHREGS;
	_glColor3f(red, green, blue);
	POPREGS;
}
void glColor3i(GLint red __asm("d0"), GLint green __asm("d1"), GLint blue __asm("d2")) {
	LOG;
	PUSHREGS;
	_glColor3i(red, green, blue);
	POPREGS;
}
void glColor3s(GLshort red __asm("d0"), GLshort green __asm("d1"), GLshort blue __asm("d2")) {
	LOG;
	PUSHREGS;
	_glColor3s(red, green, blue);
	POPREGS;
}
void glColor3ub(GLubyte red __asm("d0"), GLubyte green __asm("d1"), GLubyte blue __asm("d2")) { LOG; PUSHREGS; _glColor3ub(red, green, blue); POPREGS; }
void glColor3ui(GLuint red __asm("d0"), GLuint green __asm("d1"), GLuint blue __asm("d2")) { LOG; PUSHREGS; _glColor3ui(red, green, blue); POPREGS; }
void glColor3us(GLushort red __asm("d0"), GLushort green __asm("d1"), GLushort blue __asm("d2")) { LOG; PUSHREGS; _glColor3us(red, green, blue); POPREGS; }
void glColor4b(GLbyte red __asm("d0"), GLbyte green __asm("d1"), GLbyte blue __asm("d2"), GLbyte alpha __asm("d3")) { LOG; PUSHREGS; _glColor4b(red, green, blue, alpha); POPREGS; }
void glColor4d(GLdouble red __asm("fp0"), GLdouble green __asm("fp1"), GLdouble blue __asm("fp2"), GLdouble alpha __asm("fp3")) { LOG; PUSHREGS; _glColor4d(red, green, blue, alpha); POPREGS; }
void glColor4f(GLfloat red __asm("fp0"), GLfloat green __asm("fp1"), GLfloat blue __asm("fp2"), GLfloat alpha __asm("fp3")) { LOG; PUSHREGS; _glColor4f(red, green, blue, alpha); POPREGS; }
void glColor4i(GLint red __asm("d0"), GLint green __asm("d1"), GLint blue __asm("d2"), GLint alpha __asm("d3")) { LOG; PUSHREGS; _glColor4i(red, green, blue, alpha); POPREGS; }
void glColor4s(GLshort red __asm("d0"), GLshort green __asm("d1"), GLshort blue __asm("d2"), GLshort alpha __asm("d3")) { LOG; PUSHREGS; _glColor4s(red, green, blue, alpha); POPREGS; }
void glColor4ub(GLubyte red __asm("d0"), GLubyte green __asm("d1"), GLubyte blue __asm("d2"), GLubyte alpha __asm("d3")) { LOG; PUSHREGS; _glColor4ub(red, green, blue, alpha); POPREGS; }
void glColor4ui(GLuint red __asm("d0"), GLuint green __asm("d1"), GLuint blue __asm("d2"), GLuint alpha __asm("d3")) { LOG; PUSHREGS; _glColor4ui(red, green, blue, alpha); POPREGS; }
void glColor4us(GLushort red __asm("d0"), GLushort green __asm("d1"), GLushort blue __asm("d2"), GLushort alpha __asm("d3")) { LOG; PUSHREGS; _glColor4us(red, green, blue, alpha); POPREGS; }
void glColor3bv(GLbyte *v __asm("a0")) { LOG; PUSHREGS; _glColor3bv(memoffset + (long) v); POPREGS; }
void glColor3dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 3);
	_glColor3dv(memoffset + (long) v);
	SWAP64(v, 3);
POPREGS; }
void glColor3fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glColor3fv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glColor3iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glColor3iv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glColor3sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 3);
	_glColor3sv(memoffset + (long) v);
	SWAP16(v, 3);
POPREGS; }
void glColor3ubv(GLubyte *v __asm("a0")) { LOG; PUSHREGS; _glColor3ubv(memoffset + (long) v); POPREGS; }
void glColor3uiv(GLuint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glColor3uiv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glColor3usv(GLushort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 3);
	_glColor3usv(memoffset + (long) v);
	SWAP16(v, 3);
POPREGS; }
void glColor4bv(GLbyte *v __asm("a0")) { LOG; PUSHREGS; _glColor4bv(memoffset + (long) v); POPREGS; }
void glColor4dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 4);
	_glColor4dv(memoffset + (long) v);
	SWAP64(v, 4);
POPREGS; }
void glColor4fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glColor4fv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glColor4iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glColor4iv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glColor4sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 4);
	_glColor4sv(memoffset + (long) v);
	SWAP16(v, 4);
POPREGS; }
void glColor4ubv(GLubyte *v __asm("a0")) { LOG; PUSHREGS; _glColor4ubv(memoffset + (long) v); POPREGS; }
void glColor4uiv(GLuint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glColor4uiv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glColor4usv(GLushort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 4);
	_glColor4usv(memoffset + (long) v);
	SWAP16(v, 4);
POPREGS; }
void glTexCoord1d(GLdouble s __asm("fp0")) { LOG; PUSHREGS; _glTexCoord1d(s); POPREGS; }
void glTexCoord1f(GLfloat s __asm("fp0")) { LOG; PUSHREGS; _glTexCoord1f(s); POPREGS; }
void glTexCoord1i(GLint s __asm("d0")) { LOG; PUSHREGS; _glTexCoord1i(s); POPREGS; }
void glTexCoord1s(GLshort s __asm("d0")) { LOG; PUSHREGS; _glTexCoord1s(s); POPREGS; }
void glTexCoord2d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1")) { LOG; PUSHREGS; _glTexCoord2d(s, t); POPREGS; }
void glTexCoord2f(GLfloat s __asm("fp0"), GLfloat t __asm("fp1")) { LOG; PUSHREGS; _glTexCoord2f(s, t); POPREGS; }
void glTexCoord2i(GLint s __asm("d0"), GLint t __asm("d1")) { LOG; PUSHREGS; _glTexCoord2i(s, t); POPREGS; }
void glTexCoord2s(GLshort s __asm("d0"), GLshort t __asm("d1")) { LOG; PUSHREGS; _glTexCoord2s(s, t); POPREGS; }
void glTexCoord3d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2")) { LOG; PUSHREGS; _glTexCoord3d(s, t, r); POPREGS; }
void glTexCoord3f(GLfloat s __asm("fp0"), GLfloat t __asm("fp1"), GLfloat r __asm("fp2")) { LOG; PUSHREGS; _glTexCoord3f(s, t, r); POPREGS; }
void glTexCoord3i(GLint s __asm("d0"), GLint t __asm("d1"), GLint r __asm("d2")) { LOG; PUSHREGS; _glTexCoord3i(s, t, r); POPREGS; }
void glTexCoord3s(GLshort s __asm("d0"), GLshort t __asm("d1"), GLshort r __asm("d2")) { LOG; PUSHREGS; _glTexCoord3s(s, t, r); POPREGS; }
void glTexCoord4d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2"), GLdouble q __asm("fp3")) { LOG; PUSHREGS; _glTexCoord4d(s, t, r, q); POPREGS; }
void glTexCoord4f(GLfloat s __asm("fp0"), GLfloat t __asm("fp1"), GLfloat r __asm("fp2"), GLfloat q __asm("fp3")) { LOG; PUSHREGS; _glTexCoord4f(s, t, r, q); POPREGS; }
void glTexCoord4i(GLint s __asm("d0"), GLint t __asm("d1"), GLint r __asm("d2"), GLint q __asm("d3")) { LOG; PUSHREGS; _glTexCoord4i(s, t, r, q); POPREGS; }
void glTexCoord4s(GLshort s __asm("d0"), GLshort t __asm("d1"), GLshort r __asm("d2"), GLshort q __asm("d3")) { LOG; PUSHREGS; _glTexCoord4s(s, t, r, q); POPREGS; }
void glTexCoord1dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 1);
	_glTexCoord1dv(memoffset + (long) v);
	SWAP64(v, 1);
POPREGS; }
void glTexCoord1fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 1);
	_glTexCoord1fv(memoffset + (long) v);
	SWAP32(v, 1);
POPREGS; }
void glTexCoord1iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 1);
	_glTexCoord1iv(memoffset + (long) v);
	SWAP32(v, 1);
POPREGS; }
void glTexCoord1sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 1);
	_glTexCoord1fv(memoffset + (long) v);
	SWAP16(v, 1);
POPREGS; }
void glTexCoord2dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 2);
	_glTexCoord2dv(memoffset + (long) v);
	SWAP64(v, 2);
POPREGS; }
void glTexCoord2fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 2);
	_glTexCoord2fv(memoffset + (long) v);
	SWAP32(v, 2);
POPREGS; }
void glTexCoord2iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 2);
	_glTexCoord2iv(memoffset + (long) v);
	SWAP32(v, 2);
POPREGS; }
void glTexCoord2sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 2);
	_glTexCoord2sv(memoffset + (long) v);
	SWAP16(v, 2);
POPREGS; }
void glTexCoord3dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 3);
	_glTexCoord3dv(memoffset + (long) v);
	SWAP64(v, 3);
POPREGS; }
void glTexCoord3fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glTexCoord3fv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glTexCoord3iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glTexCoord3iv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glTexCoord3sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 3);
	_glTexCoord3sv(memoffset + (long) v);
	SWAP16(v, 3);
POPREGS; }
void glTexCoord4dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 4);
	_glTexCoord4dv(memoffset + (long) v);
	SWAP64(v, 4);
POPREGS; }
void glTexCoord4fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glTexCoord4fv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glTexCoord4iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glTexCoord4iv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glTexCoord4sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 4);
	_glTexCoord4sv(memoffset + (long) v);
	SWAP16(v, 4);
POPREGS; }
void glRasterPos2d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) { LOG; PUSHREGS; _glRasterPos2d(x, y); POPREGS; }
void glRasterPos2f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1")) { LOG; PUSHREGS; _glRasterPos2f(x, y); POPREGS; }
void glRasterPos2i(GLint x __asm("d0"), GLint y __asm("d1")) { LOG; PUSHREGS; _glRasterPos2i(x, y); POPREGS; }
void glRasterPos2s(GLshort x __asm("d0"), GLshort y __asm("d1")) { LOG; PUSHREGS; _glRasterPos2s(x, y); POPREGS; }
void glRasterPos3d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) { LOG; PUSHREGS; _glRasterPos3d(x, y, z); POPREGS; }
void glRasterPos3f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) { LOG; PUSHREGS; _glRasterPos3f(x, y, z); POPREGS; }
void glRasterPos3i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2")) { LOG; PUSHREGS; _glRasterPos3i(x, y, z); POPREGS; }
void glRasterPos3s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2")) { LOG; PUSHREGS; _glRasterPos3s(x, y, z); POPREGS; }
void glRasterPos4d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) { LOG; PUSHREGS; _glRasterPos4d(x, y, z, w); POPREGS; }
void glRasterPos4f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2"), GLfloat w __asm("fp3")) { LOG; PUSHREGS; _glRasterPos4f(x, y, z, w); POPREGS; }
void glRasterPos4i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2"), GLint w __asm("d3")) { LOG; PUSHREGS; _glRasterPos4i(x, y, z, w); POPREGS; }
void glRasterPos4s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2"), GLshort w __asm("d3")) { LOG; PUSHREGS; _glRasterPos4s(x, y, z, w); POPREGS; }
void glRasterPos2dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 2);
	_glRasterPos2dv(memoffset + (long) v);
	SWAP64(v, 2);
POPREGS; }
void glRasterPos2fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 2);
	_glRasterPos2fv(memoffset + (long) v);
	SWAP32(v, 2);
POPREGS; }
void glRasterPos2iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 2);
	_glRasterPos2iv(memoffset + (long) v);
	SWAP32(v, 2);
POPREGS; }
void glRasterPos2sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 2);
	_glRasterPos2sv(memoffset + (long) v);
	SWAP16(v, 2);
POPREGS; }
void glRasterPos3dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 3);
	_glRasterPos3dv(memoffset + (long) v);
	SWAP64(v, 3);
POPREGS; }
void glRasterPos3fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glRasterPos3fv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glRasterPos3iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 3);
	_glRasterPos3fv(memoffset + (long) v);
	SWAP32(v, 3);
POPREGS; }
void glRasterPos3sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 3);
	_glRasterPos3sv(memoffset + (long) v);
	SWAP16(v, 3);
POPREGS; }
void glRasterPos4dv(GLdouble *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(v, 4);
	_glRasterPos4dv(memoffset + (long) v);
	SWAP64(v, 4);
POPREGS; }
void glRasterPos4fv(GLfloat *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glRasterPos4fv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glRasterPos4iv(GLint *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP32(v, 4);
	_glRasterPos4iv(memoffset + (long) v);
	SWAP32(v, 4);
POPREGS; }
void glRasterPos4sv(GLshort *v __asm("a0")) {
	LOG; PUSHREGS;
	SWAP16(v, 4);
	_glRasterPos4sv(memoffset + (long) v);
	SWAP16(v, 4);
POPREGS; }
void glRectd(GLdouble x1 __asm("fp0"), GLdouble y1 __asm("fp1"), GLdouble x2 __asm("fp2"), GLdouble y2 __asm("fp3")) { LOG; PUSHREGS; _glRectd(x1, y1, x2, y2); POPREGS; }
void glRectf(GLfloat x1 __asm("fp0"), GLfloat y1 __asm("fp1"), GLfloat x2 __asm("fp2"), GLfloat y2 __asm("fp3")) { LOG; PUSHREGS; _glRectf(x1, y1, x2, y2); POPREGS; }
void glRecti(GLint x1 __asm("d0"), GLint y1 __asm("d1"), GLint x2 __asm("d2"), GLint y2 __asm("d3")) { LOG; PUSHREGS; _glRecti(x1, y1, x2, y2); POPREGS; }
void glRects(GLshort x1 __asm("d0"), GLshort y1 __asm("d1"), GLshort x2 __asm("d2"), GLshort y2 __asm("d3")) { LOG; PUSHREGS; _glRects(x1, y1, x2, y2); POPREGS; }
void glRectdv(GLdouble *v1 __asm("a0"), GLdouble *v2 __asm("a1")) {
	LOG; PUSHREGS;
	SWAP64(v1, 2);
	SWAP64(v2, 2);
	_glRectdv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP64(v1, 2);
	SWAP64(v2, 2);
POPREGS; }
void glRectfv(GLfloat *v1 __asm("a0"), GLfloat *v2 __asm("a1")) {
	LOG; PUSHREGS;
	SWAP32(v1, 2);
	SWAP32(v2, 2);
	_glRectfv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP32(v1, 2);
	SWAP32(v2, 2);
POPREGS; }
void glRectiv(GLint *v1 __asm("a0"), GLint *v2 __asm("a1")) {
	LOG; PUSHREGS;
	SWAP32(v1, 2);
	SWAP32(v2, 2);
	_glRectiv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP32(v1, 2);
	SWAP32(v2, 2);
POPREGS; }
void glRectsv(GLshort *v1 __asm("a0"), GLshort *v2 __asm("a1")) {
	LOG; PUSHREGS;
	SWAP16(v1, 2);
	SWAP16(v2, 2);
	_glRectsv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP16(v1, 2);
	SWAP16(v2, 2);
POPREGS; }