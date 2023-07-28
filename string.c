#include "shell.h"
/**
 * _strlen - len
 * @s: s
 * Return: i.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}
/**
 * _strcat - concatnet
 * @dest: dest
 * @src: src
 * Return: ret
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
/**
 * _strcpy - copy
 * @dest: de
 * @src: sr
 * Return: val
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
/**
 * _strdup - str
 * @str: str
 *
 * Return: val
 */
char *_strdup(const char *str)
{
	int v;
	int lent;
	char *new_a;

	if (str == NULL)
		return (NULL);
	lent = 0;
	while (str[lent] != '\0')
		lent++;
	new_a = malloc(sizeof(char) * (lent + 1));
	if (new_a == NULL)
		return (NULL);
	v = 0;
	while (str[v])
	{
		new_a[v] = str[v];
		v++;
	}
	return (new_a);
}
