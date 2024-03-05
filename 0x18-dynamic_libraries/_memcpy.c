#include "main.h"

/**
 * _memcpy - copies n bytes from memory area src to memory area dest
 * @dest: Destination memory area
 * @src: Source memory area
 * @n: Number of bytes to copy
 *
 * Return: Pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
    char *ptr = dest;

    while (n--)
    {
        *dest = *src;
        dest++;
        src++;
    }

    return ptr;
}

