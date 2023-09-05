#include "main.h"
char *allocMemory(char *fd);
void closeFile(int dsc);
/**
 * allocateMemory - allocates memory for a file
 * @file: file name
 * Return: pointer to the allocated memory
 */
char *allocMemory(char *fd)
{
	char *ch;

	ch = malloc(sizeof(char) * 1024);
	if (ch == NULL)
	{
		dprintf(STDERR_FILENO, "Can't write to %s\n", fd);
		exit(99);
	}
	return (ch);
}

/**
 * closeFile - close a file
 * @dsc: file descriptor
 * Return: void
 */
void closeFile(int dsc)
{
	int cl;

	cl = close(dsc);
	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dsc);
		exit(100);
	}
}

/**
 * main - program that copies content of a file
 * @argc: number of arguments passed to main
 * @argv: the arguments passed to main
 * Return: int
 */
int main(int argc, char *argv[])
{
	int fdTo, fdFrom, r, w;
	char *ch;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp fd_from fd_to\n");
		exit(97);
	}

	ch = allocateMemory(argv[2]);
	fdFrom = open(argv[1], O_RDONLY);
	r = read(fdFrom, ch, 1024);
	fdTo = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fdFrom == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(ch);
			exit(98);
		}
		w = write(fdTo, ch, r);
		if (fdTo == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(ch);
			exit(99);
		}
		r = read(fdFrom, ch, 1024);
		fdTo = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(ch);
	closefd(fdFrom);
	closefd(fdTo);
	return (0);
}
