#include "w3d.h"

int primitives[] = {GL_TRIANGLES, GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, GL_POINTS, GL_LINES, GL_LINE_LOOP, GL_LINE_STRIP};
int envs[] = {0, GL_REPLACE, GL_DECAL, GL_MODULATE, GL_BLEND};

/*************************** V4 Array function ************************************/
ULONG W3D_VertexPointer(__REGA0(W3D_Context* context), __REGA1(void *pointer), __REGD0(int stride), __REGD1(ULONG mode), __REGD2(ULONG flags)) {
	logString("W3D_VertexPointer");
	context->VertexPointer = pointer;
	context->VPStride = stride;
	context->VPMode = mode;
	context->VPFlags = flags;
	return W3D_SUCCESS;
}
ULONG W3D_TexCoordPointer(__REGA0(W3D_Context* context), __REGA1(void *pointer), __REGD0(int stride), __REGD1(int unit), __REGD2(int off_v), __REGD3(int off_w), __REGD4(ULONG flags)) {
	logString("W3D_TexCoordPointer");
	context->TexCoordPointer[0] = pointer;
	context->TPStride[0] = stride;
	context->TPVOffs[0] = off_v;
	context->TPWOffs[0] = off_w;
	context->TPFlags[0] = flags;
	return W3D_SUCCESS;
}
ULONG W3D_ColorPointer(__REGA0(W3D_Context* context), __REGA1(void *pointer), __REGD0(int stride), __REGD1(ULONG format), __REGD2(ULONG mode), __REGD3(ULONG flags)) {
	logString("W3D_ColorPointer");
	context->ColorPointer = (UBYTE*) pointer;
	context->CPStride = stride;
	context->CPMode |= format;
	context->CPMode |= mode;
	context->CPFlags = flags;
	return W3D_SUCCESS;
}
ULONG W3D_BindTexture(__REGA0(W3D_Context* context), __REGD0(ULONG tmu), __REGA1(W3D_Texture *texture)) {
	logString("W3D_BindTexture");
	context->CurrentTex[0] = texture;
	return W3D_SUCCESS;
}

inline void setColor(W3D_Context* context, unsigned int i) {
	W3D_Float* fp = NULL;
	UBYTE* up;
	if (!context->ColorPointer) return;
	if (context->state & W3D_GOURAUD && context->CPMode & W3D_COLOR_FLOAT) {
		fp = (W3D_Float*) (context->ColorPointer + i * context->CPStride);
		if (context->CPMode & W3D_CMODE_RGB) glColor3f(fp[0], fp[1], fp[2]);
		else if (context->CPMode & W3D_CMODE_BGR) glColor3f(fp[2], fp[1], fp[0]);
		else if (context->CPMode & W3D_CMODE_RGBA) glColor4f(fp[0], fp[1], fp[2], fp[3]);
		else if (context->CPMode & W3D_CMODE_ARGB) glColor4f(fp[1], fp[2], fp[3], fp[0]);
		else if (context->CPMode & W3D_CMODE_BGRA) glColor4f(fp[2], fp[1], fp[0], fp[3]);
	}
	else if (context->CPMode & W3D_COLOR_UBYTE) {
		up = (UBYTE*) (context->ColorPointer + i * context->CPStride);
		if (context->CPMode & W3D_CMODE_RGB) glColor3ub(up[0], up[1], up[2]);
		else if (context->CPMode & W3D_CMODE_BGR) glColor3ub(up[2], up[1], up[0]);
		else if (context->CPMode & W3D_CMODE_RGBA) glColor4ub(up[0], up[1], up[2], up[3]);
		else if (context->CPMode & W3D_CMODE_ARGB) glColor4ub(up[1], up[2], up[3], up[0]);
		else if (context->CPMode & W3D_CMODE_BGRA) glColor4ub(up[2], up[1], up[0], up[3]);
	}
}

