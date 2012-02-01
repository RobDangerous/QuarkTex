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
struct Library *P96Base;

char *bp, b;
int i;

int fullscreen = 0;
int width = 0;
int height = 0;

long envs[] = {0, GL_REPLACE, GL_DECAL, GL_MODULATE, GL_BLEND};

void INIT_0_Warp3D(void) {
	glInit();
	LOG
	driver.ChipID = W3D_CHIP_RADEON;
	driver.formats = W3D_FMT_CLUT | W3D_FMT_R5G5B5 | W3D_FMT_B5G5R5 | W3D_FMT_R5G5B5PC | W3D_FMT_B5G5R5PC |
		W3D_FMT_R5G6B5 | W3D_FMT_B5G6R5 | W3D_FMT_R5G6B5PC | W3D_FMT_B5G6R5PC | W3D_FMT_R8G8B8 |
		W3D_FMT_B8G8R8 | W3D_FMT_A8R8G8B8 | W3D_FMT_A8B8G8R8 | W3D_FMT_R8G8B8A8 | W3D_FMT_B8G8R8A8;
	driver.name = "QuarkTex";
	driver.swdriver = W3D_FALSE;
	IntuitionBase = (struct IntuitionBase *)OpenLibrary("intuition.library", 39L);
	GfxBase = (struct GfxBase *)OpenLibrary("graphics.library", 39L);
	P96Base = OpenLibrary("Picasso96API.library", 2);
}

void EXIT_0_Warp3D(void) {
	LOG
	glExit();
	if (IntuitionBase) CloseLibrary((struct Library *)IntuitionBase);
	if (GfxBase) CloseLibrary((struct Library *)GfxBase);
	if (P96Base) CloseLibrary(P96Base);
}

//W3D_Texture* lasttex;

static float color[] = {0.0, 0.0, 0.0, 0.0};

void bindTexture(W3D_Texture* tex) {
	//if (tex == lasttex || !tex) return;
	if (!tex) return;
	_glBindTexture(GL_TEXTURE_2D, ((Texture*) tex->driver)->glID);
	if (((Texture*) tex->driver)->envparam) _glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, envs[tex->bytesperpix]);
	if (((Texture*) tex->driver)->envparam == W3D_BLEND) {
		color[0] = ((Texture*) tex->driver)->envcolor.r; color[1] = ((Texture*) tex->driver)->envcolor.b;
		color[2] = ((Texture*) tex->driver)->envcolor.g; color[3] = ((Texture*) tex->driver)->envcolor.a;
		SWAP32(color, 4)
		_glTexEnvfv(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, (GLfloat*) (memoffset + (long) color));
	}
	if (((Texture*) tex->driver)->MinFilter) _glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (long) ((Texture*) tex->driver)->MinFilter);
	if (((Texture*) tex->driver)->MagFilter) _glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (long) ((Texture*) tex->driver)->MagFilter);
	if (((Texture*) tex->driver)->s_mode) _glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, (long) ((Texture*) tex->driver)->s_mode);
	if (((Texture*) tex->driver)->t_mode) _glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, (long) ((Texture*) tex->driver)->t_mode);
	color[0] = ((Texture*) tex->driver)->bordercolor.r; color[1] = ((Texture*) tex->driver)->bordercolor.b;
	color[2] = ((Texture*) tex->driver)->bordercolor.g; color[3] = ((Texture*) tex->driver)->bordercolor.a;
	SWAP32(color, 4)
	_glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, (GLfloat*) (memoffset + (long) color));
	//lasttex = tex;
}

void drawVertex(W3D_Context* context, W3D_Vertex* v, W3D_Texture* tex) {
	if (context->state & W3D_TEXMAPPING && tex) {
		if (context->state & W3D_PERSPECTIVE) _glTexCoord4f(v->u * v->w / tex->texwidth, v->v * v->w / tex->texheight, 0.0f, v->w);
		else _glTexCoord2f((float) ((double) v->u / (double) tex->texwidth), (float) ((double) v->v / (double) tex->texheight));
	//	if (context->state & W3D_PERSPECTIVE) qlTexCoord4i((long) (v->u * v->w), (long) (v->v * v->w), 0, (long) v->w);
	//	else qlTexCoord2i((long) v->u, (long) v->v);
	}
	if (context->state & W3D_GOURAUD) _glColor4f(v->color.r, v->color.g, v->color.b, v->color.a);
	if (context->state & W3D_ZBUFFER) _glVertex3f(v->x, v->y, v->z);
	else _glVertex2f(v->x, v->y);
}