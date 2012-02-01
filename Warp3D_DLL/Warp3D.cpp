#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <fstream>
#include "winuaesupport.h"
#include "glext.h"

HDC deviceContext;
HGLRC glContext;

bool setupPixelFormat() {
	PIXELFORMATDESCRIPTOR pfd;
	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.dwLayerMask = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 16;
	pfd.cStencilBits = 8;
	int pixelformat;
	if ((pixelformat = ChoosePixelFormat(deviceContext, &pfd)) == 0) return false;
	if (!SetPixelFormat(deviceContext, pixelformat, &pfd)) return false;
	return true;
}

template<class T>
inline void log(const T& s) {
	#ifdef _DEBUG
	static std::ofstream out("warp3dlog.txt");
	out << s << std::endl;
	#endif
}

//                 d1   d2   d3   d4   d5   d6   d7   a1   a2   a3   a4   a5          a6   a7
int createContext(int, int, int, int, int, int, int, int, int, int, int, int, winuae* a6, int) {
	log("createContext");
	deviceContext = GetDC(a6->amigawnd);
	if (!setupPixelFormat()) return 0;
 
	glContext = wglCreateContext(deviceContext);
	wglMakeCurrent(deviceContext, glContext);

	RECT rect;
	GetClientRect(a6->amigawnd, &rect);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(2.0f / (float)rect.right, -2.0f / (float)rect.bottom, 1.0f);
	glTranslatef(-((float)rect.right / 2.0f), -((float)rect.bottom / 2.0f), 0.0f);
	glViewport(0, 0, rect.right, rect.bottom);

	return 1;
}

//                d1   d2   d3   d4   d5   d6   d7   a1   a2   a3   a4   a5          a6   a7
void freeContext(int, int, int, int, int, int, int, int, int, int, int, int, winuae* a6, int) {
	log("freeContext");
	if (glContext) wglDeleteContext(glContext);
	if (deviceContext) ReleaseDC(a6->amigawnd, deviceContext);
}

void swapBuffers() {
	log("swapBuffers");
	SwapBuffers(deviceContext);
	glClear(GL_COLOR_BUFFER_BIT);
}

//                 d1   d2   d3   d4   d5   d6   d7   a1   a2   a3   a4   a5          a6   a7
void logString(int d1, int, int, int, int, int, int, int, int, int, int, int, winuae* a6, int) {
	log(reinterpret_cast<char*>(d1 + a6->z3offset));
}

void logInt(int d1) {
	log(d1);
}

void logFloat(float d1) {
	log(d1);
}

int loadTexture(int d1, int width, int height, unsigned int format, unsigned int type, int, int, int, int, int, int, int, winuae* a6, int) {
	char* tex = reinterpret_cast<char*>(d1 + a6->z3offset);
	
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	unsigned int name;
	glGenTextures(1, &name);
	glBindTexture(GL_TEXTURE_2D, name);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, format, type, tex);
	return name;
}

void aglFogColor(float r, float g, float b) {
	float color[] = {r, g, b, 0};
	glFogfv(GL_FOG_COLOR, color);
}

void aglTexEnvfv(float r, float g, float b, float a) {
	float color[] = {r, g, b, a};
	glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, color);
}

void deleteTexture(unsigned int tex) {
	glDeleteTextures(1, &tex);
}