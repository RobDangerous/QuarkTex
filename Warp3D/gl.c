#include "gl.h"

long gl;
long _glTexCoord2f, _glBindTexture, _glBegin, _glEnd, _glFinish, _glClearColor, _glClear, _glVertex2f, _glVertex3f, _glTexCoord4f, _glVertex4f, _glColor3f, _glTexEnvi,
		_glColor4f, _glEnable, _glDisable, _glAlphaFunc, _glBlendFunc, _glPixelStorei, _glDepthFunc, _glColorMask, _glScissor, _glLogicOp, _glFogi, _glFogf,
		_glColor3ub, _glColor4ub, _glDepthMask, _glGetError, _glDeleteTextures, _glShadeModel;
long w3d;
long _swapBuffers, _loadTexture, _logString, _logInt, _logFloat, _aglFogColor, _aglTexEnvfv, _deleteTexture;//, _vertex3f;

void glInit(void) {
	w3d = DLLopen("alib\\Warp3D.alib");
	
	_swapBuffers = DLLfunc(w3d, "swapBuffers");
	_loadTexture = DLLfunc(w3d, "loadTexture");
	_logString = DLLfunc(w3d, "logString");
	_logInt = DLLfunc(w3d, "logInt");
	_logFloat = DLLfunc(w3d, "logFloat");
	_aglFogColor = DLLfunc(w3d, "aglFogColor");
	_aglTexEnvfv = DLLfunc(w3d, "aglTexEnvfv");
	_deleteTexture = DLLfunc(w3d, "deleteTexture");
	
	gl = DLLopen("opengl32.dll");

	_glBegin = DLLfunc(gl, "glBegin");
	_glEnd = DLLfunc(gl, "glEnd");
	_glFinish = DLLfunc(gl, "glFinish");
	_glClearColor = DLLfunc(gl, "glClearColor");
	_glClear = DLLfunc(gl, "glClear");
	_glColor4f = DLLfunc(gl, "glColor4f");
	_glBindTexture = DLLfunc(gl, "glBindTexture");
	_glTexCoord2f = DLLfunc(gl, "glTexCoord2f");
	_glEnable = DLLfunc(gl, "glEnable");
	_glDisable = DLLfunc(gl, "glDisable");
	_glAlphaFunc = DLLfunc(gl, "glAlphaFunc");
	_glBlendFunc = DLLfunc(gl, "glBlendFunc");
	_glPixelStorei = DLLfunc(gl, "glPixelStorei");
	_glDepthFunc = DLLfunc(gl, "glDepthFunc");
	_glColorMask = DLLfunc(gl, "glColorMask");
	_glScissor = DLLfunc(gl, "glScissor");
	_glLogicOp = DLLfunc(gl, "glLogicOp");
	_glFogi = DLLfunc(gl, "glFogi");
	_glFogf = DLLfunc(gl, "glFogf");
	_glVertex2f = DLLfunc(gl, "glVertex2f");
	_glVertex3f = DLLfunc(gl, "glVertex3f");
	_glTexCoord4f = DLLfunc(gl, "glTexCoord4f");
	_glVertex4f = DLLfunc(gl, "glVertex4f");
	_glColor3f = DLLfunc(gl, "glColor3f");
	_glTexEnvi = DLLfunc(gl, "glTexEnvi");
	_glColor3ub = DLLfunc(gl, "glColor3ub");
	_glColor4ub = DLLfunc(gl, "glColor4ub");
	_glDepthMask = DLLfunc(gl, "glDepthMask");
	_glGetError = DLLfunc(gl, "glGetError");
	_glDeleteTextures = DLLfunc(gl, "glDeleteTextures");
	_glShadeModel = DLLfunc(gl, "glShadeModel");
}

void glExit(void) {
	DLLclose(gl);
	DLLclose(w3d);
}

int context = 0;

void createContext(void) {
	context = 1;
	DLLexec(DLLfunc(w3d, "createContext"));
}

void freeContext(void) {
	context = 0;
	DLLexec(DLLfunc(w3d, "freeContext"));
}
/*
void logString(char* str) {
	if (context && glGetError() != GL_NO_ERROR) logString("GL Error");
	DLLexec1(_logString, (long) str);
}

void logInt(long i) {
	DLLexec1(_logInt, i);
}

void logFloat(double f) {
	DLLexec1f(_logFloat, f);
}
*/