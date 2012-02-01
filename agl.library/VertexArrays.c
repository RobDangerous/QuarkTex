#include "../gl/gl.h"

GLint vertexSize;
GLenum vertexType;
GLsizei vertexStride;
GLvoid *vertexPtr = NULL;

void glVertexPointer(GLint size __asm("d0"), GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLvoid *ptr __asm("a0")) {
	LOG;
	PUSHREGS;
	vertexSize = size;
	vertexType = type;
	vertexStride = stride;
	vertexPtr = ptr;
	_glVertexPointer(size, type, stride, memoffset + (long) ptr);
	POPREGS;
}

inline void vertex(int i) {
	GLshort *sp = NULL;
	GLint *ip = NULL;
	GLfloat *fp = NULL;
	GLdouble *dp = NULL;
	switch (vertexType) {
	case GL_SHORT:
		sp = (GLshort*) (vertexPtr + i * vertexStride);
		switch (vertexSize) {
		case 2: _glVertex2s(sp[0], sp[1]); break;
		case 3: _glVertex3s(sp[0], sp[1], sp[2]); break;
		case 4: _glVertex4s(sp[0], sp[1], sp[2], sp[3]); break;
		}
		break;
	case GL_INT:
		ip = (GLint*) (vertexPtr + i * vertexStride);
		switch (vertexSize) {
		case 2: _glVertex2i(ip[0], ip[1]); break;
		case 3: _glVertex3i(ip[0], ip[1], ip[2]); break;
		case 4: _glVertex4i(ip[0], ip[1], ip[2], ip[3]); break;
		}
		break;
	case GL_FLOAT:
		fp = (GLfloat*) (vertexPtr + i * vertexStride);
		switch (vertexSize) {
		case 2: _glVertex2f(fp[0], fp[1]); break;
		case 3: _glVertex3f(fp[0], fp[1], fp[2]); break;
		case 4: _glVertex4f(fp[0], fp[1], fp[2], fp[3]); break;
		}
		break;
	case GL_DOUBLE:
		dp = (GLdouble*) (vertexPtr + i * vertexStride);
		switch (vertexSize) {
		case 2: _glVertex2d(dp[0], dp[1]); break;
		case 3: _glVertex3d(dp[0], dp[1], dp[2]); break;
		case 4: _glVertex4d(dp[0], dp[1], dp[2], dp[3]); break;
		}
		break;
	}
}

GLenum normalType;
GLsizei normalStride;
GLvoid *normalPtr = NULL;

void glNormalPointer(GLenum type __asm("d0"), GLsizei stride __asm("d1"), GLvoid *ptr __asm("a0")) {
	LOG;
	PUSHREGS;
	normalType = type;
	normalStride = stride;
	normalPtr = ptr;
	_glNormalPointer(type, stride, memoffset + (long) ptr);
	POPREGS;
}

inline void normal(int i) {
	GLbyte *bp = NULL;
	GLshort *sp = NULL;
	GLint *ip = NULL;
	GLfloat *fp = NULL;
	GLdouble *dp = NULL;
	switch (normalType) {
	case GL_BYTE:
		bp = (GLbyte*) (normalPtr + i * normalStride);
		_glNormal3b(bp[0], bp[1], bp[2]);
		break;
	case GL_SHORT:
		sp = (GLshort*) (normalPtr + i * normalStride);
		_glNormal3s(sp[0], sp[1], sp[2]);
		break;
	case GL_INT:
		ip = (GLint*) (normalPtr + i * normalStride);
		_glNormal3i(ip[0], ip[1], ip[2]);
		break;
	case GL_FLOAT:
		fp = (GLfloat*) (normalPtr + i * normalStride);
		_glNormal3f(fp[0], fp[1], fp[2]);
		break;
	case GL_DOUBLE:
		dp = (GLdouble*) (normalPtr + i * normalStride);
		_glNormal3d(dp[0], dp[1], dp[2]);
		break;
	}
}

GLint colorSize;
GLenum colorType;
GLsizei colorStride;
GLvoid *colorPtr = NULL;

