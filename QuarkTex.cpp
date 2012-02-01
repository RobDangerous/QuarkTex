#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
//#include <fstream>
//#include <strstream>

#define DLL extern "C" __declspec(dllexport)

namespace {
	struct winuae {
		HWND			amigawnd;    //adress of amiga Window Windows Handle
	    unsigned int    changenum;   //number to detect screen close/open 
	    unsigned int    z3offset;    //the offset to add to acsess Z3 mem from Dll side
	    int				causeint6;   //if set a interrupt Level 6 is generate for 68k side
		long            (*call68k)(); //Call: (*uaepar->call68k)(par ....)    
	};

	bool screenlost(winuae* uaepar, unsigned& oldnum) {
		if (uaepar->changenum == oldnum) return false;
		oldnum = uaepar->changenum;
		return true;
	}

	HINSTANCE instance = 0;
	HWND windowHandle = 0;
	HDC deviceContext = 0;
	HGLRC glContext = 0;

	LRESULT CALLBACK windowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
		switch (message) {
		case WM_NCCREATE:
			return 1;
		case WM_NCDESTROY:
			//ghwndApp = 0;
			//closevideo();
			return 1;
		case WM_CREATE: 
			// Initialize the window.
			return 0;  
		case WM_DESTROY:
			//ghwndApp = 0;
			// Clean up window-specific data objects.
			return 0; 
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
		}
	}
}

//std::ofstream out("QuarkTexLog.txt");

DLL void logString(char* c) {
	//out << c;
	//out.flush();
}

int cleft, ctop, cwidth, cheight;
//                          d1       d2         d3          d4   d5   d6   d7   a1   a2   a3   a4   a5          a6
DLL int createContext(int left, int top, int width, int height, int, int, int, int, int, int, int, int, winuae* a6) {
	cleft = left; ctop = top; cwidth = width; cheight = height;
//	std::strstream str;
//	str << "Creating Context(left: " << left << ", top: " << top << ", width: " << width << ", height: " << height << ")\n";
//	logString(str.str());

	RECT rect;
	GetClientRect(a6->amigawnd, &rect);
	if (!width) {
		left = rect.left;
		top = rect.top;
		width = rect.right - rect.left;
		height = rect.bottom - rect.top;
	}
	else {
		left += rect.left;
		top += rect.top;
	}

	if (!instance) instance = GetModuleHandle(0);

	WNDCLASS wc;
	memset(&wc, 0, sizeof(WNDCLASS));
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = windowFunc;
	wc.hInstance = instance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.lpszClassName = "QuarkTex";

	if (!RegisterClass(&wc)) { logString("Warning: Could not register Window Class"); return 0; }

	if (!(windowHandle = CreateWindowEx(0, "QuarkTex", "", WS_CHILD | WS_VISIBLE, left, top, width, height, a6->amigawnd, 0, 0, 0))) logString("Warning: Could not create Window");
	if (!(deviceContext = GetDC(windowHandle))) { logString("Warning: Could not get Device Context"); return 0; }

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
	if ((pixelformat = ChoosePixelFormat(deviceContext, &pfd)) == 0) { logString("Warning: Could not choose pixel format"); return 0; }
	if (!SetPixelFormat(deviceContext, pixelformat, &pfd)) { logString("Warning: Could not set pixel format"); return 0; }

	if (!(glContext = wglCreateContext(deviceContext))) { logString("Warning: Could not create rendering context"); return 0; }
	if (!(wglMakeCurrent(deviceContext, glContext))) { logString("Warning: Could not activate the rendering context"); return 0; }

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glScalef(2.0f / static_cast<float>(width), -2.0f / static_cast<float>(height), 1.0f);
	glTranslatef(-(static_cast<float>(width) / 2.0f), -(static_cast<float>(height) / 2.0f), 0.0f);

	logString("Rendering context successfully created and activated");
	return 1;
}

DLL void moveWindow(int left, int top, int width, int height) {
	MoveWindow(windowHandle, left, top, width, height, FALSE);
}

//                    d1   d2   d3   d4   d5   d6   d7   a1   a2   a3   a4   a5          a6
DLL void freeContext(int, int, int, int, int, int, int, int, int, int, int, int, winuae* a6) {
	if (glContext) {
		wglMakeCurrent(0, 0);
		wglDeleteContext(glContext);
		glContext = 0;
	}
	if (deviceContext) {
		ReleaseDC(a6->amigawnd, deviceContext);
		deviceContext = 0;
	}
	if (windowHandle) {
		DestroyWindow(windowHandle);
		windowHandle = 0;
	}

	UnregisterClass("QuarkTex", instance);
}

DLL void swapBuffers(int, int, int, int, int, int, int, int, int, int, int, int, winuae* a6) {
	static unsigned oldnum;
	if (screenlost(a6, oldnum)) logString("Warning: Screen Lost");
	SwapBuffers(deviceContext);
	//glClear(GL_COLOR_BUFFER_BIT);
	/*GLenum code = glGetError();
	if (code!=GL_NO_ERROR) logString("GL Error!\n");
	while (code!=GL_NO_ERROR)
	{
		logString((char *) gluErrorString(code));
		code = glGetError();
	}*/
}