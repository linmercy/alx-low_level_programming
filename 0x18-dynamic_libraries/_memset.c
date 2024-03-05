#include "main.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by s
 * with the constant byte b
 * @s: Pointer to memory area
 * @b: Value to set
 * @n: Number of bytes to fill
 *
 * Return: Pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
    char *ptr = s;

    while (n--)
    {
        *s = b;
        s++;
    }

    return ptr;
}