void glColorPointer(GLint size __asm("d0"), GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLvoid *ptr __asm("a0")) {
	LOG;
	PUSHREGS;
	colorSize = size;
	colorType = type;
	colorStride = stride;
	colorPtr = ptr;
	_glColorPointer(size, type, stride, memoffset + (long) ptr);
	POPREGS;
}


inline void color(int i) {
	GLbyte *bp = NULL;
	GLubyte *ubp = NULL;
	GLshort *sp = NULL;
	GLushort *usp = NULL;
	GLint *ip = NULL;
	GLuint *uip = NULL;
	GLfloat *fp = NULL;
	GLdouble *dp = NULL;
	switch (colorType) {
	case GL_BYTE:
		bp = (GLbyte*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3b(bp[0], bp[1], bp[2]); break;
		case 4: _glColor4b(bp[0], bp[1], bp[2], bp[3]); break;
		}
		break;
	case GL_UNSIGNED_BYTE:
		ubp = (GLubyte*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3ub(ubp[0], ubp[1], ubp[2]); break;
		case 4: _glColor4ub(ubp[0], ubp[1], ubp[2], ubp[3]); break;
		}
		break;
	case GL_SHORT:
		sp = (GLshort*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3s(sp[0], sp[1], sp[2]); break;
		case 4: _glColor4s(sp[0], sp[1], sp[2], sp[3]); break;
		}
		break;
	case GL_UNSIGNED_SHORT:
		usp = (GLushort*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3us(usp[0], usp[1], usp[2]); break;
		case 4: _glColor4us(usp[0], usp[1], usp[2], usp[3]); break;
		}
		break;
	case GL_INT:
		ip = (GLint*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3i(ip[0], ip[1], ip[2]); break;
		case 4: _glColor4i(ip[0], ip[1], ip[2], ip[3]); break;
		}
		break;
	case GL_UNSIGNED_INT:
		uip = (GLuint*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3ui(uip[0], uip[1], uip[2]); break;
		case 4: _glColor4ui(uip[0], uip[1], uip[2], uip[3]); break;
		}
		break;
	case GL_FLOAT:
		fp = (GLfloat*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3f(fp[0], fp[1], fp[2]); break;
		case 4: _glColor4f(fp[0], fp[1], fp[2], fp[3]); break;
		}
		break;
	case GL_DOUBLE:
		dp = (GLdouble*) (colorPtr + i * colorStride);
		switch (colorSize) {
		case 3: _glColor3d(dp[0], dp[1], dp[2]); break;
		case 4: _glColor4d(dp[0], dp[1], dp[2], dp[3]); break;
		}
		break;
	}
}

GLenum indexType;
GLsizei indexStride;
GLvoid *indexPtr = NULL;

void glIndexPointer(GLenum type __asm("d0"), GLsizei stride __asm("d1"), GLvoid *ptr __asm("a0")) {
	LOG;
	PUSHREGS;
	indexType = type;
	indexStride = stride;
	indexPtr = ptr;
	_glIndexPointer(type, stride, memoffset + (long) ptr);
	POPREGS;
}

inline void index(int i) {
	GLubyte *ubp = NULL;
	GLshort *sp = NULL;
	GLint *ip = NULL;
	GLfloat *fp = NULL;
	GLdouble *dp = NULL;
	switch (indexType) {
	case GL_UNSIGNED_BYTE:
		ubp = (GLubyte*) (indexPtr + i * indexStride);
		_glIndexub(bp[0]);
		break;
	case GL_SHORT:
		sp = (GLshort*) (indexPtr + i * indexStride);
		_glIndexs(sp[0]);
		break;
	case GL_INT:
		ip = (GLint*) (indexPtr + i * indexStride);
		_glIndexi(ip[0]);
		break;
	case GL_FLOAT:
		fp = (GLfloat*) (indexPtr + i * indexStride);
		_glIndexf(fp[0]);
		break;
	case GL_DOUBLE:
		dp = (GLdouble*) (indexPtr + i * indexStride);
		_glIndexd(dp[0]);
		break;
	}
}

