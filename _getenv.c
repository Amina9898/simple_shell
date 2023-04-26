#include "main.h"

/**
  * _getenv - function to get path from environ
  * @name: name of global variable
  * Return: string of the global varibale
  */

char *_getenv(char *name)
{
	int i, j;
	char *path;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				path = (environ[i] + j + 1);
				return (path);
			}
		}
	}
	return (0);
}
