#include "w3d.h"

#include <proto/graphics.h>
#include <proto/picasso96.h>

ULONG W3D_CheckDriver(void) {
	LOG;
	return W3D_DRIVER_3DHW;
}
ULONG W3D_LockHardware(__REGA0(W3D_Context *context)) {
	LOG;
	context->HWlocked = W3D_TRUE;
	return W3D_SUCCESS;
}
void W3D_UnLockHardware(__REGA0(W3D_Context *context)) {
	LOG;
	context->HWlocked = W3D_FALSE;
}
void W3D_WaitIdle(__REGA0(W3D_Context *context)) {
	LOG;
	_glFinish();
}
ULONG W3D_CheckIdle(__REGA0(W3D_Context *context)) {
	LOG;
	_glFinish();
	return W3D_SUCCESS;
}
ULONG W3D_Query(__REGA0(W3D_Context *context), __REGD0(ULONG query), __REGD1(ULONG destfmt)) {
	LOG;
	if (query == W3D_Q_MAXTEXWIDTH || query == W3D_Q_MAXTEXHEIGHT) return 2048;
	if (query == W3D_Q_STENCILBUFFER || query == W3D_Q_STENCIL_MASK
		|| query == W3D_Q_STENCIL_FUNC || query == W3D_Q_STENCIL_SFAIL
		|| query == W3D_Q_STENCIL_DPFAIL || query == W3D_Q_STENCIL_DPPASS
		|| query == W3D_Q_STENCIL_WRMASK)
	return W3D_NOT_SUPPORTED;
	return W3D_FULLY_SUPPORTED;
}
ULONG W3D_GetTexFmtInfo(__REGA0(W3D_Context *context), __REGD0(ULONG texfmt), __REGD1(ULONG destfmt)) {
	LOG;
	return W3D_TEXFMT_FAST | W3D_TEXFMT_SUPPORTED;
}
ULONG W3D_GetDriverState(__REGA0(W3D_Context *context)) {
	LOG;
	return W3D_SUCCESS;
}
ULONG W3D_GetDestFmt(void) {
	LOG;
	return W3D_FMT_CLUT | W3D_FMT_R5G5B5 | W3D_FMT_B5G5R5 | W3D_FMT_R5G5B5PC | W3D_FMT_B5G5R5PC |
		W3D_FMT_R5G6B5 | W3D_FMT_B5G6R5 | W3D_FMT_R5G6B5PC | W3D_FMT_B5G6R5PC | W3D_FMT_R8G8B8 |
		W3D_FMT_B8G8R8 | W3D_FMT_A8R8G8B8 | W3D_FMT_A8B8G8R8 | W3D_FMT_R8G8B8A8 | W3D_FMT_B8G8R8A8;
}
W3D_Driver **W3D_GetDrivers(void) {
	LOG;
	return drivers;
}
ULONG W3D_QueryDriver(__REGA0(W3D_Driver* driver), __REGD0(ULONG hoppla), __REGD1(ULONG destfmt)) {
	LOG;
	return W3D_FULLY_SUPPORTED;
}
ULONG W3D_GetDriverTexFmtInfo(__REGA0(W3D_Driver* driver), __REGD0(ULONG query), __REGD1(ULONG destfmt)) {
	LOG;
	return W3D_TEXFMT_FAST | W3D_TEXFMT_SUPPORTED;
}
ULONG W3D_RequestMode(__REGA0(struct TagItem *taglist)) {
	int i;
	//ULONG modeID = 0;
	ULONG fmt = 0;
	//struct ScreenModeRequester *requester = AllocAslRequest(ASL_ScreenModeRequest, NULL);
	LOG;
	for (i = 0; taglist[i].ti_Tag != TAG_DONE; ++i) {
		switch (taglist[i].ti_Tag) {
		case W3D_SMR_SIZEFILTER: taglist[i].ti_Tag = TAG_IGNORE; break;
		case W3D_SMR_DRIVER: taglist[i].ti_Tag = TAG_IGNORE; break;
		//case W3D_SMR_DESTFMT: taglist[i].ti_Tag = TAG_IGNORE; break;
		case W3D_SMR_DESTFMT:
			taglist[i].ti_Tag = P96MA_FormatsAllowed;
			if (taglist[i].ti_Data & W3D_FMT_CLUT) fmt |= RGBFF_CLUT;
			if (taglist[i].ti_Data & W3D_FMT_R5G5B5) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_B5G5R5) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_R5G5B5PC) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_B5G5R5PC) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_R5G6B5) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_B5G6R5) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_R5G6B5PC) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_B5G6R5PC) fmt |= RGBFF_HICOLOR;
			if (taglist[i].ti_Data & W3D_FMT_R8G8B8) fmt |= RGBFF_TRUECOLOR;
			if (taglist[i].ti_Data & W3D_FMT_B8G8R8) fmt |= RGBFF_TRUECOLOR;
			if (taglist[i].ti_Data & W3D_FMT_A8R8G8B8) fmt |= RGBFF_TRUEALPHA;
			if (taglist[i].ti_Data & W3D_FMT_A8B8G8R8) fmt |= RGBFF_TRUEALPHA;
			if (taglist[i].ti_Data & W3D_FMT_R8G8B8A8) fmt |= RGBFF_TRUEALPHA;
			if (taglist[i].ti_Data & W3D_FMT_B8G8R8A8) fmt |= RGBFF_TRUEALPHA;
			taglist[i].ti_Data = fmt;
			break;
		case W3D_SMR_TYPE: taglist[i].ti_Tag = TAG_IGNORE; break;
		
		case ASLSM_MinWidth: taglist[i].ti_Tag = P96MA_MinWidth; break;
		case ASLSM_MinHeight: taglist[i].ti_Tag = P96MA_MinHeight; break;
		case ASLSM_MaxWidth: taglist[i].ti_Tag = P96MA_MaxWidth; break;
		case ASL_MaxHeight: taglist[i].ti_Tag = P96MA_MaxHeight; break;
		case ASLSM_MinDepth: taglist[i].ti_Tag = P96MA_MinDepth; break;
		case ASLSM_MaxDepth: taglist[i].ti_Tag = P96MA_MaxDepth; break;
		}
	}
	//AslRequest(requester, taglist);
	//modeID = requester->sm_DisplayID;
	//FreeAslRequest(requester);
	return p96RequestModeIDTagList(taglist);
	//return modeID;
}
W3D_Driver *W3D_TestMode(__REGD0(ULONG ModeID)) {
	LOG;
	return &driver;
}