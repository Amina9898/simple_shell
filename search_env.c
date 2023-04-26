#include "main.h"

/**
  * search_env - function to search for path inside env
  * @env : environment variable passed from main
  * Return: will return the right path of argument
  */

char **search_env(char **env)
{
	int i;
	char **command_path;

	for (i = 0; env[i] != NULL ; i++)
	{
		if (env[i][0] == 'P' && env[i][2] == 'T')
		{
			command_path = check_path(env[i]);
		}
	}
	return (command_path);
}

