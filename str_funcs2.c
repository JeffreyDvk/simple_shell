#include "main.h"
/**
* _strlen - function
*
* @i: the chain
* Return: Always 0.
*/

int _strlen(char *i)
{

	if (*i == '\0')
		return (0);
	else
		return (1 + _strlen(i + 1));
}
