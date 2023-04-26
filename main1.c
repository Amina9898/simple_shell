#include 

/**
  * EOF_handle - function to handle end of file
  * @get : getline return
  * @buf : string from standard output
  */

void EOF_handle(int get, char *buf)
{
	(void)buf;

	if (get == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\n");
			free(buf);
		}
		exit(0);
	}
}

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

	signal(SIGINT, sig_handler);



	while (get != EOF)
	{
		print_prompt();
		get = getline(&buf, &n, stdin);
		EOF_handle(get, buf);
		user_input = split_string(buf);
		execute(user_input, argv[0]);
	}
	_free(user_input);
	free(buf);
	return (0);
}
