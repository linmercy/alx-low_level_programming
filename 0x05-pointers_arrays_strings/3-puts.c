#include "main.h"

/**
 * _puts-prints a string, followed by a new line,to stdout
 * @str: string to print
 */
i
void _put(char *str)
{
	while (*str != '\0')
	{
		_putchart(*str++);
	}
	_putchart('\n');
}
