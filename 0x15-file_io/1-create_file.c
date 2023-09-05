#include "main.h"
/**
 *  * create_file - creates the file
 *  @filename: file that should be created
 *  @text_content: content of that file
 *  Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

int create_file(const char *filename, char *text_content)
{
	int fol;
	ssize_t bts = 0, len = _strlen(text_content);

	if (!filename)
		return (-1);
	fol = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fol == -1)
		return (-1);
	if (len)
		bts = write(fol, text_content, len);
	close(fol);
	return (bts == len ? 1 : -1);
}
