#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
    char *ptr = dest;

    while (*dest)
        dest++;

    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';

    return ptr;
}

