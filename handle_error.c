#include "main.h"

/**
  * handle_error - function to handle error as bash/sh
  * @argv: shell name
  * @cmd: command name
  * Return: 0
  */

int handle_error(char *argv, char *cmd)
{
	write(2, argv, _strlen(argv));
	write(2, ": ", 2);
	write(2, "1", 1);
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	perror(" ");
	return (0);
}

