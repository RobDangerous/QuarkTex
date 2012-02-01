#include "w3d.h"

#include <proto/graphics.h>
#include <proto/picasso96.h>
/*
typedef struct
{
    ULONG ModeID;               // ModeID for OpenScreen
    ULONG Width, Height;        // Width and Height for visible screen
    ULONG Depth;                // Pixel Depth
    char DisplayName[DISPLAYNAMELEN];   // readable name of this display mode 
    W3D_Driver *Driver PACKED;  // Matching driver for this mode
    void *Next PACKED;          // Next W3D_ScreenMode in list
}
W3D_ScreenMode;

struct P96Mode {
	struct Node	Node;
	char			Description[MODENAMELENGTH];
	UWORD			Width;
	UWORD			Height;
	UWORD			Depth;
	ULONG			DisplayID;
};
*/
W3D_ScreenMode *W3D_GetScreenmodeList(void) {
	struct List		*ml;
	W3D_ScreenMode* smstart = malloc(sizeof(W3D_ScreenMode));
	W3D_ScreenMode* sm = smstart;
	LOG;
	//p96AllocModeListTagList
	if (ml = p96AllocModeListTags(TAG_DONE)) {
		struct P96Mode	*mn;
		int i;
		for (mn = (struct P96Mode *)(ml->lh_Head); mn->Node.ln_Succ; mn = (struct P96Mode *)mn->Node.ln_Succ) {
			//printf("%s\n",mn->Description);
			sm->ModeID = mn->DisplayID;
			sm->Width = mn->Width;
			sm->Height = mn->Height;
			sm->Depth = mn->Depth;
			sm->Driver = drivers[0];
			for (i = 0; i < MODENAMELENGTH && i < DISPLAYNAMELEN; ++i) sm->DisplayName[i] = mn->Description[i];
			sm->Next = malloc(sizeof(W3D_ScreenMode));
			sm = sm->Next;
		}
		p96FreeModeList(ml);
	}
	return smstart;
}

void W3D_FreeScreenmodeList(__REGA0(W3D_ScreenMode *list)) {
	W3D_ScreenMode* current;
	W3D_ScreenMode* next = list;
	LOG;
	while (next) {
		current = next;
		next = current->Next;
		free(current);
	}
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