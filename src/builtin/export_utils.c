/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/16 23:21:07 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static char	*export_getname(char *argv)
{
	char	*value;
	char	*name;

	if (ft_strchr(argv, '+') && *(ft_strchr(argv, '+') + 1) == '=')
	{
		value = ft_strchr(argv, '+') + 2;
		name = (char *)ft_calloc(value - argv, 1);
		ft_strlcpy(name, argv, value - argv - 1);
	}
	else
	{
		value = ft_strchr(argv, '=') + 1;
		name = (char *)ft_calloc(value - argv + 1, 1);
		ft_strlcpy(name, argv, value - argv);
	}
	return (name);
}

static char	*export_getvalue(char *argv)
{
	char	*value;

	value = ft_strdup(ft_strchr(argv, '=') + 1);
	return (value);
}

bool	check_plus_equal(char *str)
{
	int	i;

	i = 0;
	if (ft_strnstr(str, "+=", ft_strlen(str)))
	{
		while (str[i] != '+')
		{
			if (str[i] == '=')
				return (false);
			i++;
		}
		return (true);
	}
	else
		return (false);
}

int	export_command(char **argv)
{
	size_t	i;
	t_env	*env;
	char	*name;
	char	*value;

	i = 1;
	env = (*env_store())->next;
	if (argv[1] == NULL)
		export_putenvs(env);
	while (argv[i])
	{
		name = export_getname(argv[i]);
		value = export_getvalue(argv[i]);
		printf("pkpkpkpk: %s:%s\n", name, value);
		if (check_plus_equal(argv[i]))
			env_update(name, value);
		else if (!check_plus_equal(argv[i]))
		{
			env_list_add(env_store(), name, value);
			if (name)
				free(name);
			if (value)
				free(value);
		}
		i++;
		export_putenvs(env);
		strerror(errno);
		i++;
	}
	env_update("?", "0");
	return (0);
}
