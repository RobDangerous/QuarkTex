#include "../gl/gl.h"

void glClearDepth(GLclampd depth __asm("fp0")) {
	LOG;
	PUSHREGS;
	_glClearDepth(depth);
	POPREGS;
}
void glDepthFunc(GLenum func __asm("d0")) {
	LOG;
	PUSHREGS;
	_glDepthFunc(func);
	POPREGS;
}
void glDepthMask(GLboolean flag __asm("d0")) {
	LOG;
	PUSHREGS;
	_glDepthMask(flag);
	POPREGS;
}
void glDepthRange(GLclampd near_val __asm("fp0"), GLclampd far_val __asm("fp1")) {
	LOG;
	PUSHREGS;
	_glDepthRange(near_val, far_val);
	POPREGS;
}