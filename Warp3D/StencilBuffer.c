#include "w3d.h"

/************************** StencilBuffer functions *****************************/
ULONG           W3D_AllocStencilBuffer(__REGA0(W3D_Context *context)) { logString("W3D_AllocStencilBuffer"); return W3D_SUCCESS; }
ULONG           W3D_ClearStencilBuffer(__REGA0(W3D_Context *context), __REGA1(ULONG *clearvalue)) { logString("W3D_ClearStencilBuffer"); return W3D_SUCCESS; }
ULONG           W3D_FillStencilBuffer(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG width), __REGD3(ULONG height), __REGD4(ULONG depth), __REGA1(void *data)) { logString("W3D_FillStencilBuffer"); return W3D_SUCCESS; }
ULONG           W3D_FreeStencilBuffer(__REGA0(W3D_Context *context)) { logString("W3D_FreeStencilBuffer"); return W3D_SUCCESS; }
ULONG           W3D_ReadStencilPixel(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGA1(ULONG *st)) { logString("W3D_ReadStencilPixel"); return W3D_SUCCESS; }
ULONG           W3D_ReadStencilSpan(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG n), __REGA1(ULONG *st)) { logString("W3D_ReadStencilSpan"); return W3D_SUCCESS; }
ULONG           W3D_SetStencilFunc(__REGA0(W3D_Context *context), __REGD0(ULONG func), __REGD1(ULONG refvalue), __REGD2(ULONG mask)) { logString("W3D_SetStencilFunc"); return W3D_SUCCESS; }
ULONG           W3D_SetStencilOp(__REGA0(W3D_Context *context), __REGD0(ULONG sfail), __REGD1(ULONG dpfail), __REGD2(ULONG dppass)) { logString("W3D_SetStencilOp"); return W3D_SUCCESS; }
ULONG           W3D_SetWriteMask(__REGA0(W3D_Context *context), __REGD1(ULONG mask)) { logString("W3D_SetWriteMask"); return W3D_SUCCESS; }
ULONG           W3D_WriteStencilPixel(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG st)) { logString("W3D_WriteStencilPixel"); return W3D_SUCCESS; }
ULONG           W3D_WriteStencilSpan(__REGA0(W3D_Context *context), __REGD0(ULONG x), __REGD1(ULONG y), __REGD2(ULONG n), __REGA1(ULONG *st), __REGA2(UBYTE *mask)) { logString("W3D_WriteStencilSpan"); return W3D_SUCCESS; }