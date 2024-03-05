#include "main.h"

/**
 * _strncpy - copies up to n characters from the src string to the dest string
 * @dest: Destination string
 * @src: Source string
 * @n: Maximum number of characters to copy
 *
 * Return: Pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
    char *ptr = dest;

    while (*src && n--)
    {
        *dest = *src;
        dest++;
        src++;
    }

    while (n--)
    {
        *dest = '\0';
        dest++;
    }

    return ptr;
}

