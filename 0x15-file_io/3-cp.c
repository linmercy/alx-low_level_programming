#include <fcntl.h>    /* for open */
#include <unistd.h>   /* for read, write, close */
#include <sys/stat.h> /* for S_IRUSR, S_IWUSR, S_IRGRP, S_IWGRP, S_IROTH */

#include "main.h"

#define BUFFER_SIZE 1024

void print_error(const char *message, const char *filename, int code)
{
	dprintf(STDERR_FILENO, "%s: %s\n", message, filename);
	_exit(code);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, or the corresponding error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, read_result, write_result;
	char buffer[BUFFER_SIZE];
	mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error("Error: Can't read from file", argv[1], 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (fd_to == -1)
		print_error("Error: Can't write to", argv[2], 99);

	while ((read_result = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_result = write(fd_to, buffer, read_result);
		if (write_result == -1)
			print_error("Error: Can't write to", argv[2], 99);
	}

	if (read_result == -1)
		print_error("Error: Can't read from file", argv[1], 98);

	if (close(fd_from) == -1)
		print_error("Error: Can't close fd", argv[1], 100);

	if (close(fd_to) == -1)
		print_error("Error: Can't close fd", argv[2], 100);

	return (0);
}
