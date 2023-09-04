#include "main.h"
/**
 *  * create_file - creates the file
 *  @filename: file that should be created
 *  @text_content: content of that file
 *  Return: int
 */
int create_file(const char *filename, char *text_content)
{
	int f, len = 0, w;

	if (filename == NULL)
		return (-1);
	while (text_content != NULL && text_content[len])
	{
		len++;
	}
	f = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (w == -1)
		return (-1);
	w = write(f, text_content, len);
	if (w == -1)
		return (-1);
	close(f);
	return (1);
}
