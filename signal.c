#include "main.h"

/**
 * signal - handels the signals
 * @sig: Signal identifier
 *
 * Return: nothing
 */

void _signal(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n#Cisnotfun ", 12);
}
