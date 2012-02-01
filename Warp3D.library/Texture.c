#include "w3d.h"

/*
struct Node {
    struct  Node *ln_Succ;	// Pointer to next (successor)
    struct  Node *ln_Pred;	// Pointer to previous (predecessor)
    UBYTE   ln_Type;
    BYTE    ln_Pri;		// Priority, for sorting
    char    *ln_Name;		// ID string, null terminated
};
*/

struct Node* firstTex = NULL;

long swap[] = {0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0};
unsigned formats[] = {0, GL_COLOR_INDEX, GL_BGRA, GL_RGB, GL_RGB, GL_BGRA, GL_BGRA, GL_ALPHA, GL_LUMINANCE, GL_LUMINANCE_ALPHA, GL_INTENSITY, GL_RGBA};
unsigned types[] = {0, GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_1_5_5_5_REV, GL_UNSIGNED_SHORT_5_6_5, GL_UNSIGNED_BYTE, GL_UNSIGNED_SHORT_4_4_4_4_REV,
		GL_UNSIGNED_INT_8_8_8_8_REV, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE, GL_UNSIGNED_BYTE};
long filter[] = {0, GL_NEAREST, GL_LINEAR, GL_NEAREST_MIPMAP_NEAREST, GL_NEAREST_MIPMAP_LINEAR, GL_LINEAR_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_LINEAR};
long wrap[] = {0, GL_REPEAT, GL_CLAMP };

