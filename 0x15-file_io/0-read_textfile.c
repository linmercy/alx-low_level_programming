#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read
 * @letters: The number of letters to read and print
 *
 * Return: The actual number of letters read and printed, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t bytes_read;
	char buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	bytes_read = 0;
	while (letters > 0 && read(fd, &buffer, 1) == 1)
	{
		if (_putchar(buffer) == -1)
		{
			close(fd);
			return (0);
		}
		bytes_read++;
		letters--;
	}

	close(fd);

	return (bytes_read);
}

