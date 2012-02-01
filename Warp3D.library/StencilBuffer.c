#include "w3d.h"

ULONG W3D_AllocStencilBuffer(__REGA0(W3D_Context *context)) {
	LOG
	return W3D_SUCCESS;
}
ULONG W3D_ClearStencilBuffer(__REGA0(W3D_Context *context), __REGA1(ULONG *clearvalue)) {
	LOG
	_glClear(GL_STENCIL_BUFFER_BIT);
	return W3D_SUCCESS;
}
ULONG W3D_FillStencilBuffer(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG width), __REGD3(ULONG height), __REGD4(ULONG depth), __REGA1(void *data)) {
	LOG
	return W3D_SUCCESS;
}
ULONG W3D_FreeStencilBuffer(__REGA0(W3D_Context *context)) { LOG return W3D_SUCCESS; }
ULONG W3D_ReadStencilPixel(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGA1(ULONG *st)) { LOG return W3D_SUCCESS; }
ULONG W3D_ReadStencilSpan(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG n), __REGA1(ULONG *st)) { LOG return W3D_SUCCESS; }

GLenum stencil[] = { 0, GL_NEVER, GL_ALWAYS, GL_LESS, GL_LEQUAL, GL_EQUAL, GL_GEQUAL, GL_GREATER, GL_NOTEQUAL };

ULONG W3D_SetStencilFunc(__REGA0(W3D_Context *context), __REGD0(ULONG func), __REGD1(ULONG refvalue), __REGD2(ULONG mask)) {
	LOG
	_glStencilFunc(stencil[func], (int) refvalue, mask);
	return W3D_SUCCESS;
}

GLenum op[] = {0, GL_KEEP, GL_ZERO, GL_REPLACE, GL_INCR, GL_DECR, GL_INVERT };

ULONG W3D_SetStencilOp(__REGA0(W3D_Context *context), __REGD0(ULONG sfail), __REGD1(ULONG dpfail), __REGD2(ULONG dppass)) {
	LOG
	_glStencilOp(op[sfail], op[dpfail], op[dppass]);
	return W3D_SUCCESS;
}

ULONG W3D_SetWriteMask(__REGA0(W3D_Context *context), __REGD1(ULONG mask)) { LOG return W3D_SUCCESS; }
ULONG W3D_WriteStencilPixel(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG st)) { LOG return W3D_SUCCESS; }
ULONG W3D_WriteStencilSpan(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG n), __REGA1(ULONG *st), __REGA2(UBYTE *mask)) { LOG return W3D_SUCCESS; }