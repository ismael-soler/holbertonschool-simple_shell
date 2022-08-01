#include "main.h"

/**
 * _strlen - count the large of a string, without including NULL char
 * @string: string
 * Return: length of the string as an int
 */

int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (0);
	for (len = 0; string[len]; len++)
	{
	}
	return (len);
}

/**
 * _strcat - concatenate two strings
 * @dest: pointer to destinate string
 * @src: pointer to string to be concatenated on dest
 * Return: "dest"+"src"
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	for (i = 0; dest[i]; i++)
	{
	}
	for (j = 0; src[i]; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: pointer to a string
 * @s2: pointer to a string
 * Return: 0 if they are equal, other number if they are different.
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			break;
	}
	i = *s1;
	j = *s2;
	return (i - j);
}

/**
 * _strcpy - copy one string to another
 * @dest: pointer to a string
 * @src: pointer to the original string
 * Return: copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
