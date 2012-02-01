#ifndef UAE_GL
#define UAE_GL

typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

void glInit(void);
void glExit(void);
void createContext(int left __asm("d1"), int top __asm("d2"), int width __asm("d3"), int height __asm("d4"));
void moveWindow(int left __asm("d1"), int top __asm("d2"), int width __asm("d3"), int height __asm("d4"));
void freeContext(void);
void swapBuffers(void);
void logString(char* c __asm("d1"));

#include "gldefines.h"
#include "gldeclarations.auto.h"

#include <exec/libraries.h>

extern long memoffset;
extern char *bp, b;
extern int i;

#define LOG /*												\
	logString((char*) (memoffset + (int)(__FILE__)));	\
	logString((char*) (memoffset + (int)(": ")));		\
	logString((char*) (memoffset + (int)(__FUNC__)));	\
	logString((char*) (memoffset + (int)("\n")))*/

#define SWAP16(array, count)		\
	for (i = 0; i < (count); ++i) {	\
		bp = (char*) &array[i];		\
		b = bp[0];					\
		bp[0] = bp[1];				\
		bp[1] = b;					\
	}

#define SWAP32(array, count)		\
	for (i = 0; i < (count); ++i) {	\
		bp = (char*) &array[i];		\
		b = bp[0];					\
		bp[0] = bp[3];				\
		bp[3] = b;					\
		b = bp[1];					\
		bp[1] = bp[2];				\
		bp[2] = b;					\
	}

#define SWAP64(array, count)		\
	for (i = 0; i < (count); ++i) {	\
		bp = (char*) &array[i];		\
		b = bp[0];					\
		bp[0] = bp[7];				\
		bp[7] = b;					\
		b = bp[1];					\
		bp[1] = bp[6];				\
		bp[6] = b;					\
		b = bp[2];					\
		bp[2] = bp[5];				\
		bp[5] = b;					\
		b = bp[3];					\
		bp[3] = bp[4];				\
		bp[4] = b;					\
	}

//#define PUSHREGS
//#define POPREGS
//#define PUSHREGS __asm("movem.l a2-a6/d2-d7,-(a7)"); __asm("fmovem.x fp0-fp7,-(a7)")
//#define POPREGS __asm("fmovem.x (a7)+,fp0-fp7"); __asm("movem.l (a7)+,a2-a6/d2-d7")
//#define PUSHREGS __asm("movem.l a2-a6/d2-d7,-(a7)")
//#define POPREGS __asm("movem.l (a7)+,a2-a6/d2-d7")

#endif