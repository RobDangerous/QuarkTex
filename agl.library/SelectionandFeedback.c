#include "../gl/gl.h"

void glFeedbackBuffer(GLsizei size __asm("d0"), GLenum type __asm("d1"), GLfloat *buffer __asm("a0")) {
	LOG;
	_glFeedbackBuffer(size, type, memoffset + (long) buffer);
	SWAP32(buffer, size);
}
void glPassThrough(GLfloat token __asm("fp0")) { LOG; _glPassThrough(token); }
void glSelectBuffer(GLsizei size __asm("d0"), GLuint *buffer __asm("a0")) {
	LOG;
	_glSelectBuffer(size, memoffset + (long) buffer);
	SWAP32(buffer, size);
}
void glInitNames(void) { LOG; _glInitNames(); }
void glLoadName(GLuint name __asm("d0")) { LOG; _glLoadName(name); }
void glPushName(GLuint name __asm("d0")) { LOG; _glPushName(name); }
void glPopName(void) { LOG; _glPopName(); }