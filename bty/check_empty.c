#include "../main.h"
/**
 * check_empty - a function that checkes if the string is empty
 * @_str: a string
 * Return: 1 if it's empty
*/
int check_empty(char *_str)
{
	if (_str == NULL)
		return (1);
	while (*_str)
	{
		if (*_str == ' ' || *_str == '\n' || *_str == '\t' \
		 || *_str == '\f' || *_str == '\v' || *_str == '\r')
			return (0);
		_str++;
	}
	return (1);
}
