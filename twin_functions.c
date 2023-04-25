#include "main.h"

/**
 * _strdup - function will duplicate string
 * @string: input
 * Return: dupe
 */

char *_strdup(char *string)
{
	char *s = NULL;
	unsigned int size = 0, i;

	if (string == NULL)
		return (NULL);

	while (*(string + size))
		size++;

	s = malloc(sizeof(char) * (size + 1));

	if (s == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		*(s + i) = *(string + i);

	*(s + size) = '\0';
	return (s);
}

/**
 * _strcat - function will concatenate a string to another
 * @s1: first string
 * @s2: second string
 * Return: concat
 */

char *_strcat(char *s1, char *s2)
{
	int i = 0, n;

	while (s1[i] != '\0')
	{
		i++;
	}

	for (n = 0; s2[n] != '\0'; n++)
	{
		s1[i] = s2[n];
		i++;
	}
	s1[i] = '\0';

	return (s1);

}

/**
 * _strcmp - function compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 on success
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int def;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			def = (s1[i] - s2[i]);
			break;
		}
		else
			def = 0;
	}
	return (def);
}

/**
 * _strlen - function returns length of a string
 * @string: input string
 * Return: length of the input string
 */

int _strlen(char *string)
{
	int len = 0;

	while (*string != '\0')
	{
		len++;
		string++;
	}
	return (len);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @s1: copy to
 * @s2: copy from
 * Return: string
 */

char *_strcpy(char *s1, char *s2)
{
	int len = 0;

	while (*(s2 + len) != '\0')
	{
		*(s1 + len) = *(s2 + len);
		len++;
	}

	*(s1 + len) = '\0';
	return (s1);
}
