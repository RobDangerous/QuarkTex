#include "w3d.h"

ULONG W3D_DrawLine(__REGA0(W3D_Context *context), __REGA1(W3D_Line *line)) {
	LOG;
	if (context->state & W3D_TEXMAPPING) bindTexture(line->tex);
	_glBegin(GL_LINES);
		drawVertex(context, &line->v1, line->tex);
		drawVertex(context, &line->v2, line->tex);
	_glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawPoint(__REGA0(W3D_Context *context), __REGA1(W3D_Point *point)) {
	LOG;
	if (context->state & W3D_TEXMAPPING) bindTexture(point->tex);
	_glBegin(GL_POINTS);
		drawVertex(context, &point->v1, point->tex);
	_glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriangle(__REGA0(W3D_Context *context), __REGA1(W3D_Triangle *triangle)) {
	LOG;
	if (context->state & W3D_TEXMAPPING) bindTexture(triangle->tex);
	_glBegin(GL_TRIANGLES);
		drawVertex(context, &triangle->v1, triangle->tex);
		drawVertex(context, &triangle->v2, triangle->tex);
		drawVertex(context, &triangle->v3, triangle->tex);
	_glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriFan(__REGA0(W3D_Context *context), __REGA1(W3D_Triangles *triangles)) {
	int i;
	W3D_Vertex *v;
	LOG;
	v = triangles->v;
	if (context->state & W3D_TEXMAPPING) bindTexture(triangles->tex);
	_glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < triangles->vertexcount; ++i) {
		drawVertex(context, v, triangles->tex);
		++v;
	}
	_glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriStrip(__REGA0(W3D_Context *context), __REGA1(W3D_Triangles *triangles)) {
	int i;
	W3D_Vertex *v;
	LOG;
	v = triangles->v;
	if (context->state & W3D_TEXMAPPING) bindTexture(triangles->tex);
	_glBegin(GL_TRIANGLE_STRIP);
		for (i = 0; i < triangles->vertexcount; ++i, ++v) drawVertex(context, v, triangles->tex);
	_glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_Flush(__REGA0(W3D_Context *context)) {
	LOG;
	_glFinish();
	return W3D_SUCCESS;
}
ULONG W3D_DrawLineStrip(__REGA0(W3D_Context *context), __REGA1(W3D_Lines *lines)) {
	int i;
	W3D_Vertex *v;
	LOG;
	v = lines->v;
	if (context->state & W3D_TEXMAPPING) bindTexture(lines->tex);
	_glBegin(GL_LINE_STRIP);
		for (i = 0; i < lines->vertexcount; ++i, ++v) drawVertex(context, v, lines->tex);
	_glEnd();
	return W3D_SUCCESS;
}

ULONG W3D_DrawLineLoop(__REGA0(W3D_Context *context), __REGA1(W3D_Lines *lines)) {
	int i;
	W3D_Vertex *v;
	LOG;
	v = lines->v;
	if (context->state & W3D_TEXMAPPING) bindTexture(lines->tex);
	_glBegin(GL_LINE_LOOP);
		for (i = 0; i < lines->vertexcount; ++i, ++v) drawVertex(context, v, lines->tex);
	_glEnd();
	return W3D_SUCCESS;
}

ULONG W3D_ClearDrawRegion(__REGA0(W3D_Context *context), __REGD0(ULONG color)) {
	LOG;
	if (fullscreen) {
		_glClearColor(((float) (color << 8 >> 24)) / 256, ((float) (color << 16 >> 24)) / 256, ((float) (color << 24 >> 24)) / 256, ((float) (color >> 24)) / 256);
		_glClear(GL_COLOR_BUFFER_BIT);
	}
	else {
		_glColor4f(((float) (color << 8 >> 24)) / 256, ((float) (color << 16 >> 24)) / 256, ((float) (color << 24 >> 24)) / 256, ((float) (color >> 24)) / 256);
		_glRecti(0, 0, width, height);
	}
	return W3D_SUCCESS;
}