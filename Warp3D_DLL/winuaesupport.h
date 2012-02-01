#ifndef _WINUAE_SUPPORT_
#define _WINUAE_SUPPORT_

#include <windows.h>

typedef unsigned int uae_u16;
typedef int uae_s16;
typedef unsigned long uae_u32;
typedef long uae_s32;
typedef unsigned char uae_u8;
typedef signed char uae_s8;

struct winuae        //this struct is put in a6 if you call 
	                 //execute native function
{  
	HWND			amigawnd;    //adress of amiga Window Windows Handle
    unsigned int    changenum;   //number to detect screen close/open 
    unsigned int    z3offset;    //the offset to add to acsess Z3 mem from Dll side
    int				causeint6;   //if set a interrupt Level 6 is 
	                             //generate for 68k side
	long            (*call68k)(); //Call: (*uaepar->call68k)(par ....)    
};

//extern winuae* uaepar;

//BOOL screenlost(void);
uae_u32 get_long(uae_u32 *a);
uae_u16 get_word(uae_u16 *a);
void put_long(uae_u32 *a, uae_u32 v);
void put_word(uae_u16 *a, uae_u16 v);

#endif