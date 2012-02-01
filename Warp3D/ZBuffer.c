#include "w3d.h"

long w3dz[] = {0, GL_NEVER, GL_LESS, GL_GEQUAL, GL_LEQUAL, GL_GREATER, GL_NOTEQUAL, GL_EQUAL, GL_ALWAYS};

/************************** ZBuffer functions ***********************************/
ULONG W3D_AllocZBuffer(__REGA0(W3D_Context *context)) {
	logString("W3D_AllocZBuffer");
	return W3D_SUCCESS;
}
ULONG W3D_FreeZBuffer(__REGA0(W3D_Context *context)) {
	logString("W3D_FreeZBuffer");
	return W3D_SUCCESS;
}
ULONG           W3D_ClearZBuffer(__REGA0(W3D_Context *context), __REGA1(W3D_Double *clearvalue)) {
	logString("W3D_FreeZBuffer");
	glClear(GL_DEPTH_BUFFER_BIT);
	return W3D_SUCCESS;
}
ULONG           W3D_ReadZPixel(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGA1(W3D_Double *z)) { logString("W3D_ReadZPixel"); return W3D_SUCCESS; }
ULONG           W3D_ReadZSpan(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG n), __REGA1(W3D_Double *z)) { logString("W3D_ReadZSpan"); return W3D_SUCCESS; }
ULONG W3D_SetZCompareMode(__REGA0(W3D_Context *context), __REGD1(ULONG mode)) {
	logString("W3D_SetZCompareMode");
	glDepthFunc(w3dz[mode]);
	return W3D_SUCCESS;
}
void            W3D_WriteZPixel(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGA1(W3D_Double *z)) { logString("W3D_WriteZPixel"); }
void            W3D_WriteZSpan(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG n), __REGA1(W3D_Double *z), __REGA2(UBYTE *mask)) { logString("W3D_WriteZSpan"); }