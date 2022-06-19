#define _GNU_SOURCE
#include "monty.h"

/**
 * main - main entry point
 * @argc: argument count
 * @argv: srgument vector
 * Return: 0 if success.
 */

int main(int argc, char **argv)
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	read_file(fd, argv[1]);
	return (EXIT_SUCCESS);
}
