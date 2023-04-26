#include "main.h"

/**
 * print_prompt - function prints prompt and waits for input
 *
 * Return: nothing
 */

void print_prompt(void)
{
	char *s = {"#Cisnotfun "};
	char *buf = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, s, _strlen(s));
	}
	free(buf);
}
