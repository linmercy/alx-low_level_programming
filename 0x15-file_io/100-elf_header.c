#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>    /* for open */
#include <unistd.h>   /* for read, close */
#include <sys/types.h> /* for lseek */
#include <sys/stat.h> /* for S_IRUSR */
#include "main.h"

#define ELF_HEADER_SIZE 64

/**
* print_elf_header - Prints the information contained in the ELF header
* @header: Pointer to the ELF header
*/
void print_elf_header(const unsigned char *header)
{
	printf("Magic: ");
	for (int i = 0; i < 16; i++)
		printf("%02x ", header[i]);
	printf("\n");

	printf("Class: %s\n", (header[4] == 1) ? "ELF32" : "ELF64");
	printf("Data: %s\n", (header[5] == 1) ? "2's complement, little
			endian" : "2's complement, big endian");
	printf("Version: %d\n", header[6]);
	printf("OS/ABI: %d\n", header[7]);
	printf("ABI Version: %d\n", header[8]);

	printf("Type: ");
	unsigned short type = *(unsigned short *)(header + 16);
	switch (type)
	{
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("Unknown\n");
		break;
	}

	printf("Entry point address: 0x%lx\n", *(unsigned long *)(header + 24));
}

/**
* elf_header - Displays the information contained in the ELF header
* @filename: The name of the ELF file
*
* Return: (0) on success, or the exit code on failure
*/
int elf_header(const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to open file %s\n", filename);
		return (98);
	}

	unsigned char header[ELF_HEADER_SIZE];
	ssize_t read_count = read(fd, header, ELF_HEADER_SIZE);
	if (read_count == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to read file %s\n", filename);
		close(fd);
		return (98);
	}

	if (read_count != ELF_HEADER_SIZE)
	{
		dprintf(STDERR_FILENO, "Error: Invalid ELF header size\n");
		close(fd);
		return (98);
	}

	print_elf_header(header);
	close(fd);
	return (0);
}

/**
* main - Entry point of the program
* @argc: The number of command-line arguments
* @argv: An array of command-line argument strings
*
* Return: (0) on success, or the exit code on failure
*/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		return (98);
	}

	return (elf_header(argv[1]));
}

