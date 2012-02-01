#include "../gl/gl.h"

//__REG(GL MESA window pos
void glWindowPos2iMESA(GLint x __asm("d0"), GLint y __asm("d1")) {LOG;}
void glWindowPos2sMESA(GLshort x __asm("d0"), GLshort y __asm("d1")) {LOG;}
void glWindowPos2fMESA(GLfloat x __asm("fp0"), GLfloat y __asm("fp1")) {LOG;}
void glWindowPos2dMESA(GLdouble x __asm("fp0"), GLdouble y __asm("fp1")) {LOG;}
void glWindowPos2ivMESA(GLint *p __asm("a0")) {LOG;}
void glWindowPos2svMESA(GLshort *p __asm("a0")) {LOG;}
void glWindowPos2fvMESA(GLfloat *p __asm("a0")) {LOG;}
void glWindowPos2dvMESA(GLdouble *p __asm("a0")) {LOG;}
void glWindowPos3iMESA(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2")) {LOG;}
void glWindowPos3sMESA(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2")) {LOG;}
void glWindowPos3fMESA(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2")) {LOG;}
void glWindowPos3dMESA(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2")) {LOG;}
void glWindowPos3ivMESA(GLint *p __asm("a0")) {LOG;}
void glWindowPos3svMESA(GLshort *p __asm("a0")) {LOG;}
void glWindowPos3fvMESA(GLfloat *p __asm("a0")) {LOG;}
void glWindowPos3dvMESA(GLdouble *p __asm("a0")) {LOG;}
void glWindowPos4iMESA(GLint x __asm("d0"), GLint y __asm("d1"), GLint z __asm("d2"), GLint w __asm("d3")) {LOG;}
void glWindowPos4sMESA(GLshort x __asm("d0"), GLshort y __asm("d1"), GLshort z __asm("d2"), GLshort w __asm("d3")) {LOG;}
void glWindowPos4fMESA(GLfloat x __asm("fp0"), GLfloat y __asm("fp1"), GLfloat z __asm("fp2"), GLfloat w __asm("fp3")) {LOG;}
void glWindowPos4dMESA(GLdouble x __asm("fp0"), GLdouble y __asm("fp1"), GLdouble z __asm("fp2"), GLdouble w __asm("fp3")) {LOG;}
void glWindowPos4ivMESA(GLint *p __asm("a0")) {LOG;}
void glWindowPos4svMESA(GLshort *p __asm("a0")) {LOG;}
void glWindowPos4fvMESA(GLfloat *p __asm("a0")) {LOG;}
void glWindowPos4dvMESA(GLdouble *p __asm("a0")) {LOG;}

//__REG(GL MESA resize buffers
void glResizeBuffersMESA(void) {LOG;}