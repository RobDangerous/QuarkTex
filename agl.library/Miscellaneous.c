#include "../gl/gl.h"

void glClearIndex(GLfloat index __asm("fp0")) { LOG; PUSHREGS;; PUSHREGS; _glClearIndex(index); POPREGS; }
void glClearColor(GLclampf red __asm("fp0"), GLclampf green __asm("fp1"), GLclampf blue __asm("fp2"), GLclampf alpha __asm("fp3")) { LOG; PUSHREGS;; PUSHREGS; _glClearColor(red, green, blue, alpha); POPREGS; }
void glClear(GLbitfield mask __asm("d0")) { LOG; PUSHREGS;; PUSHREGS; _glClear(mask); POPREGS; }
void glIndexMask(GLuint mask __asm("d0")) { LOG; PUSHREGS;; PUSHREGS; _glIndexMask(mask); POPREGS; }
void glColorMask(GLboolean red __asm("d0"), GLboolean green __asm("d1"), GLboolean blue __asm("d2"), GLboolean alpha __asm("d3")) { LOG; PUSHREGS;; PUSHREGS; _glColorMask(red, green, blue, alpha); POPREGS; }
void glAlphaFunc(GLenum func __asm("d0"), GLclampf ref __asm("fp0")) { LOG; PUSHREGS;; PUSHREGS; _glAlphaFunc(func, ref); POPREGS; }
void glBlendFunc(GLenum sfactor __asm("d0"), GLenum dfactor __asm("d1")) { LOG; PUSHREGS;; PUSHREGS; _glBlendFunc(sfactor, dfactor); POPREGS; }
void glLogicOp(GLenum opcode __asm("d0")) { LOG; PUSHREGS;; PUSHREGS; _glLogicOp(opcode); POPREGS; }
void glCullFace(GLenum mode __asm("d0")) { LOG; PUSHREGS;; PUSHREGS; _glCullFace(mode); POPREGS; }
void glFrontFace(GLenum mode __asm("d0")) { LOG; PUSHREGS;; PUSHREGS; _glFrontFace(mode); POPREGS; }
void glPointSize(GLfloat size __asm("fp0")) { LOG; PUSHREGS;; PUSHREGS; _glPointSize(size); POPREGS; }
void glLineWidth(GLfloat width __asm("fp0")) { LOG; PUSHREGS;; PUSHREGS; _glLineWidth(width); POPREGS; }
void glLineStipple(GLint factor __asm("d0"), GLushort pattern __asm("d1")) { LOG; PUSHREGS;; PUSHREGS; _glLineStipple(factor, pattern); POPREGS; }
void glPolygonMode(GLenum face __asm("d0"), GLenum mode __asm("d1")) { LOG; PUSHREGS;; PUSHREGS; _glPolygonMode(face, mode); POPREGS; }
void glPolygonOffset(GLfloat factor __asm("fp0"), GLfloat units __asm("fp1")) { LOG; PUSHREGS;; PUSHREGS; _glPolygonOffset(factor, units); POPREGS; }
void glPolygonStipple(GLubyte *mask __asm("a0")) { LOG; PUSHREGS;; PUSHREGS; _glPolygonStipple(memoffset + (long) mask); POPREGS; }
void glGetPolygonStipple(GLubyte *mask __asm("a0")) { LOG; PUSHREGS;; PUSHREGS; _glGetPolygonStipple(memoffset + (long) mask); POPREGS; }
void glEdgeFlag(GLboolean flag __asm("d0")) { LOG; PUSHREGS;; PUSHREGS; _glEdgeFlag(flag); POPREGS; }
void glEdgeFlagv(GLboolean *flag __asm("a0")) { LOG; PUSHREGS;; PUSHREGS; _glEdgeFlagv(memoffset + (long) flag); POPREGS; }
void glScissor(GLint x __asm("d0"), GLint y __asm("d1"), GLsizei width __asm("d2"), GLsizei height __asm("d3")) { LOG; PUSHREGS; _glScissor(x, y, width, height); POPREGS; }
void glClipPlane(GLenum plane __asm("d0"), GLdouble *equation __asm("a0")) {
	LOG; PUSHREGS;
	SWAP64(equation, 4);
	_glClipPlane(plane, memoffset + (long) equation);
	SWAP64(equation, 4);
POPREGS; }
void glGetClipPlane(GLenum plane __asm("d0"), GLdouble *equation __asm("a0")) {
	LOG; PUSHREGS;
	_glGetClipPlane(plane, memoffset + (long) equation);
	SWAP64(equation, 4);
POPREGS; }
void glDrawBuffer(GLenum mode __asm("d0")) { LOG; PUSHREGS; _glDrawBuffer(mode); POPREGS; }
void glReadBuffer(GLenum mode __asm("d0")) { LOG; PUSHREGS; _glReadBuffer(mode); POPREGS; }
void glEnable(GLenum cap __asm("d0")) { LOG; PUSHREGS; _glEnable(cap); POPREGS; }
void glDisable(GLenum cap __asm("d0")) { LOG; PUSHREGS; _glDisable(cap); POPREGS; }
GLboolean glIsEnabled(GLenum cap __asm("d0")) { LOG; PUSHREGS; return _glIsEnabled(cap); POPREGS; }
void glEnableClientState(GLenum cap __asm("d0")) { LOG; PUSHREGS; _glEnableClientState(cap); POPREGS; }
void glDisableClientState(GLenum cap __asm("d0")) { LOG; PUSHREGS; _glDisableClientState(cap); POPREGS; }
void glGetBooleanv(GLenum pname __asm("d0"), GLboolean *params __asm("a0")) { LOG; PUSHREGS; _glGetBooleanv(pname, memoffset + (long) params); POPREGS; }
void glGetDoublev(GLenum pname __asm("d0"), GLdouble *params __asm("a0")) {
	LOG; PUSHREGS;
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
POPREGS; }
void glGetFloatv(GLenum pname __asm("d0"), GLfloat *params __asm("a0")) {
	LOG; PUSHREGS;
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
POPREGS; }
void glGetIntegerv(GLenum pname __asm("d0"), GLint *params __asm("a0")) {
	LOG; PUSHREGS;
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
POPREGS; }
void glPushAttrib(GLbitfield mask __asm("d0")) { LOG; PUSHREGS; _glPushAttrib(mask); POPREGS; }
void glPopAttrib(void) { LOG; PUSHREGS; _glPopAttrib(); POPREGS; }
void glPushClientAttrib( GLbitfield mask __asm("d0")) { LOG; PUSHREGS; _glPushClientAttrib(mask); POPREGS; }
void glPopClientAttrib(void) { LOG; PUSHREGS; _glPopClientAttrib(); POPREGS; }
void glRenderMode(GLenum mode __asm("d0")) { LOG; PUSHREGS; _glRenderMode(mode); POPREGS; }
GLenum glGetError(void) { LOG; PUSHREGS; return _glGetError(); POPREGS; }
GLubyte * glGetString(GLenum name __asm("d0")) {
	LOG; PUSHREGS;
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
POPREGS; }
void glFinish(void) { LOG; PUSHREGS; _glFinish(); POPREGS; }
void glFlush(void) { LOG; PUSHREGS; _glFlush(); POPREGS; }
void glHint(GLenum target __asm("d0"), GLenum mode __asm("d1")) { LOG; PUSHREGS; _glHint(target, mode); POPREGS; }