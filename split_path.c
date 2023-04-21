#include "main.h"

/**
  * split_path - function to split path into array
  * @path: path to be split
  * Return: will return array of path directories
  */

char **split_path(char *path)
{
	char **path_array;
	char *token;
	char *cpy_path = strdup(path);
	int token_count = 0, i;

	token = strtok(path, ":");
	while(token)
	{
		token_count++;
		token = strtok(NULL, ":");
	}
	token_count++;

	path_array = malloc(sizeof(char *) * token_count);
	if(!path_array)
	{
		free(cpy_path);
		return (NULL);
	}
	token = strtok(cpy_path, ":");
	for (i = 0; token != NULL; i++)
	{
		path_array[i] = malloc(sizeof(char) * strlen(token));
		strcpy(path_array[i], token);
		token = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	free(cpy_path);
	free(path);
	return (path_array);
}

