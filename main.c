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
	ssize_t get;
	char *buf = NULL;
	char **user_input;
	(void) argc;



	while (1)
	{
		print_prompt();
		get = getline(&buf, &n, stdin);
		if (get == -1)
		{
			free(buf);
			break;
		}
		if (strcmp(buf, "\n") == 0)
			continue;
		user_input = split_string(buf);
		execute(user_input, argv[0]);
	}
	free(buf);
	_free(user_input);
	return (0);
}
