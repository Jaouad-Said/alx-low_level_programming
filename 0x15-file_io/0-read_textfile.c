#include "main.h"
/**
 * read_textfile - function that reads and prints text file
 * @filename: name of the file
 * @letters: number of letters
 * Return: size_t
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int ab;
	ssize_t bts;
	char buffer[GET_BUFFER_SIZE * 8];

	if (!filename || !letters)
		return (0);
	ab = open(filename, O_RDONLY);
	if (ab == -1)
		return (0);
	bts = read(ab, &buffer[0], letters);
	bts = write(STDOUT_FILENO, &buffer[0], bts);
	close(ab);
	return (bts);
}
