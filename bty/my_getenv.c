#include "../main.h"
/**
 * my_getenv - gets the enviroment
 * @env_var: the enviroment variable
 * Return: Nothing
*/
char *my_getenv(char *env_var)
{
	size_t var_len;
	int i;

	var_len = _strlen(env_var);
	while (environ[i])
	{
		if (_strncmp(environ[i], env_var, var_len) == 0 \
		&& environ[i][var_len] == '=')
		{
			return (environ[i] + var_len + 1);
		}
		i++;
	}
	return (NULL);
}
