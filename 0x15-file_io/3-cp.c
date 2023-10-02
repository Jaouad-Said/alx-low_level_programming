#include "main.h"
char *allocateMemory(char *file);
void closeFile(int dsc);
/**
 * allocateMemory - allocates memory for a file
 * @file: file name
 * Return: pointer to the allocated meory
 */
char *allocateMemory(char *file)
{
	char *ch;

	ch = malloc(sizeof(char) * 1024);
	if (ch == NULL)
	{
		dprintf(STDERR_FILENO, "Can't write to %s\n", file);
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
	int fileTo, fileFrom, r, w;
	char *ch;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	ch = allocateMemory(argv[2]);
	fileFrom = open(argv[1], O_RDONLY);
	r = read(fileFrom, ch, 1024);
	fileTo = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fileFrom == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(ch);
			exit(98);
		}
		w = write(fileTo, ch, r);
		if (fileTo == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(ch);
			exit(99);
		}
		r = read(fileFrom, ch, 1024);
		fileTo = open(argv[2], O_WRONLY | O_APPEND);
	} while (r > 0);

	free(ch);
	closeFile(fileFrom);
	closeFile(fileTo);
	return (0);
}