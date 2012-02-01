#include "w3d.h"

long w3dalpha[] = {0, GL_NEVER, GL_LESS, GL_GEQUAL, GL_LEQUAL, GL_GREATER, GL_NOTEQUAL, GL_EQUAL, GL_ALWAYS};
long w3dblend[] = {0, GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_DST_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA,
	GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_SRC_ALPHA_SATURATE, GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR,
	GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA};
long w3dfog[] = {0, GL_LINEAR, GL_EXP, GL_EXP2, GL_EXP2}; //W3D_FOG_INTERPOLATED
long w3dlogic[] = {0, GL_CLEAR, GL_AND, GL_AND_REVERSE, GL_COPY, GL_AND_INVERTED, GL_NOOP, GL_XOR, GL_OR, GL_NOR, GL_EQUIV, GL_INVERT,
	GL_OR_REVERSE, GL_COPY_INVERTED, GL_OR_INVERTED, GL_NAND, GL_SET};

/************************** Effect functions ************************************/
ULONG W3D_SetAlphaMode(__REGA0(W3D_Context *context), __REGD1(ULONG mode), __REGA1(W3D_Float *refval)) {
	logString("W3D_SetAlphaMode");
	glAlphaFunc(w3dalpha[mode], *refval);
	return W3D_SUCCESS;
}
ULONG W3D_SetBlendMode(__REGA0(W3D_Context *context), __REGD0(ULONG srcfunc), __REGD1(ULONG dstfunc)) {
	logString("W3D_SetBlendMode");
	glBlendFunc(w3dblend[srcfunc], w3dblend[dstfunc]);
	return W3D_SUCCESS;
}
ULONG W3D_SetDrawRegion(__REGA0(W3D_Context *context), __REGA1(struct BitMap *bm), __REGD1(int yoffset), __REGA2(W3D_Scissor *scissor)) {
	logString("W3D_SetDrawRegion");
	swapBuffers();
	return W3D_SUCCESS;
}
ULONG W3D_SetDrawRegionWBM(__REGA0(W3D_Context *context), __REGA1(W3D_Bitmap *bm), __REGA2(W3D_Scissor *scissor)) {
	logString("W3D_SetDrawRegionWBM");
	swapBuffers();
	return W3D_SUCCESS;
}
ULONG W3D_SetFogParams(__REGA0(W3D_Context *context), __REGA1(W3D_Fog *fogparams), __REGD1(ULONG fogmode)) {
	logString("W3D_SetFogParams");
	glFogf(GL_FOG_DENSITY, fogparams->fog_density);
	glFogf(GL_FOG_START, fogparams->fog_start);
	glFogf(GL_FOG_END, fogparams->fog_end);
	aglFogColor(fogparams->fog_color.r, fogparams->fog_color.g, fogparams->fog_color.b);
	glFogi(GL_FOG_MODE, w3dfog[fogmode]);
	return W3D_SUCCESS;
}
ULONG W3D_SetLogicOp(__REGA0(W3D_Context *context), __REGD1(ULONG operation)) {
	logString("W3D_SetLogicOp");
	glLogicOp(w3dlogic[operation]);
	return W3D_SUCCESS;
}
ULONG W3D_SetColorMask(__REGA0(W3D_Context *context), __REGD0(W3D_Bool red), __REGD1(W3D_Bool green), __REGD2(W3D_Bool blue), __REGD3(W3D_Bool alpha)) {
	logString("W3D_SetColorMask");
	glColorMask(red, green, blue, alpha);
	return W3D_SUCCESS;
}
ULONG           W3D_SetPenMask(__REGA0(W3D_Context *context), __REGD1(ULONG pen)) { logString("W3D_SetPenMask"); return W3D_SUCCESS; }
ULONG W3D_SetCurrentColor(__REGA0(W3D_Context *context), __REGA1(W3D_Color *color)) {
	logString("W3D_SetCurrentColor");
	glColor4f(color->r, color->g, color->b, color->a);
	return W3D_SUCCESS;
}
ULONG           W3D_SetCurrentPen(__REGA0(W3D_Context *context), __REGD1(ULONG pen)) { logString("W3D_SetCurrentPen"); return W3D_SUCCESS; }
void W3D_SetScissor(__REGA0(W3D_Context *context), __REGA1(W3D_Scissor *scissor)) {
	logString("W3D_SetScissor");
	glScissor(scissor->left, scissor->top, scissor->width, scissor->height);
}
void W3D_FlushFrame(__REGA0(W3D_Context *context)) {
	logString("W3D_FlushFrame");
	glFinish();
}