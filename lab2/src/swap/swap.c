#include "swap.h"

void Swap(char *left, char *right)
{
	char x = *left;
    *left = *right;
    *right = x;
}

// gcc main.c swap.c -o swap
// ./swap
