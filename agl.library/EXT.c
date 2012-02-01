#include "../gl/gl.h"

//__REG(GL EXT blend minmax
void glBlendEquationEXT(GLenum mode __asm("d0")) {LOG;;}
//__REG(GL EXT blend color
void glBlendColorEXT(GLclampf red __asm("fp0"), GLclampf green __asm("fp1"), GLclampf blue __asm("fp2"), GLclampf alpha __asm("fp3")) {LOG;;}
//__REG(GL EXT polygon offset
void glPolygonOffsetEXT(GLfloat factor __asm("fp0"), GLfloat bias __asm("fp1")) {LOG;}
//__REG(GL EXT vertex array
void glVertexPointerEXT(GLint size __asm("d0"), GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLsizei count __asm("d3"), void *ptr __asm("a0")) {LOG;}
void glNormalPointerEXT(GLenum type __asm("d0"), GLsizei stride __asm("d1"), GLsizei count __asm("d2"), void *ptr __asm("a0")) {LOG;}
void glColorPointerEXT(GLint size __asm("d0"), GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLsizei count __asm("d3"), void *ptr __asm("a0")) {LOG;}
void glIndexPointerEXT(GLenum type __asm("d0"), GLsizei stride __asm("d1"), GLsizei count __asm("d2"), void *ptr __asm("a0")) {LOG;}
void glTexCoordPointerEXT(GLint size __asm("d0"), GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLsizei count __asm("d3"), void *ptr __asm("a0")) {LOG;}
void glEdgeFlagPointerEXT(GLsizei stride __asm("d0"), GLsizei count __asm("d1"), GLboolean *ptr __asm("a0")) {LOG;}
void glGetPointervEXT(GLenum pname __asm("d0"), void *params __asm("a0")) {LOG;}
void glArrayElementEXT(GLint i __asm("d0")) {LOG;}
void glDrawArraysEXT(GLenum mode __asm("d0"), GLint first __asm("d1"), GLsizei count __asm("d2")) {LOG;}
//__REG(GL EXT texture object
void glGenTexturesEXT(GLsizei n __asm("d0"), GLuint *textures __asm("a0")) {LOG;}
void glDeleteTexturesEXT(GLsizei n __asm("d0"), GLuint *textures __asm("a0")) {LOG;}
void glBindTextureEXT(GLenum target __asm("d0"), GLuint texture __asm("d1")) {LOG;}
void glPrioritizeTexturesEXT(GLsizei n __asm("d0"), GLuint textures __asm("a0"), GLclampf priorities __asm("a1")) {LOG;}
void glAreTexturesResidentEXT(GLsizei n __asm("d0"), GLuint *textures __asm("a0"), GLboolean *residences __asm("a1")) {LOG;}
void glIsTextureEXT(GLuint texture __asm("d0")) {LOG;}
//__REG(GL EXT texture3D
void glTexImage3DEXT(GLenum target __asm("d0"), GLint level __asm("d1"), GLenum internalformat __asm("d2"), GLsizei width __asm("d3"), GLsizei height __asm("d4"), GLsizei depth __asm("d5"), GLint border __asm("d6"), GLenum format __asm("d7"), GLenum type __asm("a0"), GLvoid *pixels __asm("a1")) {LOG;}
void glTexSubImage3DEXT(GLenum target __asm("d0"), GLint level __asm("d1"), GLint xoffset __asm("d2"), GLint yoffset __asm("d3"), GLint zoffset __asm("d4"), GLsizei width __asm("d5"), GLsizei height __asm("d6"), GLsizei depth __asm("d7"), GLenum format __asm("a0"), GLenum type __asm("a1"), GLvoid *pixels __asm("a2")) {LOG;}
void glCopyTexSubImage3DEXT(GLenum target __asm("d0"), GLint level __asm("d1"), GLint xoffset __asm("d2"), GLint yoffset __asm("d3"), GLint zoffset __asm("d4"), GLint x __asm("d5"), GLint y __asm("d6"), GLsizei width __asm("d7"), GLsizei height __asm("a0")) {LOG;}
//__REG(GL EXT color table
void glColorTableEXT(GLenum target __asm("d0"), GLenum internalformat __asm("d1"), GLsizei width __asm("d2"), GLenum format __asm("d3"), GLenum type __asm("d4"), GLvoid *table __asm("a0")) {LOG;}
void glColorSubTableEXT(GLenum target __asm("d0"), GLsizei start __asm("d1"), GLsizei count __asm("d2"), GLenum format __asm("d3"), GLenum type __asm("d4"), GLvoid *data __asm("a0")) {LOG;}
void glGetColorTableEXT(GLenum target __asm("d0"), GLenum format __asm("d1"), GLenum type __asm("d2"), GLvoid *table __asm("a0")) {LOG;}
void glGetColorTableParameterfvEXT(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {LOG;}
void glGetColorTableParameterivEXT(GLenum target __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {LOG;}
//__REG(GL EXT multitexture
void glMultiTexCoord1dEXT(GLenum target __asm("d0"), GLdouble s __asm("fp0")) {LOG;}
void glMultiTexCoord1dvEXT(GLenum target __asm("d0"), GLdouble *v __asm("a0")) {LOG;}
void glMultiTexCoord1fEXT(GLenum target __asm("d0"), GLfloat s __asm("fp0")) {LOG;}
void glMultiTexCoord1fvEXT(GLenum target __asm("d0"), GLfloat *v __asm("a0")) {LOG;}
void glMultiTexCoord1iEXT(GLenum target __asm("d0"), GLint s __asm("d1")) {LOG;}
void glMultiTexCoord1ivEXT(GLenum target __asm("d0"), GLint *v __asm("a0")) {LOG;}
void glMultiTexCoord1sEXT(GLenum target __asm("d0"), GLshort s __asm("d1")) {LOG;}
void glMultiTexCoord1svEXT(GLenum target __asm("d0"), GLshort *v __asm("a0")) {LOG;}
void glMultiTexCoord2dEXT(GLenum target __asm("d0"), GLdouble s __asm("fp0"), GLdouble t __asm("fp1")) {LOG;}
void glMultiTexCoord2dvEXT(GLenum target __asm("d0"), GLdouble *v __asm("a0")) {LOG;}
void glMultiTexCoord2fEXT(GLenum target __asm("d0"), GLfloat s __asm("fp0"), GLfloat t __asm("fp1")) {LOG;}
void glMultiTexCoord2fvEXT(GLenum target __asm("d0"), GLfloat *v __asm("a0")) {LOG;}
void glMultiTexCoord2iEXT(GLenum target __asm("d0"), GLint s __asm("d1"), GLint t __asm("d2")) {LOG;}
void glMultiTexCoord2ivEXT(GLenum target __asm("d0"), GLint *v __asm("a0")) {LOG;}
void glMultiTexCoord2sEXT(GLenum target __asm("d0"), GLshort s __asm("d1"), GLshort t __asm("d2")) {LOG;}
void glMultiTexCoord2svEXT(GLenum target __asm("d0"), GLshort *v __asm("a0")) {LOG;}
void glMultiTexCoord3dEXT(GLenum target __asm("d0"), GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2")) {LOG;}
void glMultiTexCoord3dvEXT(GLenum target __asm("d0"), GLdouble *v __asm("a0")) {LOG;}
void glMultiTexCoord3fEXT(GLenum target __asm("d0"), GLfloat s __asm("fp0"), GLfloat t __asm("fp1"), GLfloat r __asm("fp2")) {LOG;}
void glMultiTexCoord3fvEXT(GLenum target __asm("d0"), GLfloat *v __asm("a0")) {LOG;}
void glMultiTexCoord3iEXT(GLenum target __asm("d0"), GLint s __asm("d1"), GLint t __asm("d2"), GLint r __asm("d3")) {LOG;}
void glMultiTexCoord3ivEXT(GLenum target __asm("d0"), GLint *v __asm("a0")) {LOG;}
void glMultiTexCoord3sEXT(GLenum target __asm("d0"), GLshort s __asm("d1"), GLshort t __asm("d2"), GLshort r __asm("d3")) {LOG;}
void glMultiTexCoord3svEXT(GLenum target __asm("d0"), GLshort *v __asm("a0")) {LOG;}
void glMultiTexCoord4dEXT(GLenum target __asm("d0"), GLdouble s __asm("fp0"), GLdouble t __asm("fp1"), GLdouble r __asm("fp2"), GLdouble q __asm("fp3")) {LOG;}
void glMultiTexCoord4dvEXT(GLenum target __asm("d0"), GLdouble *v __asm("a0")) {LOG;}
void glMultiTexCoord4fEXT(GLenum target __asm("d0"), GLfloat s __asm("fp0"), GLfloat t __asm("fp1"), GLfloat r __asm("fp2"), GLfloat q __asm("fp3")) {LOG;}
void glMultiTexCoord4fvEXT(GLenum target __asm("d0"), GLfloat *v __asm("a0")) {LOG;}
void glMultiTexCoord4iEXT(GLenum target __asm("d0"), GLint s __asm("d1"), GLint t __asm("d2"), GLint r __asm("d3"), GLint q __asm("d4")) {LOG;}
void glMultiTexCoord4ivEXT(GLenum target __asm("d0"), GLint *v __asm("a0")) {LOG;}
void glMultiTexCoord4sEXT(GLenum target __asm("d0"), GLshort s __asm("d1"), GLshort t __asm("d2"), GLshort r __asm("d3"), GLshort q __asm("d4")) {LOG;}
void glMultiTexCoord4svEXT(GLenum target __asm("d0"), GLshort *v __asm("a0")) {LOG;}
void glInterleavedTextureCoordSetsEXT(GLint factor __asm("d0")) {LOG;}
void glSelectTextureEXT(GLenum target __asm("d0")) {LOG;}
void glSelectTextureCoordSetEXT(GLenum target __asm("d0")) {LOG;}
void glSelectTextureTransformEXT(GLenum target __asm("d0")) {LOG;}
//__REG(GL EXT point parameters
void glPointParameterfEXT(GLenum pname __asm("d0"), GLfloat param __asm("fp0")) {LOG;}
void glPointParameterfvEXT(GLenum pname __asm("d0"), GLfloat params __asm("fp0")) {LOG;}