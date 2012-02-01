#include "winuaesupport.h"
/*
BOOL screenlost(void)
{
static int oldnum=0;

if (uaepar->changenum == oldnum)return 0;
oldnum=uaepar->changenum;return 1;
}
*/
uae_u32 get_long(uae_u32 *a)
{
#ifndef _MSC_VER
    uae_u8 *b = (uae_u8 *)a;
    return (*b << 24) | (*(b+1) << 16) | (*(b+2) << 8) | (*(b+3));
#else
    uae_u32 retval;
    __asm
    {
	mov	eax, a
	mov	ebx, [eax]
	bswap	ebx
	mov	retval, ebx
    }
    return retval;
#endif
}

uae_u16 get_word(uae_u16 *a)
{
    uae_u8 *b = (uae_u8 *)a;
    
    return (*b << 8) | (*(b+1));
}

void put_long(uae_u32 *a, uae_u32 v)
{
#ifndef _MSC_VER
    uae_u8 *b = (uae_u8 *)a;
    
    *b = v >> 24;
    *(b+1) = v >> 16;    
    *(b+2) = v >> 8;
    *(b+3) = v;
#else
    __asm
    {
	mov	eax, a
	mov	ebx, v
	bswap	ebx
	mov	[eax], ebx
    }
#endif
}

void put_word(uae_u16 *a, uae_u16 v)
{
    uae_u8 *b = (uae_u8 *)a;
    
    *b = (uae_u8) (v >> 8);
    *(b+1) = (uae_u8) v;
}