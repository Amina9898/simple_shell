#include "main.h"

/**
  * check_path - function to split path into array
  * @argv: list of arguments
  * Return: will return full path of command
  */

char *check_path(char **argv)
{
	char *path, *cpy_path, *token, *command;
	char *command_path;
	struct stat st;

	if (argv && argv[0])
		command = argv[0];

	path = getenv("PATH");
	if (path != NULL)
	{
		cpy_path = strdup(path);
		token = strtok(cpy_path, ":");

		while (token != NULL)
		{
			command_path = malloc(sizeof(char) * (strlen(command) + strlen(token) + 2));
			strcpy(command_path, token);
			strcat(command_path, "/");
			strcat(command_path, command);
			strcat(command_path, "\0");

			if (stat(command_path, &st) == 0)
			{
				free(cpy_path);
				return (command_path);
			}
			else
			{
				free(command_path);
				token = strtok(NULL, ":");
			}
		}
		free(cpy_path);
		if (stat(command, &st) == 0)
			return (command);
	}
	return (NULL);
}
