#include "main.h"
/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * @b: Pointer to a string of 0 and 1 chars
 *
 * Return: The converted number, or 0 if there is one or more chars in the
 * string b that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b) {
	if (b == NULL)
		return 0;
	unsigned int result = 0;
	while (*b) {
		if (*b == '0' || *b == '1') {
			result = result * 2 + (*b - '0');
			b++;
		} else {
			return 0;
		}
	}
	return result;
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, 1. On error, -1 is returned.
 */
int _putchar(char c) {
	return write(1, &c, 1);
}
