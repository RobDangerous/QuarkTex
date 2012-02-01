#ifndef UAE_W3D
#define UAE_W3D

#include <stdlib.h>
#include <exec/libraries.h>
#include <proto/asl.h>

#include "Warp3D.h"
#include "../gl/gl.h"

typedef struct {
	GLuint glID;
	ULONG envparam;
	W3D_Color envcolor;
	ULONG MinFilter, MagFilter;
	ULONG s_mode, t_mode;
	W3D_Color bordercolor;
} Texture;

void drawVertex(W3D_Context* context, W3D_Vertex* v, W3D_Texture* tex);
void bindTexture(W3D_Texture* tex);

extern W3D_Driver driver;
extern W3D_Driver *drivers[];

extern struct IntuitionBase *IntuitionBase;
extern struct GfxBase *GfxBase;
extern struct Library *P96Base;

extern char *bp, b;
extern int i;

extern int fullscreen;
extern int width, height;

#endif