W3D_Texture *W3D_AllocTexObj(__REGA0(W3D_Context *context), __REGA1(ULONG *error), __REGA2(struct TagItem *ATOTags)) {
	W3D_Texture *tex;
	LOG
	tex = (W3D_Texture*) malloc(sizeof(W3D_Texture));

	if (!firstTex) {
		firstTex = (struct Node*) tex;
		tex->link.ln_Pred = NULL;
		tex->link.ln_Succ = NULL;
	}
	else {
		tex->link.ln_Pred = NULL;
		tex->link.ln_Succ = firstTex;
		firstTex->ln_Pred = &tex->link;
		firstTex = &tex->link;
	}
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
	if (swap[tex->texfmtsrc]) _glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_TRUE);
	else _glPixelStorei(GL_UNPACK_SWAP_BYTES, GL_FALSE);
	tex->driver = malloc(sizeof(Texture));

	((Texture*) tex->driver)->envparam = 0;
	((Texture*) tex->driver)->envcolor.r = 0; ((Texture*) tex->driver)->envcolor.g = 0; ((Texture*) tex->driver)->envcolor.b = 0; ((Texture*) tex->driver)->envcolor.a = 0;
	((Texture*) tex->driver)->MinFilter = 0; ((Texture*) tex->driver)->MagFilter = 0;
	((Texture*) tex->driver)->s_mode = 0; ((Texture*) tex->driver)->t_mode = 0;
	((Texture*) tex->driver)->bordercolor.r = 0; ((Texture*) tex->driver)->bordercolor.g = 0; ((Texture*) tex->driver)->bordercolor.b = 0; ((Texture*) tex->driver)->bordercolor.a = 0;

	_glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	_glGenTextures(1, (GLuint*) (memoffset + (long) &((Texture*) tex->driver)->glID));
	_glBindTexture(GL_TEXTURE_2D, (((Texture*) tex->driver)->glID));

	_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	_glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	_glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tex->texwidth, tex->texheight, 0, formats[tex->texfmtsrc], types[tex->texfmtsrc], (void*) (memoffset + (long) tex->texsource));

	if (error) *error = W3D_SUCCESS;
	return tex;
}
void W3D_FreeTexObj(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture)) {
	LOG
	if (texture->link.ln_Pred == NULL) { firstTex = texture->link.ln_Succ; if (firstTex != NULL) firstTex->ln_Pred = NULL; }
	if (texture->link.ln_Succ == NULL && texture->link.ln_Pred != NULL) texture->link.ln_Pred->ln_Succ = NULL;
	if (texture->link.ln_Pred != NULL && texture->link.ln_Succ != NULL) {
		(texture->link.ln_Pred)->ln_Succ = texture->link.ln_Succ;
		(texture->link.ln_Succ)->ln_Pred = texture->link.ln_Pred;
	}
	if (((Texture*) texture->driver)->glID) _glDeleteTextures(1, (GLuint*) (memoffset + (long) &((Texture*) texture->driver)->glID));
	free(texture->driver);
	free(texture);
}
void W3D_ReleaseTexture(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture)) {
	//free from video RAM
	LOG
}
void W3D_FlushTextures(__REGA0(W3D_Context *context)) {
	//Release all textures from video ram
	LOG
}
ULONG W3D_SetFilter(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD0(ULONG MinFilter), __REGD1(ULONG MagFilter)) {
	LOG
	((Texture*) texture->driver)->MinFilter = filter[MinFilter];
	((Texture*) texture->driver)->MagFilter = filter[MagFilter];
	return W3D_SUCCESS;
}
ULONG W3D_SetTexEnv(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD1(ULONG envparam), __REGA2(W3D_Color *envcolor)) {
	W3D_Color *color = (W3D_Color*) malloc(sizeof(W3D_Color));
	LOG
	*color = *envcolor;
	((Texture*) texture->driver)->envparam = envparam;
	((Texture*) texture->driver)->envcolor.r = color->r;
	((Texture*) texture->driver)->envcolor.g = color->g;
	((Texture*) texture->driver)->envcolor.b = color->b;
	((Texture*) texture->driver)->envcolor.a = color->a;
	return W3D_SUCCESS;
}
ULONG W3D_SetWrapMode(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD0(ULONG s_mode), __REGD1(ULONG t_mode), __REGA2(W3D_Color *bordercolor)) {
	LOG
	((Texture*) texture->driver)->s_mode = wrap[s_mode];
	((Texture*) texture->driver)->t_mode = wrap[t_mode];
	((Texture*) texture->driver)->bordercolor.r = bordercolor->r;
	((Texture*) texture->driver)->bordercolor.g = bordercolor->g;
	((Texture*) texture->driver)->bordercolor.b = bordercolor->b;
	((Texture*) texture->driver)->bordercolor.a = bordercolor->a;
	return W3D_SUCCESS;
}
ULONG W3D_UpdateTexImage(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGA2(void *teximage), __REGD1(int level), __REGA3(ULONG *palette)) {
	LOG
	texture->texsource = teximage;
	_glBindTexture(GL_TEXTURE_2D, ((Texture*) texture->driver)->glID);
    _glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, texture->texwidth, texture->texheight, formats[texture->texfmtsrc], types[texture->texfmtsrc], (void*) (memoffset + (int) texture->texsource));
	return W3D_SUCCESS;
}
ULONG W3D_UpdateTexSubImage(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGA2(void *teximage), __REGD1(ULONG level), __REGA3(ULONG *palette), __REGA4(W3D_Scissor* scissor), __REGD0(ULONG srcbpr)) {
	LOG
	if (srcbpr == 0) {
		_glBindTexture(GL_TEXTURE_2D, ((Texture*) texture->driver)->glID);
		_glTexSubImage2D(GL_TEXTURE_2D, 0, scissor->left, scissor->top, scissor->width, scissor->height, formats[texture->texfmtsrc], types[texture->texfmtsrc], (void*) (memoffset + (int) texture->texsource));
	}
	return W3D_SUCCESS;
}
ULONG W3D_UploadTexture(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture)) { LOG return W3D_SUCCESS; }
ULONG W3D_FreeAllTexObj(__REGA0(W3D_Context *context)) {
	W3D_Texture *n;
	LOG
	for (n = (W3D_Texture*) firstTex; n != NULL;) {
		if (((Texture*) n->driver)->glID) _glDeleteTextures(1, (GLuint*) (memoffset + (long) &((Texture*) n->driver)->glID));
		n = (W3D_Texture*) n->link.ln_Succ;
		free(n->driver);
		free(n);
	}
	firstTex = NULL;
	return W3D_SUCCESS;
}
ULONG W3D_SetChromaTestBounds(__REGA0(W3D_Context *context), __REGA1(W3D_Texture *texture), __REGD0(ULONG rgba_lower), __REGD1(ULONG rgba_upper), __REGD2(ULONG mode)) { LOG return W3D_SUCCESS; }