#include "main.h"

/**
 * execute - function will excute command
 * @av: command array
 * @name: name of the program
 */

void execute(char **av, char *name)
{
	char *command;
	pid_t child;
	int status;

	if (!av || !av[0])
		return;

	command = check_path(av);

	if (command == NULL)
	{
		perror(name);
	}
	else
	{
		child = fork();
		if (child < 0)
		{
			perror("./hsh: ");
			exit(1);
		}
		if (child == 0)
		{
			execve(command, av, environ);
				perror(command);
			exit(EXIT_FAILURE);
		}
		wait(&status);
	}
}
