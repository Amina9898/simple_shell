#include "main.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pinters
 * @env: environment variable
 * Return: 0 on success
 */

int main(int argc, char **argv, char **env)
{
	char *get;
	char **user_input = NULL;
	(void) argc;

	signal(SIGINT, sig_handler);



	while (1)
	{
		print_prompt();
		get = get_line();
		user_input = split_string(get, env);
		execute(user_input, argv[0]);
	}
	_free(user_input);
	return (0);
}
