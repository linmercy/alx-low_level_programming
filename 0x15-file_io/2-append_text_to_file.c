#include "main.h"
#include <fcntl.h>   /* for open */
#include <unistd.h>  /* for write, close */
#include <sys/stat.h>  /* for S_IRUSR, S_IWUSR */

/**
 * append_text_to_file - Appends text at the end of a file
 * @filename: The name of the file to append to
 * @text_content: The content to append to the file (NULL-terminated string)
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_result;
	int length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		return (1);

	while (text_content[length])
		length++;

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	write_result = write(fd, text_content, length);
	if (write_result == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
