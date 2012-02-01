#include "../gl/gl.h"

void glFeedbackBuffer(GLsizei size __asm("d0"), GLenum type __asm("d1"), GLfloat *buffer __asm("a0")) {
	LOG;
	PUSHREGS;
	_glFeedbackBuffer(size, type, memoffset + (long) buffer);
	SWAP32(buffer, size);
	POPREGS;
}
void glPassThrough(GLfloat token __asm("fp0")) { LOG; PUSHREGS; _glPassThrough(token); POPREGS; }
void glSelectBuffer(GLsizei size __asm("d0"), GLuint *buffer __asm("a0")) {
	LOG;
	PUSHREGS;
	_glSelectBuffer(size, memoffset + (long) buffer);
	SWAP32(buffer, size);
	POPREGS;
}
void glInitNames(void) { LOG; PUSHREGS; _glInitNames(); POPREGS; }
void glLoadName(GLuint name __asm("d0")) { LOG; PUSHREGS; _glLoadName(name); POPREGS; }
void glPushName(GLuint name __asm("d0")) { LOG; PUSHREGS; _glPushName(name); POPREGS; }
void glPopName(void) { LOG; PUSHREGS; _glPopName(); POPREGS; }