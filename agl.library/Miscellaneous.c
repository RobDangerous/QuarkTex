#include "../gl/gl.h"

void glClearIndex(GLfloat index __asm("fp0")) { LOG; _glClearIndex(index); }
void glClearColor(GLclampf red __asm("fp0"), GLclampf green __asm("fp1"), GLclampf blue __asm("fp2"), GLclampf alpha __asm("fp3")) { LOG; _glClearColor(red, green, blue, alpha); }
void glClear(GLbitfield mask __asm("d0")) { LOG; _glClear(mask); }
void glIndexMask(GLuint mask __asm("d0")) { LOG; _glIndexMask(mask); }
void glColorMask(GLboolean red __asm("d0"), GLboolean green __asm("d1"), GLboolean blue __asm("d2"), GLboolean alpha __asm("d3")) { LOG; _glColorMask(red, green, blue, alpha); }
void glAlphaFunc(GLenum func __asm("d0"), GLclampf ref __asm("fp0")) { LOG; _glAlphaFunc(func, ref); }
void glBlendFunc(GLenum sfactor __asm("d0"), GLenum dfactor __asm("d1")) { LOG; _glBlendFunc(sfactor, dfactor); }
void glLogicOp(GLenum opcode __asm("d0")) { LOG; _glLogicOp(opcode); }
void glCullFace(GLenum mode __asm("d0")) { LOG; _glCullFace(mode); }
void glFrontFace(GLenum mode __asm("d0")) { LOG; _glFrontFace(mode); }
void glPointSize(GLfloat size __asm("fp0")) { LOG; _glPointSize(size); }
void glLineWidth(GLfloat width __asm("fp0")) { LOG; _glLineWidth(width); }
void glLineStipple(GLint factor __asm("d0"), GLushort pattern __asm("d1")) { LOG; _glLineStipple(factor, pattern); }
void glPolygonMode(GLenum face __asm("d0"), GLenum mode __asm("d1")) { LOG; _glPolygonMode(face, mode); }
void glPolygonOffset(GLfloat factor __asm("fp0"), GLfloat units __asm("fp1")) { LOG; _glPolygonOffset(factor, units); }
void glPolygonStipple(GLubyte *mask __asm("a0")) { LOG; _glPolygonStipple(memoffset + (long) mask); }
void glGetPolygonStipple(GLubyte *mask __asm("a0")) { LOG; _glGetPolygonStipple(memoffset + (long) mask); }
void glEdgeFlag(GLboolean flag __asm("d0")) { LOG; _glEdgeFlag(flag); }
void glEdgeFlagv(GLboolean *flag __asm("a0")) { LOG; _glEdgeFlagv(memoffset + (long) flag); }
void glScissor(GLint x __asm("d0"), GLint y __asm("d1"), GLsizei width __asm("d2"), GLsizei height __asm("d3")) { LOG; _glScissor(x, y, width, height); }
void glClipPlane(GLenum plane __asm("d0"), GLdouble *equation __asm("a0")) {
	LOG;
	SWAP64(equation, 4);
	_glClipPlane(plane, memoffset + (long) equation);
	SWAP64(equation, 4);
}
void glGetClipPlane(GLenum plane __asm("d0"), GLdouble *equation __asm("a0")) {
	LOG;
	_glGetClipPlane(plane, memoffset + (long) equation);
	SWAP64(equation, 4);
}
void glDrawBuffer(GLenum mode __asm("d0")) { LOG; _glDrawBuffer(mode); }
void glReadBuffer(GLenum mode __asm("d0")) { LOG; _glReadBuffer(mode); }
void glEnable(GLenum cap __asm("d0")) { LOG; _glEnable(cap); }
void glDisable(GLenum cap __asm("d0")) { LOG; _glDisable(cap); }
GLboolean glIsEnabled(GLenum cap __asm("d0")) { LOG; return _glIsEnabled(cap); }
void glEnableClientState(GLenum cap __asm("d0")) { LOG; _glEnableClientState(cap); }
void glDisableClientState(GLenum cap __asm("d0")) { LOG; _glDisableClientState(cap); }
void glGetBooleanv(GLenum pname __asm("d0"), GLboolean *params __asm("a0")) { LOG; _glGetBooleanv(pname, memoffset + (long) params); }
void glGetDoublev(GLenum pname __asm("d0"), GLdouble *params __asm("a0")) {
	LOG;
	_glGetDoublev(pname, memoffset + (long) params);
	switch (pname) {
	case GL_MODELVIEW_MATRIX:
	case GL_PROJECTION_MATRIX:
	case GL_TEXTURE_MATRIX:
		SWAP64(params, 16);
		break;
	case GL_ACCUM_CLEAR_VALUE:
	case GL_COLOR_CLEAR_VALUE:
	case GL_COLOR_WRITEMASK:
	case GL_CURRENT_COLOR:
	case GL_CURRENT_RASTER_COLOR:
	case GL_CURRENT_RASTER_POSITION:
	case GL_CURRENT_RASTER_TEXTURE_COORDS:
	case GL_CURRENT_TEXTURE_COORDS:
	case GL_FOG_COLOR:
	case GL_LIGHT_MODEL_AMBIENT:
	case GL_MAP2_GRID_DOMAIN:
	case GL_SCISSOR_BOX:
	case GL_TEXTURE_ENV_COLOR:
	case GL_VIEWPORT:
		SWAP64(params, 4);
		break;
	case GL_CURRENT_NORMAL:
		SWAP64(params, 3);
		break;
	case GL_DEPTH_RANGE:
	case GL_LINE_WIDTH_RANGE:
	case GL_MAP1_GRID_DOMAIN:
	case GL_MAP2_GRID_SEGMENTS:
	case GL_MAX_VIEWPORT_DIMS:
	case GL_POINT_SIZE_RANGE:
	case GL_POLYGON_MODE:
		SWAP64(params, 2);
		break;
	default:
		SWAP64(params, 1);
		break;
	}
}
void glGetFloatv(GLenum pname __asm("d0"), GLfloat *params __asm("a0")) {
	LOG;
	_glGetFloatv(pname, memoffset + (long) params);
	switch (pname) {
	case GL_MODELVIEW_MATRIX:
	case GL_PROJECTION_MATRIX:
	case GL_TEXTURE_MATRIX:
		SWAP32(params, 16);
		break;
	case GL_ACCUM_CLEAR_VALUE:
	case GL_COLOR_CLEAR_VALUE:
	case GL_COLOR_WRITEMASK:
	case GL_CURRENT_COLOR:
	case GL_CURRENT_RASTER_COLOR:
	case GL_CURRENT_RASTER_POSITION:
	case GL_CURRENT_RASTER_TEXTURE_COORDS:
	case GL_CURRENT_TEXTURE_COORDS:
	case GL_FOG_COLOR:
	case GL_LIGHT_MODEL_AMBIENT:
	case GL_MAP2_GRID_DOMAIN:
	case GL_SCISSOR_BOX:
	case GL_TEXTURE_ENV_COLOR:
	case GL_VIEWPORT:
		SWAP32(params, 4);
		break;
	case GL_CURRENT_NORMAL:
		SWAP32(params, 3);
		break;
	case GL_DEPTH_RANGE:
	case GL_LINE_WIDTH_RANGE:
	case GL_MAP1_GRID_DOMAIN:
	case GL_MAP2_GRID_SEGMENTS:
	case GL_MAX_VIEWPORT_DIMS:
	case GL_POINT_SIZE_RANGE:
	case GL_POLYGON_MODE:
		SWAP32(params, 2);
		break;
	default:
		SWAP32(params, 1);
		break;
	}
}
void glGetIntegerv(GLenum pname __asm("d0"), GLint *params __asm("a0")) {
	LOG;
	_glGetIntegerv(pname, memoffset + (long) params);
	switch (pname) {
	case GL_MODELVIEW_MATRIX:
	case GL_PROJECTION_MATRIX:
	case GL_TEXTURE_MATRIX:
		SWAP32(params, 16);
		break;
	case GL_ACCUM_CLEAR_VALUE:
	case GL_COLOR_CLEAR_VALUE:
	case GL_COLOR_WRITEMASK:
	case GL_CURRENT_COLOR:
	case GL_CURRENT_RASTER_COLOR:
	case GL_CURRENT_RASTER_POSITION:
	case GL_CURRENT_RASTER_TEXTURE_COORDS:
	case GL_CURRENT_TEXTURE_COORDS:
	case GL_FOG_COLOR:
	case GL_LIGHT_MODEL_AMBIENT:
	case GL_MAP2_GRID_DOMAIN:
	case GL_SCISSOR_BOX:
	case GL_TEXTURE_ENV_COLOR:
	case GL_VIEWPORT:
		SWAP32(params, 4);
		break;
	case GL_CURRENT_NORMAL:
		SWAP32(params, 3);
		break;
	case GL_DEPTH_RANGE:
	case GL_LINE_WIDTH_RANGE:
	case GL_MAP1_GRID_DOMAIN:
	case GL_MAP2_GRID_SEGMENTS:
	case GL_MAX_VIEWPORT_DIMS:
	case GL_POINT_SIZE_RANGE:
	case GL_POLYGON_MODE:
		SWAP32(params, 2);
		break;
	default:
		SWAP32(params, 1);
		break;
	}
}
void glPushAttrib(GLbitfield mask __asm("d0")) { LOG; _glPushAttrib(mask); }
void glPopAttrib(void) { LOG; _glPopAttrib(); }
void glPushClientAttrib( GLbitfield mask __asm("d0")) { LOG; _glPushClientAttrib(mask); }
void glPopClientAttrib(void) { LOG; _glPopClientAttrib(); }
void glRenderMode(GLenum mode __asm("d0")) { LOG; _glRenderMode(mode); }
GLenum glGetError(void) { LOG; return _glGetError(); }
GLubyte * glGetString(GLenum name __asm("d0")) {
	LOG;
	switch (name) {
	case GL_VENDOR:
		return "Robert Konrad";
	case GL_RENDERER:
		return "QuarkTex";
	case GL_VERSION:
		return "1.1.0.5";
	case GL_EXTENSIONS:
		return "";
	}
	return "unknown name";
}
void glFinish(void) { LOG; _glFinish(); }
void glFlush(void) { LOG; _glFlush(); }
void glHint(GLenum target __asm("d0"), GLenum mode __asm("d1")) { LOG; _glHint(target, mode); }