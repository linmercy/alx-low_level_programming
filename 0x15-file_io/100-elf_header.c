#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   /* for open */
#include <unistd.h>  /* for read, lseek */
#include <sys/stat.h>  /* for S_IRUSR */

#define ELF_MAGIC_SIZE 4
#define ELF_HEADER_SIZE 64

/**
 * print_error - Prints the error message to stderr and exits with code 98
 * @message: The error message to print
 */
void print_error(const char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * print_elf_header - Prints the information contained in the ELF header
 * @header: The ELF header data
 */
void print_elf_header(const unsigned char *header)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < ELF_MAGIC_SIZE; i++)
		printf("%02x ", header[i]);
	printf("\n");

	printf("  Class:                             %s\n", (header[4] == 1) ? "ELF32" : "ELF64");
	printf("  Data:                              %s\n", (header[5] == 1) ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header[6]);
	printf("  OS/ABI:                            %d\n", header[7]);
	printf("  ABI Version:                       %d\n", header[8]);
	printf("  Type:                              %d\n", *((unsigned short *)&header[16]));
	printf("  Entry point address:               %lx\n", *((unsigned long *)&header[24]));
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: 0 on success, or 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	unsigned char header[ELF_HEADER_SIZE];

	if (argc != 2)
	{
		print_error("Usage: elf_header elf_filename");
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Error: Cannot open file");
	}

	if (read(fd, header, ELF_HEADER_SIZE) != ELF_HEADER_SIZE)
	{
		print_error("Error: Cannot read ELF header");
	}

	/* Check if the file is an ELF file */
	if (header[0] != 0x7f || header[1] != 'E' || header[2] != 'L' || header[3] != 'F')
	{
		print_error("Error: Not an ELF file");
	}

	print_elf_header(header);

	if (close(fd) == -1)
	{
		print_error("Error: Cannot close file");
	}

	return 0;
}
