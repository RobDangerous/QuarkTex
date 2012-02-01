#include "../gl/gl.h"

void glClearDepth(GLclampd depth __asm("fp0")) {
	LOG;
	_glClearDepth(depth);
}
void glDepthFunc(GLenum func __asm("d0")) {
	LOG;
	_glDepthFunc(func);
}
void glDepthMask(GLboolean flag __asm("d0")) {
	LOG;
	_glDepthMask(flag);
}
void glDepthRange(GLclampd near_val __asm("fp0"), GLclampd far_val __asm("fp1")) {
	LOG;
	_glDepthRange(near_val, far_val);
}