#include "main.h"

/**
  * print_env - function to print the current environment
  * @env: environment variable
  */

void print_env(char **env)
{
	char **s = env;
	int i = 0;

	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
