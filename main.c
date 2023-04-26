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
	char **path;
	int check_cmd = 0;
	(void) argc;

	signal(SIGINT, sig_handler);

	while (1)
	{
		print_prompt();
		get = get_line();
		user_input = split_string(get, env);

		if ((_strcmp(user_input[0], "\n") != 0) &&
				(_strcmp(user_input[0], "env") != 0))
		{
			path = search_env(env);
			check_cmd = cmd_status(user_input, path);
			execute(user_input, check_cmd, env, argv);
		}
		else
		{
			free(user_input);
		}
		free(get);
	}
	return (EXIT_SUCCESS);
}
