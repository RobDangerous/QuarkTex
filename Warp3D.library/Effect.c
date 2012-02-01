#include "w3d.h"

GLenum w3dalpha[] = {0, GL_NEVER, GL_LESS, GL_GEQUAL, GL_LEQUAL, GL_GREATER, GL_NOTEQUAL, GL_EQUAL, GL_ALWAYS};
GLenum w3dblend[] = {0, GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_DST_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA,
	GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_SRC_ALPHA_SATURATE, GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR,
	GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA};
long w3dfog[] = {0, GL_LINEAR, GL_EXP, GL_EXP2, GL_EXP2}; //W3D_FOG_INTERPOLATED
GLenum w3dlogic[] = {0, GL_CLEAR, GL_AND, GL_AND_REVERSE, GL_COPY, GL_AND_INVERTED, GL_NOOP, GL_XOR, GL_OR, GL_NOR, GL_EQUIV, GL_INVERT,
	GL_OR_REVERSE, GL_COPY_INVERTED, GL_OR_INVERTED, GL_NAND, GL_SET};

ULONG W3D_SetAlphaMode(__REGA0(W3D_Context *context), __REGD1(ULONG mode), __REGA1(W3D_Float *refval)) {
	LOG
	_glAlphaFunc(w3dalpha[mode], *refval);
	return W3D_SUCCESS;
}
ULONG W3D_SetBlendMode(__REGA0(W3D_Context *context), __REGD0(ULONG srcfunc), __REGD1(ULONG dstfunc)) {
	LOG
	_glBlendFunc(w3dblend[srcfunc], w3dblend[dstfunc]);
	return W3D_SUCCESS;
}
ULONG W3D_SetDrawRegion(__REGA0(W3D_Context *context), __REGA1(struct BitMap *bm), __REGD1(int yoffset), __REGA2(W3D_Scissor *scissor)) {
	LOG
	if (fullscreen) swapBuffers();
	return W3D_SUCCESS;
}
ULONG W3D_SetDrawRegionWBM(__REGA0(W3D_Context *context), __REGA1(W3D_Bitmap *bm), __REGA2(W3D_Scissor *scissor)) {
	LOG
	if (fullscreen) swapBuffers();
	return W3D_SUCCESS;
}

GLfloat color[] = { 0.0, 0.0, 0.0, 0.0 };

ULONG W3D_SetFogParams(__REGA0(W3D_Context *context), __REGA1(W3D_Fog *fogparams), __REGD1(ULONG fogmode)) {
	int i;
	LOG
	_glFogf(GL_FOG_DENSITY, fogparams->fog_density);
	_glFogf(GL_FOG_START, fogparams->fog_start);
	_glFogf(GL_FOG_END, fogparams->fog_end);
	color[0] = fogparams->fog_color.r;
	color[1] = fogparams->fog_color.g;
	color[2] = fogparams->fog_color.b;
	SWAP32(color, 4)
	_glFogfv(GL_FOG_COLOR, (GLfloat*) (memoffset + (long) color));
	_glFogi(GL_FOG_MODE, w3dfog[fogmode]);
	return W3D_SUCCESS;
}
ULONG W3D_SetLogicOp(__REGA0(W3D_Context *context), __REGD1(ULONG operation)) {
	LOG
	_glLogicOp(w3dlogic[operation]);
	return W3D_SUCCESS;
}
ULONG W3D_SetColorMask(__REGA0(W3D_Context *context), __REGD0(W3D_Bool red), __REGD1(W3D_Bool green), __REGD2(W3D_Bool blue), __REGD3(W3D_Bool alpha)) {
	LOG
	_glColorMask((GLboolean) red, (GLboolean) green, (GLboolean) blue, (GLboolean) alpha);
	return W3D_SUCCESS;
}
ULONG           W3D_SetPenMask(__REGA0(W3D_Context *context), __REGD1(ULONG pen)) { logString("W3D_SetPenMask"); return W3D_SUCCESS; }
ULONG W3D_SetCurrentColor(__REGA0(W3D_Context *context), __REGA1(W3D_Color *color)) {
	LOG
	_glColor4f(color->r, color->g, color->b, color->a);
	return W3D_SUCCESS;
}
ULONG W3D_SetCurrentPen(__REGA0(W3D_Context *context), __REGD1(ULONG pen)) { logString("W3D_SetCurrentPen"); return W3D_SUCCESS; }
void W3D_SetScissor(__REGA0(W3D_Context *context), __REGA1(W3D_Scissor *scissor)) {
	LOG
	_glScissor(scissor->left, scissor->top, scissor->width, scissor->height);
}
void W3D_FlushFrame(__REGA0(W3D_Context *context)) {
	LOG
	_glFinish();
}