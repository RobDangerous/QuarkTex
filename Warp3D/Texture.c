#include "w3d.h"

long swap[] = {0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0};
long formats[] = {0, GL_RGB, GL_BGRA, GL_RGB, GL_RGB, GL_BGRA, GL_BGRA, GL_ALPHA, GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_INTENSITY, GL_RGBA};
long types[] = {0, GL_UNSIGNED_BYTE_3_3_2, GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_4_4_4_4_REV,
		GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE};

/************************** Texture functions ***********************************/
W3D_Texture *W3D_AllocTexObj(__REGA0(W3D_Context *context), __REGA1(ULONG *error), __REGA2(struct TagItem *ATOTags)) {
	W3D_Texture *tex;
	logString("W3D_AllocTexObj");
	tex = (W3D_Texture*) malloc(sizeof(W3D_Texture));

	tex->resident = W3D_TRUE;
	tex->mipmap = W3D_FALSE;
	tex->dirty = W3D_FALSE;
	tex->matchfmt = W3D_TRUE;
	tex->reserved1 = W3D_TRUE;
	tex->reserved2 = W3D_TRUE;
	tex->mipmapmask = 0;
	tex->texsource = NULL;
	tex->mipmaps[16] = NULL;
	tex->texfmtsrc = 0;
	tex->palette = NULL;
	tex->texdata = NULL;
	tex->texdest = NULL;
	tex->texdestsize = 0;
	tex->texwidth = 0;
	tex->texwidthexp = 0;
	tex->texheight = 0;
	tex->texheightexp = 0;
	tex->bytesperpix = 0;
	tex->bytesperrow = 0;
	tex->driver = NULL;

	for (; ATOTags->ti_Tag != TAG_DONE; ++ATOTags) {
		switch (ATOTags->ti_Tag) {
		case W3D_ATO_IMAGE:
			tex->texsource = (void*) ATOTags->ti_Data;
			break;
		case W3D_ATO_FORMAT:
			tex->texfmtsrc = ATOTags->ti_Data;
			break;
		case W3D_ATO_WIDTH:
			tex->texwidth = ATOTags->ti_Data;
			break;
		case W3D_ATO_HEIGHT:
			tex->texheight = ATOTags->ti_Data;
			break;
		}
	}
	glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
	if (swap[tex->texfmtsrc]) glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	else glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
	tex->mipmapmask = loadTexture(tex->texsource, tex->texwidth, tex->texheight, formats[tex->texfmtsrc], types[tex->texfmtsrc]);
	if (error) *error = W3D_SUCCESS;
	return tex;
}
void W3D_FreeTexObj(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture)) {
	logString("W3D_FreeTexObj");
	if (texture->mipmapmask) deleteTexture((long)texture->mipmapmask);
	//if (texture->texsource) free(texture->texsource);
	free(texture);
}
void W3D_ReleaseTexture(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture)) {
	logString("W3D_ReleaseTexture");
}
void            W3D_FlushTextures(__REGA0(W3D_Context *context)) { logString("W3D_FlushTextures"); }
ULONG           W3D_SetFilter(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD0(ULONG MinFilter), __REGD1(ULONG MagFilter)) { logString("W3D_SetFilter");	return W3D_SUCCESS; }
ULONG W3D_SetTexEnv(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD1(ULONG envparam), __REGA2(W3D_Color *envcolor)) {
	W3D_Color *color = (W3D_Color*) malloc(sizeof(W3D_Color));
	logString("W3D_SetTexEnv");
	*color = *envcolor;
	texture->bytesperpix = envparam;
	texture->driver = color;
	return W3D_SUCCESS;
}
ULONG           W3D_SetWrapMode(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD0(ULONG s_mode), __REGD1(ULONG t_mode), __REGA2(W3D_Color *bordercolor)) { logString("W3D_SetWrapMode"); return W3D_SUCCESS; }
ULONG W3D_UpdateTexImage(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGA2(void *teximage), __REGD1(int level), __REGA3(ULONG *palette)) {
	logString("W3D_UpdateTexImage");
	deleteTexture((long)texture->mipmapmask);
	texture->mipmapmask = loadTexture(texture->texsource, texture->texwidth, texture->texheight, formats[texture->texfmtsrc], types[texture->texfmtsrc]);
	return W3D_SUCCESS;
}
ULONG           W3D_UpdateTexSubImage(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGA2(void *teximage), __REGD1(ULONG level), __REGA3(ULONG *palette), __REGA4(W3D_Scissor* scissor), __REGD0(ULONG srcbpr)) { logString("W3D_UpdateTexSubImage"); return W3D_SUCCESS; }
ULONG           W3D_UploadTexture(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture)) { logString("W3D_UploadTexture"); return W3D_SUCCESS; }
ULONG           W3D_FreeAllTexObj(__REGA0(W3D_Context *context)) { logString("W3D_FreeAllTexObj"); return W3D_SUCCESS; }
ULONG           W3D_SetChromaTestBounds(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD0(ULONG rgba_lower), __REGD1(ULONG rgba_upper), __REGD2(ULONG mode)) { logString("W3D_SetChromaTestBounds"); return W3D_SUCCESS; }