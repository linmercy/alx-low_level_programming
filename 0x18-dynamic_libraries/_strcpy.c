#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, char *src)
{
    char *ptr = dest;

    while ((*dest++ = *src++))
        ;

    return ptr;
}

