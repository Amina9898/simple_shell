#include "main.h"

/**
 * execute - function will excute command
 * @av: command array
 */

void execute(char **av, char *name)
{
	char *command;
	pid_t child;
	int status;

	if (av && av[0])
	{
		command = check_path(av);

		if (command == NULL)
		{
			perror(name);
		}
		else
		{
			child = fork();
			if (child == -1)
				perror("Fork Error");
			if (child == 0)
			{
				if (execve(command, av, environ) == -1)
				{
					perror(command);
					exit(EXIT_FAILURE);
				}
			}
			wait(&status);
		}

	}
}
