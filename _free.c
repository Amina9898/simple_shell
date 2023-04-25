#include "main.h"

/**
  * _free - function to free array of pointers
  * @argv: array of pointers
  */

void _free(char **argv)
{
	int i;

	for (i = 0; argv[i] != NULL; i++)
		free(argv[i]);
	free(argv);
}
