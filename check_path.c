#include "main.h"

/**
  * check_path - function to split path into array
  * @path: path variable
  * Return: will return path as array
  */

char **check_path(char *path)
{
	char *cpy_path = NULL, *token = NULL;
	const char *delim = ":=";
	char **path_tokens = calloc(sizeof(char *), 64);
	int i = 0;

	if (path == NULL)
	{
		free(path);
		return (0);
	}
	if (path_tokens == NULL)
	{
		free(path);
		perror("Allocated Memorry Error: ");
		return (NULL);
	}
	cpy_path = strdup(path);
	token = strtok(cpy_path, delim);

	while (token != NULL)
	{
		path_tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	return (path_tokens);
}
