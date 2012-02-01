#include "w3d.h"
#include <proto/exec.h>

ULONG oldrectfillasm = 0;
ULONG w3dtaskasm = 0;

ULONG blub(VOID) { return 1; }
ULONG dummyrect(VOID) {
	asm("
	MOVEM.l a6/d0,-(a7)
	MOVE.l 0x4,a6
	MOVE.l 0x114(a6),d0
	CMP.l _w3dtaskasm,d0
	BEQ patch
	MOVEM.l (a7)+,a6/d0
	MOVE.l _oldrectfillasm,-(a7)
	RTS
	patch:
	MOVEM.l (a7)+,a6/d0
	MOVEQ #1,d0
	RTS
	");
}

ULONG (*oldscrollvport)(VOID) = NULL;
ULONG (*olderaserect)(VOID) = NULL;
ULONG (*oldrectfill)(VOID) = NULL;
ULONG (*oldchangescreenbuffer)(VOID) = NULL;

/************************** Context functions ***********************************/
W3D_Context *W3D_CreateContext(__REGA0(ULONG *error),__REGA1(struct TagItem *CCTags)) {
	//unsigned int bla = 32 * 800 * 600;
	//void *fake = malloc(bla);
	W3D_Context *context = (W3D_Context*) malloc(sizeof(W3D_Context));
	logString("W3D_CreateContext");

	context->driver = NULL; context->gfxdriver = NULL; context->drivertype = 0;
	context->regbase = NULL; context->vmembase = NULL;
	context->zbuffer = NULL; context->stencilbuffer = NULL;
	context->state = 0;
	context->drawregion = NULL;
	context->supportedfmt = 0; context->format = 0;
	context->yoffset = 0; context->bprow = 0;
	context->width = 0; context->height = 0; context->depth = 0;
	context->chunky = W3D_FALSE; context->destalpha = W3D_FALSE; context->zbufferalloc = W3D_FALSE;
	context->stbufferalloc = W3D_FALSE; context->HWlocked = W3D_FALSE; context->w3dbitmap = W3D_FALSE;
	context->zbufferlost = W3D_FALSE; context->reserved3 = W3D_FALSE;
	//struct MinList restex;
	//struct MinList tex;
	context->maxtexwidth = 0; context->maxtexheight = 0; context->maxtexwidthp = 0; context->maxtexheightp = 0;
	//W3D_Scissor scissor;
	//W3D_Fog fog;
	context->envsupmask = 0; context->queue = (W3D_Queue*) malloc(sizeof(W3D_Queue)); context->drawmem = NULL; //fake;
	context->globaltexenvmode = 0;
	context->globaltexenvcolor[0] = 0.0; context->globaltexenvcolor[1] = 0.0; context->globaltexenvcolor[2] = 0.0; context->globaltexenvcolor[3] = 0.0;
	context->DriverBase = NULL;
	context->EnableMask = 0; context->DisableMask = 0;
	context->CurrentChip = 0; context->DriverVersion = 0;
	context->VertexPointer = NULL; context->VPStride = 0; context->VPMode = 0; context->VPFlags = 0;
	context->TexCoordPointer[0] = NULL; context->TPStride[0] = 0; context->CurrentTex[0] = NULL; context->TPVOffs[0] = 0; context->TPWOffs[0] = 0; context->TPFlags[0] = 0;
	context->ColorPointer = NULL; context->CPStride = 0; context->CPMode = 0; context->CPFlags = 0;
	context->FrontFaceOrder = 0; context->specialbuffer = 0;

	createContext();

	if (error) *error = W3D_SUCCESS;
	//for (; CCTags->ti_Tag != TAG_DONE; ++CCTags) {}
	
	oldscrollvport = SetFunction((struct Library *)GfxBase, -0x24c, blub);
	olderaserect = SetFunction((struct Library *)GfxBase, -0x32a, blub);
	oldrectfill = SetFunction((struct Library *)GfxBase, -0x132, blub);
	
	/*asm("
	MOVE.l d0,_oldrectfillasm
	MOVE.l 0x4,a6
	MOVE.l 0x114(a6),_w3dtaskasm
	");*/
	
	oldchangescreenbuffer = SetFunction((struct Library *)IntuitionBase, -780, blub);

	return context;
}
void W3D_DestroyContext(__REGA0(W3D_Context *context)) {
	logString("W3D_DestroyContext");
	SetFunction((struct Library *)GfxBase, -0x24c, oldscrollvport);
	SetFunction((struct Library *)GfxBase, -0x32a, olderaserect);
	SetFunction((struct Library *)GfxBase, -0x132, oldrectfill);
	SetFunction((struct Library *)IntuitionBase, -780, oldchangescreenbuffer);
	free(context);
	freeContext();
}
ULONG W3D_GetState(__REGA0(W3D_Context *context), __REGD1(ULONG state)) {
	logString("W3D_GetState");
	if (context->state & state) return W3D_ENABLED;
	return W3D_DISABLED;
}
ULONG W3D_SetState(__REGA0(W3D_Context *context), __REGD0(ULONG state), __REGD1(ULONG action)) {
	logString("W3D_SetState");
	if (action == W3D_ENABLE) {
		context->state |= state;
		switch (state) {
		case W3D_AUTOTEXMANAGEMENT:	logString("W3D_AUTOTEXMANAGEMENT"); break;
		case W3D_SYNCHRON:		logString("W3D_SYNCHRON"); break;
		case W3D_INDIRECT:		logString("W3D_INDIRECT"); break;
		case W3D_GLOBALTEXENV:		logString("W3D_GLOBALTEXENV"); break;
		case W3D_DOUBLEHEIGHT:		logString("W3D_DOUBLEHEIGHT"); break;
		case W3D_FAST:			logString("W3D_FAST"); break;
		case W3D_TEXMAPPING:		logString("W3D_TEXMAPPING"); glEnable(GL_TEXTURE_2D); break;
		case W3D_PERSPECTIVE:		logString("W3D_PERSPECTIVE"); break;
		case W3D_GOURAUD:		logString("W3D_GOURAUD"); glShadeModel(GL_SMOOTH); break;
		case W3D_ZBUFFER:		logString("W3D_ZBUFFER"); glEnable(GL_DEPTH_TEST); break;
		case W3D_ZBUFFERUPDATE:		logString("W3D_ZBUFFERUPDATE"); /*glDepthMask(GL_FALSE);*/ break;
		case W3D_BLENDING:		logString("W3D_BLENDING"); glEnable(GL_BLEND); break;
		case W3D_FOGGING:		logString("W3D_FOGGING"); glEnable(GL_FOG); break;
		case W3D_ANTI_POINT:		logString("W3D_ANTI_POINT"); break;
		case W3D_ANTI_LINE:		logString("W3D_ANTI_LINE"); break;
		case W3D_ANTI_POLYGON:		logString("W3D_ANTI_POLYGON"); break;
		case W3D_ANTI_FULLSCREEN:	logString("W3D_ANTI_FULLSCREEN"); break;
		case W3D_DITHERING:		logString("W3D_DITHERING"); break;
		case W3D_LOGICOP:		logString("W3D_LOGICOP"); glEnable(GL_COLOR_LOGIC_OP); break;
		case W3D_STENCILBUFFER:		logString("W3D_STENCILBUFFER"); break;
		case W3D_ALPHATEST:		logString("W3D_ALPHATEST"); glEnable(GL_ALPHA_TEST); break;
		case W3D_SPECULAR:		logString("W3D_SPECULAR"); break;
		case W3D_TEXMAPPING3D:		logString("W3D_TEXMAPPING3D"); break;
		case W3D_SCISSOR:		logString("W3D_SCISSOR"); glEnable(GL_SCISSOR_TEST); break;
		case W3D_CHROMATEST:		logString("W3D_CHROMATEST"); break;
		case W3D_CULLFACE:		logString("W3D_CULLFACE"); break;
		}
	}
	else {
		logString("Disable");
		context->state &= ~state;
		switch (state) {
		case W3D_AUTOTEXMANAGEMENT:	break;
		case W3D_SYNCHRON:		break;
		case W3D_INDIRECT:		break;
		case W3D_GLOBALTEXENV:		break;
		case W3D_DOUBLEHEIGHT:		break;
		case W3D_FAST:			break;
		case W3D_TEXMAPPING:		glDisable(GL_TEXTURE_2D); break;
		case W3D_PERSPECTIVE:		break;
		case W3D_GOURAUD:		glShadeModel(GL_FLAT); break;
		case W3D_ZBUFFER:		glDisable(GL_DEPTH_TEST); break;
		case W3D_ZBUFFERUPDATE:		/*glDepthMask(GL_TRUE);*/ break;
		case W3D_BLENDING:		glDisable(GL_BLEND); break;
		case W3D_FOGGING:		glDisable(GL_FOG); break;
		case W3D_ANTI_POINT:		break;
		case W3D_ANTI_LINE:		break;
		case W3D_ANTI_POLYGON:		break;
		case W3D_ANTI_FULLSCREEN:	break;
		case W3D_DITHERING:		break;
		case W3D_LOGICOP:		glDisable(GL_COLOR_LOGIC_OP); break;
		case W3D_STENCILBUFFER:		break;
		case W3D_ALPHATEST:		glDisable(GL_ALPHA_TEST); break;
		case W3D_SPECULAR:		break;
		case W3D_TEXMAPPING3D:		break;
		case W3D_SCISSOR:		glDisable(GL_SCISSOR_TEST); break;
		case W3D_CHROMATEST:		break;
		case W3D_CULLFACE:		break;
		}
	}
	return W3D_SUCCESS;
}
ULONG W3D_Hint(__REGA0(W3D_Context *context), __REGD0(ULONG mode), __REGD1(ULONG quality)) {
	logString("W3D_Hint");
	return W3D_SUCCESS;
}