#include "../gl/gl.h"

void glStencilFunc(GLenum func __asm("d0"), GLint ref __asm("d1"), GLuint mask __asm("d2")) { LOG; _glStencilFunc(func, ref, mask); }
void glStencilMask(GLuint mask __asm("d0")) { LOG; _glStencilMask(mask); }
void glStencilOp(GLenum fail __asm("d0"), GLenum zfail __asm("d1"), GLenum zpass __asm("d2")) { LOG; _glStencilOp(fail, zfail, zpass); }
void glClearStencil(GLint s __asm("d0")) { LOG; _glClearStencil(s); }