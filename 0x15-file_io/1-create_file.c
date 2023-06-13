#include "main.h"
#include <fcntl.h>   /* for open */
#include <unistd.h>  /* for write, close */
#include <sys/stat.h>  /* for S_IRUSR, S_IWUSR */

/**
 * create_file - Creates a file with the specified name and writes
 * the content to it
 * @filename: The name of the file to create
 * @text_content: The content to write to the file (NULL-terminated string)
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, write_result;
	int permissions = S_IRUSR | S_IWUSR;  /* rw------- */
	int length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[length])
			length++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		write_result = write(fd, text_content, length);
		if (write_result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
