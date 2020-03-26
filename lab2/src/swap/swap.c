#include "swap.h"

void Swap(char *left, char *right)
{
	char x = *left;
    *left = *right;
    *right = x;
}

// gcc main.c swap.c -o swap
// ./swap

// gcc -c revert_string.c -o revert_string.o                    
// ar rc libMY_STATIC.a revert_string.o
// ranlib libMY_STATIC.a
// gcc main.c libMY_STATIC.a
// ./a.out milica