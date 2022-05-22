#include "main.h"

/**
 * _getline - a function ...
 * @foot: the chain
 * @p: the number
 * @stream: the File
 *
 * Return: 1 or 0
 */
char _getline(char **foot, size_t *p, FILE *stream)
{
	/* implement your code, see man strtok*/

	UNUSED(foot);
	UNUSED(p);
	UNUSED(stream);

	return (getline(foot, p, stream));
}
