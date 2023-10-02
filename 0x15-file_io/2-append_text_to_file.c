#include "main.h"
/**
 * append_text_to_file - function that appends text to a file
 * @filename: file name
 * @text_content: string to be added at the end
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int r, w, lenght = 0;

	if (filename == NULL)
		return (-1);
	while (text_content != NULL && text_content[lenght])
	{
		lenght++;
	}
	r = open(filename, O_WRONLY | O_APPEND);
	if (r == -1)
		return (-1);
	w = write(r, text_content, lenght);
	if (w == -1)
		return (-1);
	close(r);
	return (1);
}