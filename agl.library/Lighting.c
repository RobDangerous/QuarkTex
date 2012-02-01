#include "../gl/gl.h"

void glShadeModel(GLenum mode __asm("d0")) { LOG; PUSHREGS; _glShadeModel(mode); POPREGS; }
void glLightf(GLenum light __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glLightf(light, pname, param); POPREGS; }
void glLighti(GLenum light __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; PUSHREGS; _glLighti(light, pname, param); POPREGS; }
void glLightfv(GLenum light __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_POSITION:
		SWAP32(params, 4);
		break;
	case GL_SPOT_DIRECTION:
		SWAP32(params, 3);
		break;
	case GL_SPOT_EXPONENT:
	case GL_SPOT_CUTOFF:
	case GL_CONSTANT_ATTENUATION:
	case GL_LINEAR_ATTENUATION:
	case GL_QUADRATIC_ATTENUATION:
		SWAP32(params, 1);
		break;
	}
	_glLightfv(light, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_POSITION:
		SWAP32(params, 4);
		break;
	case GL_SPOT_DIRECTION:
		SWAP32(params, 3);
		break;
	case GL_SPOT_EXPONENT:
	case GL_SPOT_CUTOFF:
	case GL_CONSTANT_ATTENUATION:
	case GL_LINEAR_ATTENUATION:
	case GL_QUADRATIC_ATTENUATION:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glLightiv(GLenum light __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_POSITION:
		SWAP32(params, 4);
		break;
	case GL_SPOT_DIRECTION:
		SWAP32(params, 3);
		break;
	case GL_SPOT_EXPONENT:
	case GL_SPOT_CUTOFF:
	case GL_CONSTANT_ATTENUATION:
	case GL_LINEAR_ATTENUATION:
	case GL_QUADRATIC_ATTENUATION:
		SWAP32(params, 1);
		break;
	}
	_glLightiv(light, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_POSITION:
		SWAP32(params, 4);
		break;
	case GL_SPOT_DIRECTION:
		SWAP32(params, 3);
		break;
	case GL_SPOT_EXPONENT:
	case GL_SPOT_CUTOFF:
	case GL_CONSTANT_ATTENUATION:
	case GL_LINEAR_ATTENUATION:
	case GL_QUADRATIC_ATTENUATION:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glGetLightfv(GLenum light __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	PUSHREGS;
	_glGetLightfv(light, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_POSITION:
		SWAP32(params, 4);
		break;
	case GL_SPOT_DIRECTION:
		SWAP32(params, 3);
		break;
	case GL_SPOT_EXPONENT:
	case GL_SPOT_CUTOFF:
	case GL_CONSTANT_ATTENUATION:
	case GL_LINEAR_ATTENUATION:
	case GL_QUADRATIC_ATTENUATION:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glGetLightiv(GLenum light __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	PUSHREGS;
	_glGetLightiv(light, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_POSITION:
		SWAP32(params, 4);
		break;
	case GL_SPOT_DIRECTION:
		SWAP32(params, 3);
		break;
	case GL_SPOT_EXPONENT:
	case GL_SPOT_CUTOFF:
	case GL_CONSTANT_ATTENUATION:
	case GL_LINEAR_ATTENUATION:
	case GL_QUADRATIC_ATTENUATION:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glLightModelf(GLenum pname __asm("d0"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glLightModelf(pname, param); POPREGS; }
void glLightModeli(GLenum pname __asm("d0"), GLint param __asm("d1")) { LOG; PUSHREGS; _glLightModeli(pname, param); POPREGS; }
void glLightModelfv(GLenum pname __asm("d0"), GLfloat *params __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (pname) {
	case GL_LIGHT_MODEL_AMBIENT:
		SWAP32(params, 4);
		break;
	case GL_LIGHT_MODEL_LOCAL_VIEWER:
	case GL_LIGHT_MODEL_TWO_SIDE:
		SWAP32(params, 1);
		break;
	}
	_glLightModelfv(pname, memoffset + (long) params);
	switch (pname) {
	case GL_LIGHT_MODEL_AMBIENT:
		SWAP32(params, 4);
		break;
	case GL_LIGHT_MODEL_LOCAL_VIEWER:
	case GL_LIGHT_MODEL_TWO_SIDE:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glLightModeliv(GLenum pname __asm("d0"), GLint *params __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (pname) {
	case GL_LIGHT_MODEL_AMBIENT:
		SWAP32(params, 4);
		break;
	case GL_LIGHT_MODEL_LOCAL_VIEWER:
	case GL_LIGHT_MODEL_TWO_SIDE:
		SWAP32(params, 1);
		break;
	}
	_glLightModeliv(pname, memoffset + (long) params);
	switch (pname) {
	case GL_LIGHT_MODEL_AMBIENT:
		SWAP32(params, 4);
		break;
	case GL_LIGHT_MODEL_LOCAL_VIEWER:
	case GL_LIGHT_MODEL_TWO_SIDE:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glMaterialf(GLenum face __asm("d0"), GLenum pname __asm("d1"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glMaterialf(face, pname, param); POPREGS; }
void glMateriali(GLenum face __asm("d0"), GLenum pname __asm("d1"), GLint param __asm("d2")) { LOG; PUSHREGS; _glMateriali(face, pname, param); POPREGS; }
void glMaterialfv(GLenum face __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_EMISSION:
	case GL_AMBIENT_AND_DIFFUSE:
		SWAP32(params, 4);
		break;
	case GL_COLOR_INDEXES:
		SWAP32(params, 3);
		break;
	case GL_SHININESS:
		SWAP32(params, 1);
		break;
	}
	_glMaterialfv(face, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_EMISSION:
	case GL_AMBIENT_AND_DIFFUSE:
		SWAP32(params, 4);
		break;
	case GL_COLOR_INDEXES:
		SWAP32(params, 3);
		break;
	case GL_SHININESS:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glMaterialiv(GLenum face __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	PUSHREGS;
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_EMISSION:
	case GL_AMBIENT_AND_DIFFUSE:
		SWAP32(params, 4);
		break;
	case GL_COLOR_INDEXES:
		SWAP32(params, 3);
		break;
	case GL_SHININESS:
		SWAP32(params, 1);
		break;
	}
	_glMaterialiv(face, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_EMISSION:
	case GL_AMBIENT_AND_DIFFUSE:
		SWAP32(params, 4);
		break;
	case GL_COLOR_INDEXES:
		SWAP32(params, 3);
		break;
	case GL_SHININESS:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glGetMaterialfv(GLenum face __asm("d0"), GLenum pname __asm("d1"), GLfloat *params __asm("a0")) {
	LOG;
	PUSHREGS;
	_glGetMaterialfv(face, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_EMISSION:
	case GL_AMBIENT_AND_DIFFUSE:
		SWAP32(params, 4);
		break;
	case GL_COLOR_INDEXES:
		SWAP32(params, 3);
		break;
	case GL_SHININESS:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glGetMaterialiv(GLenum face __asm("d0"), GLenum pname __asm("d1"), GLint *params __asm("a0")) {
	LOG;
	PUSHREGS;
	_glGetMaterialiv(face, pname, memoffset + (long) params);
	switch (pname) {
	case GL_AMBIENT:
	case GL_DIFFUSE:
	case GL_SPECULAR:
	case GL_EMISSION:
	case GL_AMBIENT_AND_DIFFUSE:
		SWAP32(params, 4);
		break;
	case GL_COLOR_INDEXES:
		SWAP32(params, 3);
		break;
	case GL_SHININESS:
		SWAP32(params, 1);
		break;
	}
	POPREGS;
}
void glColorMaterial(GLenum face __asm("d0"), GLenum mode __asm("d1")) { LOG; PUSHREGS; _glColorMaterial(face, mode); POPREGS; }