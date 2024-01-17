/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/17 21:32:23 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static char	*export_getname(char *argv)
{
	int		i;
	char	*name;

	i = 0;
	if (!argv[i])
		return (NULL);
	while (argv[i])
	{
		if (!env_name_judge(argv) || (argv[i] == ' ' && argv[i + 1] == '='))
		{
			DEBUG();
			ft_eprintf("not a valid identifier\n");
			break ;
		}
		if (argv[i] == '=')
		{
			DEBUG();
			name = ft_calloc(i + 1, sizeof(char));
			ft_strlcpy(name, argv, i + 1);
			return (name);
		}
		else if (argv[i] == '+' && argv[i + 1] == '=')
		{
			name = ft_calloc(i + 1, sizeof(char));
			ft_strlcpy(name, argv, i + 1);
			return (name);
		}
		i++;
	}
	name = ft_calloc(i + 1, sizeof(char));
	ft_strlcpy(name, argv, i + 1);
	return (name);
}

static char	*export_getvalue(char *argv)
{
	char	*value;
	char	*equal;

	equal = ft_strchr(argv, '=');
	if (equal == NULL)
		return (NULL);
	value = ft_strdup(equal + 1);
	return (value);
}

char	check_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return ('=');
		else if (str[i] == '+' && str[i + 1] == '=')
			return ('+');
		i++;
	}
	return (0);
}

int	export_command(char **argv)
{
	size_t	i;
	t_env	*env;
	char	*name;
	char	*value;
	char	*temp;

	i = 1;
	env = (*env_store())->next;
	if (argv[1] == NULL)
		export_putenvs(env);
	while (argv[i])
	{
		name = export_getname(argv[i]);
		value = export_getvalue(argv[i]);
		if (check_type(argv[i]) == '=')
		{
			env = env_search(env, name);
			if (env == NULL)
				env_list_add(env_store(), name, value);
			else
				env_search(env, name)->value = value;
		}
		else if (check_type(argv[i]) == '+')
		{
			env = env_search(env, name);
			if (env == NULL)
				env_list_add(env_store(), name, value);
			else
			{
				env = env_search(env, name);
				temp = env->value;
				env->value = ft_strjoin(env->value, value);
				free(temp);
			}
		}
		else
		{
			env = env_search(env, name);
			if (env == NULL)
				env_list_add(env_store(), name, NULL);
		}
		i++;
	}
	env_update("?", "0");
	return (0);
}
