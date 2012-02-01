#include "w3d.h"
#include <clib/graphics_protos.h>

/*************************** V3 Screenmode functions ******************************/
W3D_ScreenMode *W3D_GetScreenmodeList(void) { logString("W3D_ScreemMode"); return NULL; }
void            W3D_FreeScreenmodeList(__REGA0(W3D_ScreenMode *list)) { logString("W3D_FreeScreenModeList"); }
ULONG W3D_BestModeID(__REGA0(struct TagItem *tags)) {
	int i;
	logString("W3D_BestModeID");
	for (i = 0; tags[i].ti_Tag != TAG_DONE; ++i) {
		switch (tags[i].ti_Tag) {
		case W3D_BMI_DRIVER: tags[i].ti_Tag = TAG_IGNORE; break;
		case W3D_BMI_WIDTH: tags[i].ti_Tag = BIDTAG_NominalWidth; break;
		case W3D_BMI_HEIGHT: tags[i].ti_Tag = BIDTAG_NominalHeight; break;
		case W3D_BMI_DEPTH: tags[i].ti_Tag = BIDTAG_Depth; break;
		}
	}
	return BestModeIDA(tags);
}