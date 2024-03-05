#include "main.h"

/**
 * _strlen - computes the length of a string
 * @s: The string to compute
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len] != '\0')
        len++;

    return len;
}

