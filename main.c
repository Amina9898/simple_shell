#include "main.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pinters
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	size_t n = 0;
	ssize_t get = 0;
	char *buf = NULL;
	char **user_input = NULL;
	(void) argc;



	while (1)
	{
		print_prompt();
		get = getline(&buf, &n, stdin);
		if (get == -1)
		{
			write(1, "\n", 1);
			free(buf);
			exit(EXIT_FAILURE);
		}
		if (_strcmp(buf, "\n") == 0)
			continue;
		user_input = split_string(buf);
		execute(user_input, argv[0]);
	}
	_free(user_input);
	free(buf);
	return (0);
}
