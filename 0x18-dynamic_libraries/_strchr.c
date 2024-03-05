#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates the first occurrence of the character c in the string s
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: Pointer to the first occurrence of c in s, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
    while (*s)
    {
        if (*s == c)
            return s;
        s++;
    }

    if (c == '\0')
        return s;

    return NULL;
}

