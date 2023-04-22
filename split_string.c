#include "main.h"

/**
 * split_string - function will parse input
 * @buf: buffer string
 * Return: pointer to an array of strings
 */

char **split_string(char *buf)
{
	char *cpy_buf, *token;
	char *delim = " \t\n";
	int token_count = 0, i;
	char **argv;

	cpy_buf = strdup(buf);
	token = strtok(buf, delim);

	while (token)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;

	argv = malloc(sizeof(char *) * token_count);

	if (!argv)
	{
		perror("Memorry Allocation Error");
		free(cpy_buf);
		free(argv);
		return (NULL);
	}
	token = strtok(cpy_buf, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	if (strcmp(argv[0], "exit") == 0)
		exit(EXIT_SUCCESS);
	if (strcmp(argv[0], "env") == 0)
		print_env();
	free(cpy_buf);
	return (argv);
}
