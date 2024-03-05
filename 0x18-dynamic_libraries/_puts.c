#include "main.h"

/**
 * _puts - writes a string to stdout
 * @s: The string to write
 */
void _puts(char *s)
{
    while (*s)
    {
        _putchar(*s);
        s++;
    }
}

