#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   /* for open */
#include <unistd.h>  /* for read, write, close */
#include <sys/stat.h>  /* for S_IRUSR */
#include "main.h"

#define BUFFER_SIZE 1024

/**
 * cp - Copies the content of one file to another file
 * @file_from: The source file
 * @file_to: The destination file
 *
 * Return: 0 on success, or the exit code on failure
 */
int cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, read_count, write_count;
	char buffer[BUFFER_SIZE];

	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				file_from);
		return (98);
	}

	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		close(fd_from);
		return (99);
	}

	while ((read_count = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_count = write(fd_to, buffer, read_count);
		if (write_count == -1 || write_count != read_count)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n",
					file_to);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (read_count == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				file_from);
		close(fd_from);
		close(fd_to);
		return (98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		close(fd_to);
		return (100);
	}

	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		return (100);
	}

	return (0);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, or the exit code on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	return (cp(argv[1], argv[2]));
}

