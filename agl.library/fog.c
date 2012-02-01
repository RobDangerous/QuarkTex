#include "../gl/gl.h"

void glFogf(GLenum pname __asm("d0"), GLfloat param __asm("fp0")) { LOG; PUSHREGS; _glFogf(pname, param); POPREGS; }
void glFogi(GLenum pname __asm("d0"), GLint param __asm("d1")) { LOG; PUSHREGS; _glFogi(pname, param); POPREGS; }
void glFogfv(GLenum pname __asm("d0"), GLfloat *params __asm("a0")) {
	LOG;
	PUSHREGS;
	if (pname == GL_FOG_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	_glFogfv(pname, memoffset + (long) params);
	if (pname == GL_FOG_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	POPREGS;
}
void glFogiv(GLenum pname __asm("d0"), GLint *params __asm("a0")) {
	LOG;
	PUSHREGS;
	if (pname == GL_FOG_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	_glFogiv(pname, memoffset + (long) params);
	if (pname == GL_FOG_COLOR) { SWAP32(params, 4); }
	else { SWAP32(params, 1); }
	POPREGS;
}