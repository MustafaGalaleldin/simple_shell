#include "main.h"
/**
 * my_strtok - tokenizing a string
 * @str: string
 * @delim: delimeter
 * Return: token or null
 */
char *my_strtok(char *str, const char *delim)
{
	static char *ret;
	static int m;
	int i;

	if (!ret && !str)
		return (NULL);
	if ((!ret) || (ret && str))
	{
		ret = str;
		m = 0;
	}
	ret += m;
	while (*ret)
	{
		for (m = 0; ret[m]; m++)
		{
			for (i = 0; delim[i]; i++)
			{
				if (delim[i] == ret[m])
				{
					ret[m] = '\0';
					if (!m)
					{
						ret++;
						m--;
						i = (_strlen(delim)) - 1;
						continue;
					}
					m++;
					return (ret);
				}
			}
		}
		if (m > 0)
			return (ret);
	}
	return (NULL);
}
