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
	char *buf, *path;
	char **path_array;
	(void)argc;
	(void)argv;

	while (1)
	{
		print_prompt();
		get = getline(&buf, &n, stdin);
		if (get == -1)
		{
			free(buf);
			exit(0);
		}
		argv = split_string(buf);
		path = getenv("PATH");
		path_array = split_path(path);
	}
	return (0);
}
