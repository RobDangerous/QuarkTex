#include "../gl/gl.h"
#include <stdlib.h>
#include <proto/exec.h>
#include <proto/utility.h>
//#include <intuition/intuitionbase.h>
#include "Amigamesa.h"
#include <math.h>

struct StormMESABase {
	struct Library base;
};

#pragma libbase StormMESABase

long memoffset = 0;

//struct IntuitionBase *IntuitionBase;

void INIT_0_StormMESA(void) {
	glInit();
	LOG
//	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", 39L);
	//oldGluPerspective = SetFunction(gluBase, -48, _gluPerspective);
}

void EXIT_0_StormMESA(void) {
	LOG
	glExit();
//	if (IntuitionBase) CloseLibrary((struct Library *)IntuitionBase);
	//if (oldGluPerspective) SetFunction(gluBase, -48, oldGluPerspective);
}

void registerGL(void *ptr __asm("a0")) {}

void initDD(void *  bla){}
void dispose (struct amigamesa_context *c){}
void swapBuffer (struct amigamesa_context *c){}

struct Window* window = NULL;
int left, top, width, height;
int fullscreen;

struct amigamesa_context *AmigaMesaCreateContext(struct TagItem *tagList __asm("a0")) {
	struct amigamesa_context* context;
	LOG
	//window = IntuitionBase->ActiveWindow;
	window = (struct Window*) GetTagData(AMA_Window, NULL, tagList);
	fullscreen = GetTagData(AMA_Fullscreen, 0, tagList);
	if (fullscreen) createContext(window->LeftEdge, window->TopEdge, window->Width, window->Height);
	else createContext(window->LeftEdge + window->BorderLeft, window->TopEdge + window->BorderTop,
			window->Width - (window->BorderLeft + window->BorderRight), window->Height - (window->BorderTop + window->BorderBottom));
	left = window->LeftEdge + window->BorderLeft;
	top = window->TopEdge + window->BorderTop;
	width = window->Width - (window->BorderLeft + window->BorderRight);
	height = window->Height - (window->BorderTop + window->BorderBottom);
	context = (struct amigamesa_context*) malloc(sizeof(struct amigamesa_context));
	context->visual = (struct amigamesa_visual*) malloc(sizeof(struct amigamesa_visual));
	context->visual->rgb_flag = GetTagData(AMA_RGBMode, GL_TRUE, tagList);
	context->visual->db_flag = GetTagData(AMA_DoubleBuf, GL_FALSE, tagList);
	context->visual->alpha_flag = GetTagData(AMA_AlphaFlag, GL_FALSE, tagList);
	context->visual->depth = 16;
	if (GetTagData(AMA_NoDepth, GL_FALSE, tagList)) context->visual->depth = 0;
	context->visual->stencil = 8;
	if (GetTagData(AMA_NoStencil, GL_FALSE, tagList)) context->visual->stencil = 0;
	context->visual->accum = 16;
	if (GetTagData(AMA_NoAccum, GL_FALSE, tagList)) context->visual->accum = 0;
	context->buffer = (struct amigamesa_buffer*) malloc(sizeof(struct amigamesa_buffer));
	//context->

	context->InitDD = initDD;
	context->Dispose = dispose;
	context->SwapBuffer = swapBuffer;

	return context;
}
void AmigaMesaDestroyContext(struct amigamesa_context *c __asm("a0")) {
	LOG
	free(c->visual);
	free(c->buffer);
	freeContext();
}
struct amigamesa_visual *AmigaMesaCreateVisual(struct TagItem *tagList __asm("a0")) {
	struct amigamesa_visual* visual;
	LOG
	visual = (struct amigamesa_visual*) malloc(sizeof(struct amigamesa_visual));
	visual->rgb_flag = GetTagData(AMA_RGBMode, GL_TRUE, tagList);
	visual->db_flag = GetTagData(AMA_DoubleBuf, GL_FALSE, tagList);
	visual->alpha_flag = GetTagData(AMA_AlphaFlag, GL_FALSE, tagList);
	visual->depth = 16;
	if (GetTagData(AMA_NoDepth, GL_FALSE, tagList)) visual->depth = 0;
	visual->stencil = 8;
	if (GetTagData(AMA_NoStencil, GL_FALSE, tagList)) visual->stencil = 0;
	visual->accum = 16;
	if (GetTagData(AMA_NoAccum, GL_FALSE, tagList)) visual->accum = 0;
	return visual;
}

void AmigaMesaDestroyVisual(struct amigamesa_visual *v __asm("a0")) {
	LOG
	free(v);
}
void AmigaMesaMakeCurrent(struct amigamesa_context *amesa __asm("a0"), struct amigamesa_buffer *b __asm("a1")) {LOG}
void AmigaMesaSwapBuffers(struct amigamesa_context *amesa __asm("a0")) {
	LOG
	if (!fullscreen && (left != window->LeftEdge + window->BorderLeft || top != window->TopEdge + window->BorderTop ||
		width != window->Width - (window->BorderLeft + window->BorderRight) || height != window->Height - (window->BorderTop + window->BorderBottom))) {
		left = window->LeftEdge + window->BorderLeft;
		top = window->TopEdge + window->BorderTop;
		width = window->Width - (window->BorderLeft + window->BorderRight);
		height = window->Height - (window->BorderTop + window->BorderBottom);;
		moveWindow(left, top, width, height);
	}
	swapBuffers();
}
void AmigaMesaSetOneColor(struct amigamesa_context *c __asm("a0"), int index __asm("d0"), float r __asm("fp0"), float g __asm("fp1"), float b __asm("fp2")) {LOG}
void AmigaMesaSetRast(struct amigamesa_context *c __asm("a0"), struct TagItem* tagList __asm("a1")) {LOG}
void AmigaMesaGetConfig(struct amigamesa_visual *v __asm("a0"), GLenum pname __asm("d0"), GLint* params __asm("a1")) {LOG}

void Dummy_at_90(void){}
void Dummy_at_96(void){}
void Dummy_at_102(void){}
void Dummy_at_108(void){}
void Dummy_at_114(void){}
void Dummy_at_120(void){}
void Dummy_at_126(void){}
void Dummy_at_132(void){}
void Dummy_at_138(void){}
void Dummy_at_144(void){}
void Dummy_at_150(void){}
void Dummy_at_156(void){}
void Dummy_at_162(void){}
void Dummy_at_168(void){}
void Dummy_at_174(void){}