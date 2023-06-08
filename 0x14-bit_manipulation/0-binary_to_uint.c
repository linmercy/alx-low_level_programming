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
	unsigned int index = 0;

	if (b == NULL)
		return (0);

	while (b[index] != '\0')
	{
		if (b[index] == '0' || b[index] == '1')
		{
			result = result << 1;
			result += b[index] - '0';
			index++;
		}
		else
		{
			return 0;
		}
	}
	return result;
}
