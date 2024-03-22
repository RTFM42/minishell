/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/03/22 16:14:28 by nsakanou         ###   ########.fr       */
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
		if ((!env_name_judge(argv) || (argv[i] == ' ' && argv[i + 1] == '='))
			&& ft_eprintf("not a valid identifier\n"))
			return (NULL);
		if (argv[i] == '=' || (argv[i] == '+' && argv[i + 1] == '='))
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

static void	export_insert_plus(t_env *env, char *value)
{
	char	*temp;

	temp = env->value;
	env->value = ft_strjoin(env->value, value);
	free(temp);
}

static void	export_rewrite_value(t_env *env, char *name, char *new_value)
{
	if (env == NULL || name == NULL || new_value == NULL)
		return ;
	while (env)
	{
		if (env->name && ft_strcmp(env->name, name) == 0)
		{
			if (env->value)
				free(env->value);
			env->value = ft_strdup(new_value);
			return ;
		}
		env = env->next;
	}
}

int	export_insert(char *arg, t_env *env)
{
	char	*name;
	char	*value;
	int		status;

	name = export_getname(arg);
	value = export_getvalue(arg);
	env = env_search(env, name);
	status = 0;
	if (name == NULL)
		status = 1;
	else if (check_type(arg) == '=' && env == NULL)
		env_list_add(env_store(), name, value);
	else if (check_type(arg) == '=')
		export_rewrite_value(*env_store(), name, value);
	else if (check_type(arg) == '+' && env == NULL)
		env_list_add(env_store(), name, value);
	else if (check_type(arg) == '+')
		export_insert_plus(env, value);
	else if (check_type(arg) == 0 && env == NULL)
		env_list_add(env_store(), name, NULL);
	free(name);
	free(value);
	return (status);
}
