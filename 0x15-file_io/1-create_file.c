#include "main.h"
/**
 * create_file - create a file
 * @filename: file to create
 * @text_content: content of the file
 * Return: int
 */
int create_file(const char *filename, char *text_content)
{
	int f, lenght = 0, w;

	if (filename == NULL)
		return (-1);
	while (text_content != NULL && text_content[lenght])
	{
		lenght++;
	}
	f = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (f == -1)
		return (-1);
	w = write(f, text_content, lenght);
	if (w == -1)
		return (-1);
	close(f);
	return (1);
}