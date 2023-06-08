#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: Pointer to the binary string.
 *
 * Return: The converted number, or 0 if an error occurs.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);
	for (int bit = 0; b[bit] != '\0'; bit++)
	{
		if (b[bit] != '0' && b[bit] != '1')
			return (0);
		result = result * 2 + (b[i] - '0');
	}
	return (result);
}
