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
	char *buf;
	int i;
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
		argv = split_string(buf);

		for (i = 0; argv[i] != NULL; i++)
			printf("argv[%d] = %s\n", i, argv[i]);
	}
	return (0);
}
