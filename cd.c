#include "main.h"
/**
 * cwd_search - look for current working dir
 * @f: file name
 * Return: current working dir
 */
char *cwd_search(char *f, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *ret;
	int len = 0;
	int i = 0;

	while (f[len])
		len++;
	ret = malloc(sizeof(char) * (len + 3));
	dir = opendir(".");
	if (!dir)
	{
		printf("Error! Unable to open directory.\n");
		exit(0);
	}
	while ((sd = readdir(dir)))
	{
		for (i = 0; sd->d_name[i] && f[i]; i++)
		{
			if (sd->d_name[i] != f[i])
				break;
			if (i == (len - 1) && !(sd->d_name[i + 1]))
			{
				strcpy(ret, "./");
				strcat(ret, f);
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
				else
					write(2, er, 5);
			}
		}
	}
	closedir(dir);
	return (er);
}