GLint texCoordSize;
GLenum texCoordType;
GLsizei texCoordStride;
GLvoid *texCoordPtr = NULL;

void glTexCoordPointer(GLint size __asm("d0"), GLenum type __asm("d1"), GLsizei stride __asm("d2"), GLvoid *ptr __asm("a0")) {
	LOG;
	PUSHREGS;
	texCoordSize = size;
	texCoordType = type;
	texCoordStride = stride;
	texCoordPtr = ptr;
	_glTexCoordPointer(size, type, stride, memoffset + (long) ptr);
	POPREGS;
}

inline void texCoord(int i) {
	GLshort *sp = NULL;
	GLint *ip = NULL;
	GLfloat *fp = NULL;
	GLdouble *dp = NULL;
	switch (texCoordType) {
	case GL_SHORT:
		sp = (GLshort*) (texCoordPtr + i * texCoordStride);
		switch (texCoordSize) {
		case 1: _glTexCoord1s(sp[0]); break;
		case 2: _glTexCoord2s(sp[0], sp[1]); break;
		case 3: _glTexCoord3s(sp[0], sp[1], sp[2]); break;
		case 4: _glTexCoord4s(sp[0], sp[1], sp[2], sp[3]); break;
		}
		break;
	case GL_INT:
		ip = (GLint*) (texCoordPtr + i * texCoordStride);
		switch (texCoordSize) {
		case 1: _glTexCoord1i(ip[0]); break;
		case 2: _glTexCoord2i(ip[0], ip[1]); break;
		case 3: _glTexCoord3i(ip[0], ip[1], ip[2]); break;
		case 4: _glTexCoord4i(ip[0], ip[1], ip[2], ip[3]); break;
		}
		break;
	case GL_FLOAT:
		fp = (GLfloat*) (texCoordPtr + i * texCoordStride);
		switch (texCoordSize) {
		case 1: _glTexCoord1f(fp[0]); break;
		case 2: _glTexCoord2f(fp[0], fp[1]); break;
		case 3: _glTexCoord3f(fp[0], fp[1], fp[2]); break;
		case 4: _glTexCoord4f(fp[0], fp[1], fp[2], fp[3]); break;
		}
		break;
	case GL_DOUBLE:
		dp = (GLdouble*) (texCoordPtr + i * texCoordStride);
		switch (texCoordSize) {
		case 1: _glTexCoord1d(dp[0]); break;
		case 2: _glTexCoord2d(dp[0], dp[1]); break;
		case 3: _glTexCoord3d(dp[0], dp[1], dp[2]); break;
		case 4: _glTexCoord4d(dp[0], dp[1], dp[2], dp[3]); break;
		}
		break;
	}
}

GLsizei edgeFlagStride;
GLboolean *edgeFlagPtr = NULL;
void glEdgeFlagPointer(GLsizei stride __asm("d0"), GLboolean *ptr __asm("a0")) {
	LOG;
	PUSHREGS;
	edgeFlagStride = stride;
	edgeFlagPtr = ptr;
	_glEdgeFlagPointer(stride, memoffset + (long) ptr);
	POPREGS;
}

inline void edgeFlag(int i) {
	GLboolean *bp = (GLboolean*) (edgeFlagPtr + i * edgeFlagStride);
	_glEdgeFlag(bp[0]);
}

void glGetPointerv(GLenum pname __asm("d0"), GLvoid *params __asm("a0")) {
	LOG;
	PUSHREGS;
	_glGetPointerv(pname, memoffset + (long) params);
	SWAP32(params, 1);
	POPREGS;
}
void glArrayElement(GLint i __asm("d0")) {
	LOG;
	PUSHREGS;
	if (_glIsEnabled(GL_EDGE_FLAG_ARRAY)) edgeFlag(i);
	if (_glIsEnabled(GL_TEXTURE_COORD_ARRAY)) texCoord(i);
	if (_glIsEnabled(GL_INDEX_ARRAY)) index(i);
	if (_glIsEnabled(GL_COLOR_ARRAY)) color(i);
	if (_glIsEnabled(GL_NORMAL_ARRAY)) normal(i);
	if (_glIsEnabled(GL_VERTEX_ARRAY)) vertex(i);
	POPREGS;
}

