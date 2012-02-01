#include "w3d.h"

/*************************** V3 Vector functions **********************************/
ULONG W3D_DrawTriangleV(__REGA0(W3D_Context *context), __REGA1(W3D_TriangleV *triangle)) {
	logString("W3D_DrawTriangleV");
	if (context->state & W3D_TEXMAPPING) bindTexture(triangle->tex);
	glBegin(GL_TRIANGLES);
		drawVertex(context, triangle->v1, triangle->tex);
		drawVertex(context, triangle->v2, triangle->tex);
		drawVertex(context, triangle->v3, triangle->tex);
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriFanV(__REGA0(W3D_Context *context), __REGA1(W3D_TrianglesV *triangles)) {
	int i;
	W3D_Vertex **v = triangles->v;
	logString("W3D_DrawTriFanV");
	if (context->state & W3D_TEXMAPPING) bindTexture(triangles->tex);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < triangles->vertexcount; ++i) {
		drawVertex(context, *v, triangles->tex);
		++v;
	}
	glEnd();
	return W3D_SUCCESS;
}
ULONG W3D_DrawTriStripV(__REGA0(W3D_Context *context), __REGA1(W3D_TrianglesV *triangles)) {
	int i;
	W3D_Vertex **v = triangles->v;
	logString("W3D_DrawTriStripV");
	if (context->state & W3D_TEXMAPPING) bindTexture(triangles->tex);
	glBegin(GL_TRIANGLE_STRIP);
	for (i = 0; i < triangles->vertexcount; ++i) {
		drawVertex(context, *v, triangles->tex);
		++v;
	}
	glEnd();
	return W3D_SUCCESS;
}