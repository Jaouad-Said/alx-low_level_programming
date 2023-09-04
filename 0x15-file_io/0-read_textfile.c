#include "main.h"
/**
 * read_textfile - function that reads and prints text file
 * @filename: name of the file
 * @letters: number of letters
 * Return: size_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int a, b, c;
	char *chr;

	a = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	chr = malloc(sizeof(chr) * letters);
	if (chr == NULL)
	{
		clode(a);
		return (0);
	}
	b = read(a, chr, letters);
	c = write(STDOUT_FILENO, chr, b);
	if (b == -1)
	{
		free(chr);
		close(a);
		return (0);
	}
	close(a);
	return (c);
}
