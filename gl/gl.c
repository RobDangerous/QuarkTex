#include "gl.h"

static unsigned long
#include "glstatichandles.auto.c"
create, move, free, swap;
static long w3d, gl, log;
long memoffset;
double fp0, fp1, fp2, fp3, fp4, fp5, fp6, fp7;
long a5;
int ret;
char *bp, b;
int i;

long memOffset(void) {
	asm volatile ("
		moveq #105,d0
		jsr 0xf0ffc0
		move.l d0,_ret
	");
	return ret;
}

char* blub = "opengl32.dll";

long DLLopen(char* dll __asm("a0")) {
	asm volatile ("
		moveq #100,d0
		jsr 0xf0ffc0
		move.l d0,_ret
	");
	return ret;
}

long DLLfunc(__REGD1(volatile long dll), __REGA0(volatile char* func)) {
	asm volatile ("
		moveq #101,d0
		jsr 0xf0ffc0
		move.l d0,_ret
	");
	return ret;
}

long DLLclose(__REGD1(volatile long dll)) {
	asm volatile ("
		moveq #103,d0
		jsr 0xf0ffc0
		move.l d0,_ret
	");
	return ret;
}

void glInit(void) {
	memoffset = memOffset();
	w3d = DLLopen("alib\\QuarkTex.alib");
	if (!w3d) w3d = DLLopen("winuae_dll\\QuarkTex.alib");
	if (!w3d) w3d = DLLopen("QuarkTex.alib");

	create = DLLfunc(w3d, "createContext");
	move = DLLfunc(w3d, "moveWindow");
	free = DLLfunc(w3d, "freeContext");
	swap = DLLfunc(w3d, "swapBuffers");
	log = DLLfunc(w3d, "logString");
	gl = DLLopen("opengl32.dll");

	#include "glDLLfunc.auto.c"
}

void glExit(void) {
	DLLclose(gl);
	DLLclose(w3d);
}

#define EXEC(func) asm volatile ("move.l %0,a0\nmoveq #102,d0\njsr 0xf0ffc0" : : "g" (func))
#define EXEC_RET(func) asm volatile ("move.l %0,a0\nmoveq #102,d0\njsr 0xf0ffc0\nmove.l d0,_ret" : : "g" (func))

void createContext(int left __asm("d1"), int top __asm("d2"), int width __asm("d3"), int height __asm("d4")) { EXEC(create); }
void moveWindow(int left __asm("d1"), int top __asm("d2"), int width __asm("d3"), int height __asm("d4")) { EXEC(move); }
void freeContext(void) { EXEC(free); }
void swapBuffers(void) { EXEC(swap); }
void logString(char* c __asm("d1")) { EXEC(log); }

#include "gldefinitions.auto.c"