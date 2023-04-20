#include "main.h"

/**
 * split_string - function will parse input
 * @buf: buffer string
 * Return: pointer to an array of strings
 */

char **split_string(char *buf)
{
	char *cpy_buf;
	char *delim = " \t\n";
	int token_count = 0;
	char *token;

	strdup(cpy_buf, buf);

	token = strtok(buf, delim);

	while (token)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;
}
