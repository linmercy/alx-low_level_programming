#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: The string to search
 * @needle: The substring to locate
 *
 * Return: Pointer to the beginning of the located substring, or NULL if
 * the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
    while (*haystack)
    {
        char *start = haystack;
        char *substr = needle;

        while (*haystack && *substr && *haystack == *substr)
        {
            haystack++;
            substr++;
        }

        if (!*substr)
            return start;

        haystack = start + 1;
    }

    return NULL;
}

