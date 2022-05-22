#include "main.h"
/**
 * _get_environment - gets env of input
 * @env: input
 * Return: env without =
 */
char *get_environment(char *env)
{
	int x = 0, s = 0;
	char *temp, *res;

	while (environ[x] != NULL)
	{
		if (strcmp(environ[x], env) == 0)
			temp = environ[x];
		x++;
	}

	while (temp[s] != '\0')
	{
		if (strcmp(temp, env) == 0)
			res = strstr(temp, "/");
		s++;
	}
	return (res);
}