void glDrawArrays(GLenum mode __asm("d0"), GLint first __asm("d1"), GLsizei count __asm("d2")) {
	int i;
	GLboolean edgeFlagOn = _glIsEnabled(GL_EDGE_FLAG_ARRAY);
	GLboolean texCoordOn = _glIsEnabled(GL_TEXTURE_COORD_ARRAY);
	GLboolean indexOn = _glIsEnabled(GL_INDEX_ARRAY);
	GLboolean colorOn = _glIsEnabled(GL_COLOR_ARRAY);
	GLboolean normalOn = _glIsEnabled(GL_NORMAL_ARRAY);
	GLboolean vertexOn = _glIsEnabled(GL_VERTEX_ARRAY);
	LOG;
	PUSHREGS;
	_glBegin(mode);
	for (i = first; i < first + count; ++i) {
		if (edgeFlagOn) edgeFlag(i);
		if (texCoordOn) texCoord(i);
		if (indexOn) index(i);
		if (colorOn) color(i);
		if (normalOn) normal(i);
		if (vertexOn) vertex(i);
	}
	_glEnd();
	POPREGS;
}

void glDrawElements(GLenum mode __asm("d0"), GLsizei count __asm("d1"), GLenum type __asm("d2"), GLvoid *indices __asm("a0")) {
	GLubyte *ubp = NULL;
	GLushort *usp = NULL;
	GLuint *uip = NULL;
	int i;
	GLboolean edgeFlagOn = _glIsEnabled(GL_EDGE_FLAG_ARRAY);
	GLboolean texCoordOn = _glIsEnabled(GL_TEXTURE_COORD_ARRAY);
	GLboolean indexOn = _glIsEnabled(GL_INDEX_ARRAY);
	GLboolean colorOn = _glIsEnabled(GL_COLOR_ARRAY);
	GLboolean normalOn = _glIsEnabled(GL_NORMAL_ARRAY);
	GLboolean vertexOn = _glIsEnabled(GL_VERTEX_ARRAY);
	LOG;
	PUSHREGS;
	_glBegin(mode);
	switch (type) {
	case GL_UNSIGNED_BYTE:
		ubp = (GLubyte*) indices;
		for (i = 0; i < count; ++i) {
			if (edgeFlagOn) edgeFlag(ubp[i]);
			if (texCoordOn) texCoord(ubp[i]);
			if (indexOn) index(ubp[i]);
			if (colorOn) color(ubp[i]);
			if (normalOn) normal(ubp[i]);
			if (vertexOn) vertex(ubp[i]);
		}
		break;
	case GL_UNSIGNED_SHORT:
		usp = (GLushort*) indices;
		for (i = 0; i < count; ++i) {
			if (edgeFlagOn) edgeFlag(usp[i]);
			if (texCoordOn) texCoord(usp[i]);
			if (indexOn) index(usp[i]);
			if (colorOn) color(usp[i]);
			if (normalOn) normal(usp[i]);
			if (vertexOn) vertex(usp[i]);
		}
		break;
	case GL_UNSIGNED_INT:
		uip = (GLuint*) indices;
		for (i = 0; i < count; ++i) {
			if (edgeFlagOn) edgeFlag(uip[i]);
			if (texCoordOn) texCoord(uip[i]);
			if (indexOn) index(uip[i]);
			if (colorOn) color(uip[i]);
			if (normalOn) normal(uip[i]);
			if (vertexOn) vertex(uip[i]);
		}
		break;
	}
	_glEnd();
	POPREGS;
}
void glInterleavedArrays(GLenum format __asm("d0"), GLsizei stride __asm("d1"), GLvoid *pointer __asm("a0")) {
	LOG;
	//_glInterleavedArrays(format, stride, pointer);
}