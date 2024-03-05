#include "main.h"

/**
 * _strncat - concatenates n characters from the src string to the dest string
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to concatenate
 *
 * Return: Pointer to dest.
 */
char *_strncat(char *dest, char *src, int n)
{
    char *ptr = dest;

    while (*dest)
        dest++;

    while (*src && n--)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return ptr;
}

