#include "w3d.h"

#include <proto/graphics.h>
#include <proto/picasso96.h>

W3D_ScreenMode *W3D_GetScreenmodeList(void) {
	LOG;
	return NULL;
}

void W3D_FreeScreenmodeList(__REGA0(W3D_ScreenMode *list)) {
	LOG;
}

ULONG W3D_BestModeID(__REGA0(struct TagItem *tags)) {
	int i;
	LOG;
	for (i = 0; tags[i].ti_Tag != TAG_DONE; ++i) {
		switch (tags[i].ti_Tag) {
		case W3D_BMI_DRIVER: tags[i].ti_Tag = TAG_IGNORE; break;
		case W3D_BMI_WIDTH: tags[i].ti_Tag = P96BIDTAG_NominalWidth; break;
		case W3D_BMI_HEIGHT: tags[i].ti_Tag = P96BIDTAG_NominalHeight; break;
		case W3D_BMI_DEPTH: tags[i].ti_Tag = P96BIDTAG_Depth; break;
		}
	}
	return p96BestModeIDTagList(tags);
}