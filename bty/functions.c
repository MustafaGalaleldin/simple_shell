#include "../main.h"

/**
 * _strlen - l
 * @s: input
 * Return: length
 */
int _strlen(const char *s)
{
	int count = 0;

	if (s)
	{
		while (*s != '\0')
		{
			count++;
			s++;
		}
	}
	return (count);
}

/**
 * _memcpy - copies memory area
 * @dest: destination
 * @src: source
 * @n: num of bytes
 * Return: dest
 */

char *_memcpy(char *dest, const char *src, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		dest[x] = src[x];
	}
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *
 * @str: string
 *
 * Return: pointer or null
 */

char *_strdup(const char *str)
{
	int i = _strlen(str) + 1;
	char *c = malloc(i);

	if (str == NULL)
		return (NULL);
	if (c)
	{
		_memcpy(c, str, i);
		return (c);
	}
	return (NULL);
}

/**
 * tokenizer - tokenize strings
 *
 * @count: sizeof av
 * @buf: commands written
 *
 * Return: array of strings
 */
char **tokenizer(char *buf, size_t count)
{
	char *ttok;
	char **v = malloc(sizeof(char *) * count);
	int i = 0;

	if (!v)
		return (NULL);
	ttok = my_strtok(buf, " \n");
	while (ttok)
	{
	/*	if (_strcmp(ttok, "#") == 0)
			break;*/
		if (ttok[0] == '#')
			break;
		v[i] = strdup(ttok);
		ttok = my_strtok(NULL, " \n");
		i++;
	}
	v[i] = NULL;
	return (v);
}

/**
 * get_path - get path
 *
 */
char *get_path(char **env)
{
	int i = 0;

	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && 
				env[i][2] == 'T' && env[i][3] == 'H')
			return (env[i]);
		i++;
	}
	return (NULL);
}
