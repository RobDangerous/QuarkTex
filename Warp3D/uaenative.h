#ifndef UAE_NATIVE
#define UAE_NATIVE

#include <exec/libraries.h>

long DLLopen(__REGA0(volatile char* dll));
long DLLfunc(__REGD1(volatile long dll), __REGA0(volatile char* func));
long DLLexec(__REGA0(volatile long func));
long DLLexec1(__REGA0(volatile long func), __REGD1(volatile long arg1));
long DLLexec2(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2));
long DLLexec3(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3));
long DLLexec4(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3), __REGD4(volatile long arg4));
long DLLexec5(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3), __REGD4(volatile long arg4), __REGD5(volatile long arg5));
long DLLexec6(__REGA0(volatile long func), __REGD1(volatile long arg1), __REGD2(volatile long arg2), __REGD3(volatile long arg3), __REGD4(volatile long arg4), __REGD5(volatile long arg5), __REGD6(volatile long arg6));
long DLLexec1f(__REGA0(volatile long func), volatile double arg1);
long DLLexec2f(__REGA0(volatile long func), volatile double arg1, volatile double arg2);
long DLLexec3f(__REGA0(volatile long func), volatile double arg1, volatile double arg2, volatile double arg3);
long DLLexec4f(__REGA0(volatile long func), volatile double arg1, volatile double arg2, volatile double arg3, volatile double arg4);
long DLLexecif(__REGA0(volatile long func), __REGD1(volatile long arg1), volatile double arg2);
long DLLclose(__REGD1(volatile long dll));

#endif