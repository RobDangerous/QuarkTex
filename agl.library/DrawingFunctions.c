#include "../gl/gl.h"

void glBegin(GLenum mode __asm("d0")) {
	LOG;
	_glBegin(mode);
}
void glEnd(void) {
	LOG;
	_glEnd();
}
void glVertex2d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) {
	LOG;
	_glVertex2d(x, y);
}
void glVertex2f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1")) {
	LOG;
	_glVertex2f(x, y);
}
void glVertex2i(GLint x __asm("d0"), GLint y __asm("d1")) {
	LOG;
	_glVertex2i(x, y);
}
void glVertex2s(GLshort x __asm("d0"), GLshort y __asm("d1")) {
	LOG;
	_glVertex2s(x, y);
}
void glVertex3d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {
	LOG;
	_glVertex3d(x, y, z);
}
void glVertex3f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) {
	LOG;
	_glVertex3f(x, y, z);
}
void glVertex3i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2")) {
	LOG;
	_glVertex3i(x, y, z);
}
void glVertex3s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2")) {
	LOG;
	_glVertex3s(x, y, z);
}
void glVertex4d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) {
	LOG;
	_glVertex4d(x, y, z, w);
}
void glVertex4f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2"), GLfloat w __asm("fp3")) {
	LOG;
	_glVertex4f(x, y, z, w);
}
void glVertex4i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2"), GLint w __asm("d3")) {
	LOG;
	_glVertex4i(x, y, z, w);
}
void glVertex4s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2"), GLshort w __asm("d3")) {
	LOG;
	_glVertex4s(x, y, z, w);
}
void glVertex2dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 2);
	_glVertex2dv(memoffset + (long) v);
	SWAP64(v, 2);
}
void glVertex2fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 2);
	_glVertex2fv(memoffset + (long) v);
	SWAP32(v, 2);
}
void glVertex2iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 2);
	_glVertex2iv(memoffset + (long) v);
	SWAP32(v, 2);
}
void glVertex2sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 2);
	_glVertex2sv(memoffset + (long) v);
	SWAP16(v, 2);
}
void glVertex3dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 3);
	_glVertex3dv(memoffset + (long) v);
	SWAP64(v, 3);
}
void glVertex3fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glVertex3fv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glVertex3iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glVertex2iv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glVertex3sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 3);
	_glVertex2sv(memoffset + (long) v);
	SWAP16(v, 3);
}
void glVertex4dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 4);
	_glVertex4dv(memoffset + (long) v);
	SWAP64(v, 4);
}
void glVertex4fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glVertex4fv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glVertex4iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glVertex4iv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glVertex4sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 4);
	_glVertex4sv(memoffset + (long) v);
	SWAP16(v, 4);
}
void glNormal3b(GLbyte nx __asm("d0"), GLbyte ny __asm("d1"), GLbyte nz __asm("d2")) {
	LOG;
	_glNormal3b(nx, ny, nz);
}
void glNormal3d(GLdouble nx __asm("fp0"), GLdouble ny __asm("fp1"), GLdouble nz __asm("fp2")) {
	LOG;
	_glNormal3d(nx, ny, nz);
}
void glNormal3f(GLfloat nx __asm("fp0"), GLfloat ny __asm("fp1"), GLfloat nz __asm("fp2")) {
	LOG;
	_glNormal3f(nx, ny, nz);
}
void glNormal3i(GLint nx __asm("d0"), GLint ny __asm("d1"), GLint nz __asm("d2")) {
	LOG;
	_glNormal3i(nx, ny, nz);
}
void glNormal3s(GLshort nx __asm("d0"), GLshort ny __asm("d1"), GLshort nz __asm("d2")) {
	LOG;
	_glNormal3s(nx, ny, nz);
}
void glNormal3bv(GLbyte *v __asm("a0")) {
	LOG;
	_glNormal3bv(memoffset + (long) v);
}
void glNormal3dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 3);
	_glNormal3dv(memoffset + (long) v);
	SWAP64(v, 3);
}
void glNormal3fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glNormal3fv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glNormal3iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glNormal3iv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glNormal3sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 3);
	_glNormal3sv(memoffset + (long) v);
	SWAP16(v, 3);
}
void glIndexd(GLdouble c __asm("fp0")) {
	LOG;
	_glIndexd(c);
}
void glIndexf(GLfloat c __asm("fp0")) {
	LOG;
	_glIndexf(c);
}
void glIndexi(GLint c __asm("d0")) {
	LOG;
	_glIndexi(c);
}
void glIndexs(GLshort c __asm("d0")) {
	LOG;
	_glIndexs(c);
}
void glIndexub(GLubyte c __asm("d0")) {
	LOG;
	_glIndexub(c);
}
void glIndexdv(GLdouble *c __asm("a0")) {
	LOG;
	SWAP64(c, 1);
	_glIndexdv(memoffset + (long) c);
	SWAP64(c, 1);
}
void glIndexfv(GLfloat *c __asm("a0")) {
	LOG;
	SWAP32(c, 1);
	_glIndexfv(memoffset + (long) c);
	SWAP32(c, 1);
}
void glIndexiv(GLint *c __asm("a0")) {
	LOG;
	SWAP32(c, 1);
	_glIndexiv(memoffset + (long) c);
	SWAP32(c, 1);
}
void glIndexsv(GLshort *c __asm("a0")) {
	LOG;
	SWAP16(c, 1);
	_glIndexsv(memoffset + (long) c);
	SWAP16(c, 1);
}
void glIndexubv(GLubyte *c __asm("a0")) {
	LOG;
	_glIndexubv(memoffset + (long) c);
}
void glColor3b(GLbyte red __asm("d0"), GLbyte green __asm("d1"), GLbyte blue __asm("d2")) {
	LOG;
	_glColor3b(red, green, blue);
}
void glColor3d(GLdouble red __asm("fp0"), GLdouble green __asm("fp1"), GLdouble blue __asm("fp2")) {
	LOG;
	_glColor3d(red, green, blue);
}
void glColor3f(GLfloat red __asm("fp0"), GLfloat green __asm("fp1"), GLfloat blue __asm("fp2")) {
	LOG;
	_glColor3f(red, green, blue);
}
void glColor3i(GLint red __asm("d0"), GLint green __asm("d1"), GLint blue __asm("d2")) {
	LOG;
	_glColor3i(red, green, blue);
}
void glColor3s(GLshort red __asm("d0"), GLshort green __asm("d1"), GLshort blue __asm("d2")) {
	LOG;
	_glColor3s(red, green, blue);
}
void glColor3ub(GLubyte red __asm("d0"), GLubyte green __asm("d1"), GLubyte blue __asm("d2")) { LOG; _glColor3ub(red, green, blue); }
void glColor3ui(GLuint red __asm("d0"), GLuint green __asm("d1"), GLuint blue __asm("d2")) { LOG; _glColor3ui(red, green, blue); }
void glColor3us(GLushort red __asm("d0"), GLushort green __asm("d1"), GLushort blue __asm("d2")) { LOG; _glColor3us(red, green, blue); }
void glColor4b(GLbyte red __asm("d0"), GLbyte green __asm("d1"), GLbyte blue __asm("d2"), GLbyte alpha __asm("d3")) { LOG; _glColor4b(red, green, blue, alpha); }
void glColor4d(GLdouble red __asm("fp0"), GLdouble green __asm("fp1"), GLdouble blue __asm("fp2"), GLdouble alpha __asm("fp3")) { LOG; _glColor4d(red, green, blue, alpha); }
void glColor4f(GLfloat red __asm("fp0"), GLfloat green __asm("fp1"), GLfloat blue __asm("fp2"), GLfloat alpha __asm("fp3")) { LOG; _glColor4f(red, green, blue, alpha); }
void glColor4i(GLint red __asm("d0"), GLint green __asm("d1"), GLint blue __asm("d2"), GLint alpha __asm("d3")) { LOG; _glColor4i(red, green, blue, alpha); }
void glColor4s(GLshort red __asm("d0"), GLshort green __asm("d1"), GLshort blue __asm("d2"), GLshort alpha __asm("d3")) { LOG; _glColor4s(red, green, blue, alpha); }
void glColor4ub(GLubyte red __asm("d0"), GLubyte green __asm("d1"), GLubyte blue __asm("d2"), GLubyte alpha __asm("d3")) { LOG; _glColor4ub(red, green, blue, alpha); }
void glColor4ui(GLuint red __asm("d0"), GLuint green __asm("d1"), GLuint blue __asm("d2"), GLuint alpha __asm("d3")) { LOG; _glColor4ui(red, green, blue, alpha); }
void glColor4us(GLushort red __asm("d0"), GLushort green __asm("d1"), GLushort blue __asm("d2"), GLushort alpha __asm("d3")) { LOG; _glColor4us(red, green, blue, alpha); }
void glColor3bv(GLbyte *v __asm("a0")) { LOG; _glColor3bv(memoffset + (long) v); }
void glColor3dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 3);
	_glColor3dv(memoffset + (long) v);
	SWAP64(v, 3);
}
void glColor3fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glColor3fv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glColor3iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glColor3iv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glColor3sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 3);
	_glColor3sv(memoffset + (long) v);
	SWAP16(v, 3);
}
void glColor3ubv(GLubyte *v __asm("a0")) { LOG; _glColor3ubv(memoffset + (long) v); }
void glColor3uiv(GLuint *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glColor3uiv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glColor3usv(GLushort *v __asm("a0")) {
	LOG;
	SWAP16(v, 3);
	_glColor3usv(memoffset + (long) v);
	SWAP16(v, 3);
}
void glColor4bv(GLbyte *v __asm("a0")) { LOG; _glColor4bv(memoffset + (long) v); }
void glColor4dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 4);
	_glColor4dv(memoffset + (long) v);
	SWAP64(v, 4);
}
void glColor4fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glColor4fv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glColor4iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glColor4iv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glColor4sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 4);
	_glColor4sv(memoffset + (long) v);
	SWAP16(v, 4);
}
void glColor4ubv(GLubyte *v __asm("a0")) { LOG; _glColor4ubv(memoffset + (long) v); }
void glColor4uiv(GLuint *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glColor4uiv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glColor4usv(GLushort *v __asm("a0")) {
	LOG;
	SWAP16(v, 4);
	_glColor4usv(memoffset + (long) v);
	SWAP16(v, 4);
}
void glTexCoord1d(GLdouble s __asm("fp0")) { LOG; _glTexCoord1d(s); }
void glTexCoord1f(GLfloat s __asm("fp0")) { LOG; _glTexCoord1f(s); }
void glTexCoord1i(GLint s __asm("d0")) { LOG; _glTexCoord1i(s); }
void glTexCoord1s(GLshort s __asm("d0")) { LOG; _glTexCoord1s(s); }
void glTexCoord2d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1")) { LOG; _glTexCoord2d(s, t); }
void glTexCoord2f(GLfloat s __asm("fp0"), GLfloat t __asm("fp1")) { LOG; _glTexCoord2f(s, t); }
void glTexCoord2i(GLint s __asm("d0"), GLint t __asm("d1")) { LOG; _glTexCoord2i(s, t); }
void glTexCoord2s(GLshort s __asm("d0"), GLshort t __asm("d1")) { LOG; _glTexCoord2s(s, t); }
void glTexCoord3d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2")) { LOG; _glTexCoord3d(s, t, r); }
void glTexCoord3f(GLfloat s __asm("fp0"), GLfloat t __asm("fp1"), GLfloat r __asm("fp2")) { LOG; _glTexCoord3f(s, t, r); }
void glTexCoord3i(GLint s __asm("d0"), GLint t __asm("d1"), GLint r __asm("d2")) { LOG; _glTexCoord3i(s, t, r); }
void glTexCoord3s(GLshort s __asm("d0"), GLshort t __asm("d1"), GLshort r __asm("d2")) { LOG; _glTexCoord3s(s, t, r); }
void glTexCoord4d(GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2"), GLdouble q __asm("fp3")) { LOG; _glTexCoord4d(s, t, r, q); }
void glTexCoord4f(GLfloat s __asm("fp0"), GLfloat t __asm("fp1"), GLfloat r __asm("fp2"), GLfloat q __asm("fp3")) { LOG; _glTexCoord4f(s, t, r, q); }
void glTexCoord4i(GLint s __asm("d0"), GLint t __asm("d1"), GLint r __asm("d2"), GLint q __asm("d3")) { LOG; _glTexCoord4i(s, t, r, q); }
void glTexCoord4s(GLshort s __asm("d0"), GLshort t __asm("d1"), GLshort r __asm("d2"), GLshort q __asm("d3")) { LOG; _glTexCoord4s(s, t, r, q); }
void glTexCoord1dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 1);
	_glTexCoord1dv(memoffset + (long) v);
	SWAP64(v, 1);
}
void glTexCoord1fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 1);
	_glTexCoord1fv(memoffset + (long) v);
	SWAP32(v, 1);
}
void glTexCoord1iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 1);
	_glTexCoord1iv(memoffset + (long) v);
	SWAP32(v, 1);
}
void glTexCoord1sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 1);
	_glTexCoord1fv(memoffset + (long) v);
	SWAP16(v, 1);
}
void glTexCoord2dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 2);
	_glTexCoord2dv(memoffset + (long) v);
	SWAP64(v, 2);
}
void glTexCoord2fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 2);
	_glTexCoord2fv(memoffset + (long) v);
	SWAP32(v, 2);
}
void glTexCoord2iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 2);
	_glTexCoord2iv(memoffset + (long) v);
	SWAP32(v, 2);
}
void glTexCoord2sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 2);
	_glTexCoord2sv(memoffset + (long) v);
	SWAP16(v, 2);
}
void glTexCoord3dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 3);
	_glTexCoord3dv(memoffset + (long) v);
	SWAP64(v, 3);
}
void glTexCoord3fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glTexCoord3fv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glTexCoord3iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glTexCoord3iv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glTexCoord3sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 3);
	_glTexCoord3sv(memoffset + (long) v);
	SWAP16(v, 3);
}
void glTexCoord4dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 4);
	_glTexCoord4dv(memoffset + (long) v);
	SWAP64(v, 4);
}
void glTexCoord4fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glTexCoord4fv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glTexCoord4iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glTexCoord4iv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glTexCoord4sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 4);
	_glTexCoord4sv(memoffset + (long) v);
	SWAP16(v, 4);
}
void glRasterPos2d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) { LOG; _glRasterPos2d(x, y); }
void glRasterPos2f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1")) { LOG; _glRasterPos2f(x, y); }
void glRasterPos2i(GLint x __asm("d0"), GLint y __asm("d1")) { LOG; _glRasterPos2i(x, y); }
void glRasterPos2s(GLshort x __asm("d0"), GLshort y __asm("d1")) { LOG; _glRasterPos2s(x, y); }
void glRasterPos3d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) { LOG; _glRasterPos3d(x, y, z); }
void glRasterPos3f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) { LOG; _glRasterPos3f(x, y, z); }
void glRasterPos3i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2")) { LOG; _glRasterPos3i(x, y, z); }
void glRasterPos3s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2")) { LOG; _glRasterPos3s(x, y, z); }
void glRasterPos4d(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) { LOG; _glRasterPos4d(x, y, z, w); }
void glRasterPos4f(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2"), GLfloat w __asm("fp3")) { LOG; _glRasterPos4f(x, y, z, w); }
void glRasterPos4i(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2"), GLint w __asm("d3")) { LOG; _glRasterPos4i(x, y, z, w); }
void glRasterPos4s(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2"), GLshort w __asm("d3")) { LOG; _glRasterPos4s(x, y, z, w); }
void glRasterPos2dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 2);
	_glRasterPos2dv(memoffset + (long) v);
	SWAP64(v, 2);
}
void glRasterPos2fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 2);
	_glRasterPos2fv(memoffset + (long) v);
	SWAP32(v, 2);
}
void glRasterPos2iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 2);
	_glRasterPos2iv(memoffset + (long) v);
	SWAP32(v, 2);
}
void glRasterPos2sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 2);
	_glRasterPos2sv(memoffset + (long) v);
	SWAP16(v, 2);
}
void glRasterPos3dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 3);
	_glRasterPos3dv(memoffset + (long) v);
	SWAP64(v, 3);
}
void glRasterPos3fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glRasterPos3fv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glRasterPos3iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 3);
	_glRasterPos3fv(memoffset + (long) v);
	SWAP32(v, 3);
}
void glRasterPos3sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 3);
	_glRasterPos3sv(memoffset + (long) v);
	SWAP16(v, 3);
}
void glRasterPos4dv(GLdouble *v __asm("a0")) {
	LOG;
	SWAP64(v, 4);
	_glRasterPos4dv(memoffset + (long) v);
	SWAP64(v, 4);
}
void glRasterPos4fv(GLfloat *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glRasterPos4fv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glRasterPos4iv(GLint *v __asm("a0")) {
	LOG;
	SWAP32(v, 4);
	_glRasterPos4iv(memoffset + (long) v);
	SWAP32(v, 4);
}
void glRasterPos4sv(GLshort *v __asm("a0")) {
	LOG;
	SWAP16(v, 4);
	_glRasterPos4sv(memoffset + (long) v);
	SWAP16(v, 4);
}
void glRectd(GLdouble x1 __asm("fp0"), GLdouble y1 __asm("fp1"), GLdouble x2 __asm("fp2"), GLdouble y2 __asm("fp3")) { LOG; _glRectd(x1, y1, x2, y2); }
void glRectf(GLfloat x1 __asm("fp0"), GLfloat y1 __asm("fp1"), GLfloat x2 __asm("fp2"), GLfloat y2 __asm("fp3")) { LOG; _glRectf(x1, y1, x2, y2); }
void glRecti(GLint x1 __asm("d0"), GLint y1 __asm("d1"), GLint x2 __asm("d2"), GLint y2 __asm("d3")) { LOG; _glRecti(x1, y1, x2, y2); }
void glRects(GLshort x1 __asm("d0"), GLshort y1 __asm("d1"), GLshort x2 __asm("d2"), GLshort y2 __asm("d3")) { LOG; _glRects(x1, y1, x2, y2); }
void glRectdv(GLdouble *v1 __asm("a0"), GLdouble *v2 __asm("a1")) {
	LOG;
	SWAP64(v1, 2);
	SWAP64(v2, 2);
	_glRectdv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP64(v1, 2);
	SWAP64(v2, 2);
}
void glRectfv(GLfloat *v1 __asm("a0"), GLfloat *v2 __asm("a1")) {
	LOG;
	SWAP32(v1, 2);
	SWAP32(v2, 2);
	_glRectfv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP32(v1, 2);
	SWAP32(v2, 2);
}
void glRectiv(GLint *v1 __asm("a0"), GLint *v2 __asm("a1")) {
	LOG;
	SWAP32(v1, 2);
	SWAP32(v2, 2);
	_glRectiv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP32(v1, 2);
	SWAP32(v2, 2);
}
void glRectsv(GLshort *v1 __asm("a0"), GLshort *v2 __asm("a1")) {
	LOG;
	SWAP16(v1, 2);
	SWAP16(v2, 2);
	_glRectsv(memoffset + (long) v1, memoffset + (long) v2);
	SWAP16(v1, 2);
	SWAP16(v2, 2);
}