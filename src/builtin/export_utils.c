/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 14:33:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static char	*export_getname(char *argv)
{
	int		i;
	char	*name;

	i = -1;
	if (!argv[0])
		return (NULL);
	while (argv[++i])
	{
		if (!env_name_judge(argv) || (argv[i] == ' ' && argv[i + 1] == '=')
			&& ft_eprintf("not a valid identifier\n"))
			return (NULL);
		if (argv[i] == '=')
		{
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

static char	check_type(char *str)
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

static int	export_insert(char *arg, t_env *env)
{
	char	*name;
	char	*value;
	char	*temp;

	name = export_getname(arg);   // <--- Leak
	value = export_getvalue(arg); // <--- Leak
	env = env_search(env, name);
	if (name == NULL)
		return (1);
	else if (check_type(arg) == '=' && env == NULL)
		env_list_add(env_store(), name, value);
	else if (check_type(arg) == '=')
		env_search(env, name)->value = value;
	else if (check_type(arg) == '+' && env == NULL)
		env_list_add(env_store(), name, value);
	else if (check_type(arg) == '+')
	{
		temp = env->value;
		env->value = ft_strjoin(env->value, value);
		free(temp);
	}
	else if (check_type(arg) == 0 && env == NULL)
		env_list_add(env_store(), name, NULL);
	return (0);
}

int	export_command(char **argv)
{
	t_env	*env;
	int		ret;

	ret = 0;
	env = (*env_store())->next;
	if (ft_memcpy(&env, &(*env_store())->next, sizeof(void *)) && !argv[1])
		export_putenvs(env);
	while (env_update("?", ft_itoa(ret)) && *++argv)
		if (export_insert(*argv, env))
			ret = 1;
	return (ret);
}
