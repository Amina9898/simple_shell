#include "main.h"

/**
 * split_string - function will parse input
 * @buf: buffer string
 * @env: environment argument
 * Return: pointer to an array of strings
 */

char **split_string(char *buf, char **env)
{
	char *token;
	const char *delim = " \t\r\a\n";
	int token_count = 0;
	char **argv = NULL;

	if (buf == NULL)
		return (0);

	argv = calloc(sizeof(char *), 64);
	if (argv == NULL)
	{
		perror("Memorry Allocation Error");
		exit(EXIT_FAILURE);
	}
	token = strtok(buf, delim);

	while (token)
	{
		argv[token_count] = token;
		token_count++;
		token = strtok(NULL, delim);
	}
	if (argv[0] == NULL)
		argv[token_count] = "\n";

	if ((_strcmp(argv[0], "exit") == 0) && argv[1] == NULL)
	{
		free(buf);
		free(argv);
		exit(0);
	}
	if ((_strcmp(argv[0], "env") == 0) && argv[1] == NULL)
		print_env(env);

	return (argv);
}
