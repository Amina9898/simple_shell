#include "main.h"

/**
 * main - main function
 * @argc: number of arguments
 * @argv: array of pinters
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	size_t n;
	ssize_t get;
	char *buf; /**path;
	char **path_array;*/
	char **string;
	(void)argc;

	while (1)
	{
		print_prompt();
		get = getline(&buf, &n, stdin);
		if (get == -1)
		{
			free(buf);
			exit(0);
		}
		string = split_string(buf);
		if (execve(string[0], string, environ) == -1)
			perror(argv[0]);
		/*path = getenv("PATH");
		path_array = split_path(path);
		if (path_array == NULL)
			exit(0);*/
	}
	return (0);
}