inline void setTexture(W3D_Context* context, unsigned int i) {
	W3D_Float* fp = NULL;
	W3D_Float u, v, w;
	if (context->state & W3D_TEXMAPPING && context->TexCoordPointer[0]) {
		fp = (W3D_Float*) (context->TexCoordPointer[0] + i * context->TPStride[0]);
		u = fp[0];
		v = ((W3D_Float*) (((UBYTE*) fp) + context->TPVOffs[0]))[0];
		w = ((W3D_Float*) (((UBYTE*) fp) + context->TPWOffs[0]))[0];
		if (context->TPFlags[0] & W3D_TEXCOORD_NORMALIZED) glTexCoord4f(u * w, v * w, 0.0f, w);
		else glTexCoord4f(u * w / context->CurrentTex[0]->texwidth, v * w / context->CurrentTex[0]->texheight, 0.0f, w);
	}
}

inline void drawV(W3D_Context* context, unsigned int i) {
	W3D_Float* fp = NULL;
	W3D_Double* dp = NULL;
	switch (context->VPMode) {
	case W3D_VERTEX_F_F_F:
		fp = (W3D_Float*) (context->VertexPointer + i * context->VPStride);
		glVertex3f(fp[0], fp[1], fp[2]);
		break;
	case W3D_VERTEX_F_F_D:
		fp = (W3D_Float*) (context->VertexPointer + i * context->VPStride);
		dp = (W3D_Double*) (context->VertexPointer + i * context->VPStride);
		glVertex3f(fp[0], fp[1], dp[1]);
		break;
	case W3D_VERTEX_D_D_D:
		dp = (W3D_Double*) (context->VertexPointer + i * context->VPStride);
		glVertex3f(dp[0], dp[1], dp[2]);
		break;
	}
}

ULONG W3D_DrawArray(__REGA0(W3D_Context* context), __REGD0(ULONG primitive), __REGD1(ULONG base), __REGD2(ULONG count)) {
	unsigned int i;
	logString("W3D_DrawArray");
	if (context->state & W3D_TEXMAPPING && context->TexCoordPointer[0]) bindTexture(context->CurrentTex[0]);
	glBegin(primitives[primitive]);
	for (i = base; i < base + count; ++i) {
		setColor(context, i);
		setTexture(context, i);
		drawV(context, i);
	}
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawElements(__REGA0(W3D_Context* context), __REGD0(ULONG primitive), __REGD1(ULONG type), __REGD2(ULONG count), __REGA1(void *indices)) {
	UBYTE* bp = NULL;
	UWORD* wp = NULL;
	ULONG* lp = NULL;
	unsigned int i;
	logString("W3D_DrawElements");
	if (context->state & W3D_TEXMAPPING && context->TexCoordPointer[0]) bindTexture(context->CurrentTex[0]);
	switch (type) {
	case W3D_INDEX_UBYTE:
		bp = (UBYTE*) indices;
		glBegin(primitives[primitive]);
		for (i = 0; i < count; ++i) {
			setColor(context, bp[i]);
			setTexture(context, bp[i]);
			drawV(context, bp[i]);
		}
		glEnd();
		break;
	case W3D_INDEX_UWORD:
		wp = (UWORD*) indices;
		glBegin(primitives[primitive]);
		for (i = 0; i < count; ++i) {
			setColor(context, wp[i]);
			setTexture(context, wp[i]);
			drawV(context, wp[i]);
		}
		glEnd();
		break;
	case W3D_INDEX_ULONG:
		lp = (ULONG*) indices;
		glBegin(primitives[primitive]);
		for (i = 0; i < count; ++i) {
			setColor(context, lp[i]);
			setTexture(context, lp[i]);
			drawV(context, lp[i]);
		}
		glEnd();
		break;
	}
	return W3D_SUCCESS;
}
void            W3D_SetFrontFace(__REGA0(W3D_Context* context), __REGD0(ULONG direction)) { logString("W3D_SetFrontFace"); }