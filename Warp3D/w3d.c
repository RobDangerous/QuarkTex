#include "w3d.h"
#include <proto/exec.h>

struct Warp3DBase {
	struct Library base;
};

#pragma libbase Warp3DBase

W3D_Driver driver;
W3D_Driver *drivers[] = {&driver, NULL};

struct IntuitionBase *IntuitionBase;
struct GfxBase *GfxBase;

long envs[] = {0, GL_REPLACE, GL_DECAL, GL_MODULATE, GL_BLEND};

void INIT_0_Warp3D(void) {
	glInit();
	logString("Warp3D INIT");
	driver.ChipID = W3D_CHIP_RADEON;
	driver.formats = W3D_FMT_CLUT | W3D_FMT_R5G5B5 | W3D_FMT_B5G5R5 | W3D_FMT_R5G5B5PC | W3D_FMT_B5G5R5PC |
		W3D_FMT_R5G6B5 | W3D_FMT_B5G6R5 | W3D_FMT_R5G6B5PC | W3D_FMT_B5G6R5PC | W3D_FMT_R8G8B8 |
		W3D_FMT_B8G8R8 | W3D_FMT_A8R8G8B8 | W3D_FMT_A8B8G8R8 | W3D_FMT_R8G8B8A8 | W3D_FMT_B8G8R8A8;
	driver.name = "OpenGL Wrapper";
	driver.swdriver = W3D_FALSE;
	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", 39L);
	GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 39L);
}

void EXIT_0_Warp3D(void) {
	logString("Warp3D EXIT");
	glExit();
	if (IntuitionBase)  CloseLibrary((struct Library *)IntuitionBase);
	if (GfxBase)        CloseLibrary((struct Library *)GfxBase);
}

W3D_Texture* lasttex;

void bindTexture(W3D_Texture* tex) {
	if (tex == lasttex || !tex) return;
	glBindTexture(GL_TEXTURE_2D, (long) tex->mipmapmask);
	if (tex->bytesperpix) glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, envs[tex->bytesperpix]);
	if (tex->bytesperpix == W3D_BLEND) aglTexEnvfv(((W3D_Color*) tex->driver)->r, ((W3D_Color*) tex->driver)->g, ((W3D_Color*) tex->driver)->b, ((W3D_Color*) tex->driver)->a);
	lasttex = tex;
}

void drawVertex(W3D_Context* context, W3D_Vertex* v, W3D_Texture* tex) {
	if (context->state & W3D_TEXMAPPING && tex) {
		if (context->state & W3D_PERSPECTIVE) glTexCoord4f(v->u * v->w / tex->texwidth, v->v * v->w / tex->texheight, 0.0f, v->w);
		else glTexCoord2f(v->u / tex->texwidth, v->v / tex->texheight);
	}
	if (context->state & W3D_GOURAUD) glColor4f(v->color.r, v->color.g, v->color.b, v->color.a);
	if (context->state & W3D_ZBUFFER) glVertex3f(v->x, v->y, v->z);
	else glVertex2f(v->x, v->y);
}