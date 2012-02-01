#include "w3d.h"

/************************** Hardware/Driver functions ***************************/
ULONG W3D_CheckDriver(void) {
	logString("W3D_CheckDriver");
	return W3D_DRIVER_3DHW;
}
ULONG W3D_LockHardware(__REGA0(W3D_Context *context)) {
	logString("W3D_LockHardware");
	context->HWlocked = W3D_TRUE;
	return W3D_SUCCESS;
}
void W3D_UnLockHardware(__REGA0(W3D_Context *context)) {
	logString("W3D_UnlockHardware");
	context->HWlocked = W3D_FALSE;
	//nur im Fenster
	//DLLexec(swapBuffers);
	//DLLexec4(glClearColor, 0, 0, 0, 1);
	//DLLexec1(glClear, GL_COLOR_BUFFER_BIT);
}
void W3D_WaitIdle(__REGA0(W3D_Context *context)) {
	logString("W3D_WaitIdle");
	glFinish();
}
ULONG W3D_CheckIdle(__REGA0(W3D_Context *context)) {
	logString("W3D_CheckIdle");
	glFinish();
	return W3D_SUCCESS;
}
ULONG W3D_Query(__REGA0(W3D_Context *context), __REGD0(ULONG query), __REGD1(ULONG destfmt)) {
	logString("W3D_Query");
	if (query == W3D_Q_MAXTEXWIDTH) return 2048;
	if (query == W3D_Q_MAXTEXHEIGHT) return 2048;
	return W3D_FULLY_SUPPORTED;
}
ULONG W3D_GetTexFmtInfo(__REGA0(W3D_Context *context), __REGD0(ULONG texfmt), __REGD1(ULONG destfmt)) {
	logString("W3D_GetTexFmtInfo");
	return W3D_TEXFMT_FAST | W3D_TEXFMT_SUPPORTED;
}
ULONG W3D_GetDriverState(__REGA0(W3D_Context *context)) {
	logString("W3D_GetDriverState");
	return W3D_SUCCESS;
}
ULONG W3D_GetDestFmt(void) {
	logString("W3D_GetDestFmt");
	return W3D_FMT_CLUT | W3D_FMT_R5G5B5 | W3D_FMT_B5G5R5 | W3D_FMT_R5G5B5PC | W3D_FMT_B5G5R5PC |
		W3D_FMT_R5G6B5 | W3D_FMT_B5G6R5 | W3D_FMT_R5G6B5PC | W3D_FMT_B5G6R5PC | W3D_FMT_R8G8B8 |
		W3D_FMT_B8G8R8 | W3D_FMT_A8R8G8B8 | W3D_FMT_A8B8G8R8 | W3D_FMT_R8G8B8A8 | W3D_FMT_B8G8R8A8;
}
W3D_Driver **W3D_GetDrivers(void) {
	logString("W3D_GetDrivers");
	return drivers;
}
ULONG W3D_QueryDriver(__REGA0(W3D_Driver* driver), __REGD0(ULONG hoppla), __REGD1(ULONG destfmt)) {
	logString("W3D_QueryDriver");
	return W3D_FULLY_SUPPORTED;
}
ULONG W3D_GetDriverTexFmtInfo(__REGA0(W3D_Driver* driver), __REGD0(ULONG query), __REGD1(ULONG destfmt)) {
	logString("W3D_GetDriverTexFmtInfo");
	return W3D_TEXFMT_FAST | W3D_TEXFMT_SUPPORTED;
}
ULONG W3D_RequestMode(__REGA0(struct TagItem *taglist)) {
	int i;
	ULONG modeID = 0;
	struct ScreenModeRequester *requester = AllocAslRequest(ASL_ScreenModeRequest, NULL);
	logString("W3D_RequestMode");
	//AslRequestTags(requester, TAG_DONE);//ASLSM_Screen, , TAG_DONE);
	for (i = 0; taglist[i].ti_Tag != TAG_DONE; ++i) {
		switch (taglist[i].ti_Tag) {
		case W3D_SMR_SIZEFILTER: taglist[i].ti_Tag = TAG_IGNORE; break;
		case W3D_SMR_DRIVER: taglist[i].ti_Tag = TAG_IGNORE; break;
		case W3D_SMR_DESTFMT: taglist[i].ti_Tag = TAG_IGNORE; break;
		case W3D_SMR_TYPE: taglist[i].ti_Tag = TAG_IGNORE; break;
		}
	}
	AslRequest(requester, taglist);
	modeID = requester->sm_DisplayID;
	FreeAslRequest(requester);
	return modeID;
}
W3D_Driver *W3D_TestMode(__REGD0(ULONG ModeID)) {
	logString("W3D_TestMode");
	return &driver;
}