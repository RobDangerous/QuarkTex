#include "../gl/gl.h"

void glStencilFunc(GLenum func __asm("d0"), GLint ref __asm("d1"), GLuint mask __asm("d2")) { LOG; PUSHREGS; _glStencilFunc(func, ref, mask); POPREGS;}
void glStencilMask(GLuint mask __asm("d0")) { LOG; PUSHREGS; _glStencilMask(mask); POPREGS;}
void glStencilOp(GLenum fail __asm("d0"), GLenum zfail __asm("d1"), GLenum zpass __asm("d2")) { LOG; PUSHREGS; _glStencilOp(fail, zfail, zpass); POPREGS;}
void glClearStencil(GLint s __asm("d0")) { LOG; PUSHREGS; _glClearStencil(s); POPREGS;}