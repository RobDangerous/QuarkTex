#ifndef UAE_W3D
#define UAE_W3D

#include <stdlib.h>
#include <exec/libraries.h>
#include <proto/asl.h>

#include "Warp3D.h"
#include "gl.h"

void drawVertex(W3D_Context* context, W3D_Vertex* v, W3D_Texture* tex);
void bindTexture(W3D_Texture* tex);

extern W3D_Driver driver;
extern W3D_Driver *drivers[];

extern struct IntuitionBase *IntuitionBase;
extern struct GfxBase *GfxBase;

#endif