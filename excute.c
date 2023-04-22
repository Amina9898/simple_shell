#include "main.h"

/**
 * execute - function will excute command
 * @av: command array
 */

void execute(char **av)
{
	char *command; char *

	if (av && av[0])
	{
		command = check_path(av);

		if (command == NULL)
			perror("Error");
	}
}
