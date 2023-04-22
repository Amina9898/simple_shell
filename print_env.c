#include "main.h"

/**
  * print_env - function to print the current environment
  */

void print_env()
{
	char **s = environ;
	int i = 0;

	while (s[i] != NULL)
	{
		printf("%s\n", s[i]);
		i++;
	}
}
