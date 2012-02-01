#include "../gl/gl.h"

void glClearAccum(GLfloat red __asm("fp0"), GLfloat green __asm("fp1"), GLfloat blue __asm("fp2"), GLfloat alpha __asm("fp3")) {
	LOG;
	PUSHREGS;
	_glClearAccum(red, green, blue, alpha);
	POPREGS;
}
void glAccum(GLenum op __asm("d0"), GLfloat value __asm("fp0")) {
	LOG;
	PUSHREGS;
	_glAccum(op, value);
	POPREGS;
}