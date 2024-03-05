#include "main.h"

/**
 * _strspn - calculates the length of the initial segment of s which
 * consists entirely of characters in accept
 * @s: The string to search
 * @accept: The string containing the characters to match
 *
 * Return: The number of bytes in the initial segment of s which consist
 * only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int found;

    while (*s)
    {
        found = 0;
        while (*accept)
        {
            if (*s == *accept)
            {
                count++;
                found = 1;
                break;
            }
            accept++;
        }
        if (found == 0)
            break;
        s++;
        accept -= count;
    }

    return count;
}

