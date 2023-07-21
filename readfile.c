#include "main.h"

/**
 * readshfile - a function that reads a textfile and prints it to strd out
 *
 * @filename: the name of the file to read
 * @buf: the buffer to write to
 *
 * Return: the actual number of letters written or 0 if it fails
 */

ssize_t readshfile(const char *filename, char **buf)
{
	int opn, opn2;

	opn = open(filename, O_RDONLY);

	if (opn <= 0)
		return (0);

	opn2 = read(opn, *buf, 1024);

	close(opn);
	return (opn2);
}
