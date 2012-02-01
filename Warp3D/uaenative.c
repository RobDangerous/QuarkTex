#include "uaenative.h"

long ret = 0;

#define UAE_EXEC asm volatile ("moveq #102,d0\njsr 0xf0ffc0\nmove.l d0,_ret"); return ret;

long DLLopen(__REGA0(volatile char* dll)) {
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

long DLLexec(__REGA0(volatile long func)) {
	UAE_EXEC
}

long DLLexec1(__REGA0(volatile long func), __REGD1(volatile long arg1)) {
	UAE_EXEC
}

long DLLexec2(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2)) {
	UAE_EXEC
}

long DLLexec3(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3)) {
	UAE_EXEC
}

long DLLexec4(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3), __REGD4(volatile long arg4)) {
	UAE_EXEC
}

long DLLexec5(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3), __REGD4(volatile long arg4), __REGD5(volatile long arg5)) {
	UAE_EXEC
}

long DLLexec6(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3), __REGD4(volatile long arg4), __REGD5(volatile long arg5), __REGD6(volatile long arg6)) {
	UAE_EXEC
}

float a1, a2, a3, a4;

long DLLexec1f(__REGA0(volatile long func), volatile double arg1) {
	a1 = (float) arg1;
	asm volatile ("
		move.l _a1,d1
	
		moveq #102,d0
		jsr 0xf0ffc0
		move.l d0,_ret

	");
	return ret;
}

long DLLexec2f(__REGA0(volatile long func), volatile double arg1, volatile double arg2) {
	a1 = (float) arg1;
	a2 = (float) arg2;
	asm volatile ("
		move.l d2,-(a7)
		move.l _a1,d1
		move.l _a2,d2
	
		moveq #102,d0
		jsr 0xf0ffc0
		move.l d0,_ret

		move.l (a7)+,d2
	");
	return ret;
}

long DLLexec3f(__REGA0(volatile long func), volatile double arg1, volatile double arg2, volatile double arg3) {
	a1 = (float) arg1;
	a2 = (float) arg2;
	a3 = (float) arg3;
	asm volatile ("
		movem.l d2/d3,-(a7)
		move.l _a1,d1
		move.l _a2,d2
		move.l _a3,d3
	
		moveq #102,d0
		jsr 0xf0ffc0
		move.l d0,_ret

		movem.l (a7)+,d2/d3
	");
	return ret;
}

long DLLexec4f(__REGA0(volatile long func), volatile double arg1, volatile double arg2, volatile double arg3, volatile double arg4) {
	a1 = (float) arg1;
	a2 = (float) arg2;
	a3 = (float) arg3;
	a4 = (float) arg4;
	asm volatile ("
		movem.l d2-d4,-(a7)
		move.l _a1,d1
		move.l _a2,d2
		move.l _a3,d3
		move.l _a4,d4
	
		moveq #102,d0
		jsr 0xf0ffc0
		move.l d0,_ret

		movem.l (a7)+,d2-d4
	");
	return ret;
}

long DLLexecif(__REGA0(volatile long func), __REGD1(volatile long arg1), volatile double arg2) {
	a2 = (float) arg2;
	asm volatile ("
		move.l d2,-(a7)
		move.l _a2,d2
	
		moveq #102,d0
		jsr 0xf0ffc0
		move.l d0,_ret

		move.l (a7)+,d2
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