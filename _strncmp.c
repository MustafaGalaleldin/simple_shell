#include "main.h"
/**
 * _strncmp - Compare two specified number of characters
 * @str1: first string
 * @str2: second string
 * @n: maximum number of characters to compare
 * Return: Negative if str1 < str2, positive if str1 > str2
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0 && (*str1 || *str2))
	{
		if (*str1 != *str2)
			return (*str1 - *str2);

		str1++;
		str2++;
		n--;
	}

	return (0);

}
