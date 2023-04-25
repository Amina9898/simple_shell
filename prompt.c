#include "main.h"

/**
 * print_prompt - function prints prompt and waits for input
 *
 * Return: nothing
 */

void print_prompt(void)
{
	char *s = "#Cisnotfun ";

	if (isatty(STDIN_FILENO))
		write(1, s, 11);
}
