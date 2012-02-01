#include "w3d.h"

/************************** Drawing functions ***********************************/

ULONG W3D_DrawLine(__REGA0(W3D_Context *context), __REGA1(W3D_Line *line)) {
	logString("W3D_DrawLine");
	if (context->state & W3D_TEXMAPPING) bindTexture(line->tex);
	glBegin(GL_LINES);
		drawVertex(context, &line->v1, line->tex);
		drawVertex(context, &line->v2, line->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawPoint(__REGA0(W3D_Context *context), __REGA1(W3D_Point *point)) {
	logString("W3D_DrawPoint");
	if (context->state & W3D_TEXMAPPING) bindTexture(point->tex);
	glBegin(GL_POINTS);
		drawVertex(context, &point->v1, point->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriangle(__REGA0(W3D_Context *context), __REGA1(W3D_Triangle *triangle)) {
	logString("W3D_DrawTriangle");
	if (context->state & W3D_TEXMAPPING) bindTexture(triangle->tex);
	glBegin(GL_TRIANGLES);
		drawVertex(context, &triangle->v1, triangle->tex);
		drawVertex(context, &triangle->v2, triangle->tex);
		drawVertex(context, &triangle->v3, triangle->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriFan(__REGA0(W3D_Context *context), __REGA1(W3D_Triangles *triangles)) {
	int i;
	W3D_Vertex *v = triangles->v;
	logString("W3D_DrawTriFan");
	if (context->state & W3D_TEXMAPPING) bindTexture(triangles->tex);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < triangles->vertexcount; ++i) {
		drawVertex(context, v, triangles->tex);
		++v;
	}
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriStrip(__REGA0(W3D_Context *context), __REGA1(W3D_Triangles *triangles)) {
	int i;
	W3D_Vertex *v = triangles->v;
	logString("W3D_DrawTriStrip");
	if (context->state & W3D_TEXMAPPING) bindTexture(triangles->tex);
	glBegin(GL_TRIANGLE_STRIP);
		for (i = 0; i < triangles->vertexcount; ++i, ++v) drawVertex(context, v, triangles->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_Flush(__REGA0(W3D_Context *context)) {
	logString("W3D_Flush");
	glFinish();
	return W3D_SUCCESS;
}
ULONG W3D_DrawLineStrip(__REGA0(W3D_Context *context), __REGA1(W3D_Lines *lines)) {
	int i;
	W3D_Vertex *v = lines->v;
	logString("W3D_DrawLineStrip");
	if (context->state & W3D_TEXMAPPING) bindTexture(lines->tex);
	glBegin(GL_LINE_STRIP);
		for (i = 0; i < lines->vertexcount; ++i, ++v) drawVertex(context, v, lines->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawLineLoop(__REGA0(W3D_Context *context), __REGA1(W3D_Lines *lines)) {
	int i;
	W3D_Vertex *v = lines->v;
	logString("W3D_DrawLineLoop");
	if (context->state & W3D_TEXMAPPING) bindTexture(lines->tex);
	glBegin(GL_LINE_LOOP);
		for (i = 0; i < lines->vertexcount; ++i, ++v) drawVertex(context, v, lines->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_ClearDrawRegion(__REGA0(W3D_Context *context), __REGD0(ULONG color)) {
	logString("W3D_ClearDrawRegion");
	glClearColor(((float) (color << 8 >> 24)) / 256, ((float) (color << 16 >> 24)) / 256, ((float) (color << 24 >> 24)) / 256, ((float) (color >> 24)) / 256);
	glClear(GL_COLOR_BUFFER_BIT);
	return W3D_SUCCESS;
}