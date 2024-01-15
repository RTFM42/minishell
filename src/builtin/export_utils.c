/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/15 18:59:37 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

void	ft_swap(t_env *a, t_env *b)
{
	t_env	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	sort_env(t_env *env)
{
	if (env == NULL)
		return ;
	while (env->next)
	{
		if (ft_strcmp(env->name, env->next->name) > 0)
			ft_swap(env, env->next);
		env = env->next;
	}
}

void	export_print_env(void)
{
	t_env	*env;

	env = *(env_store());

	sort_env(env);
	while (env)
	{
		if (env->name && env->value && *env->name != 63)
			printf("declare -x %s=%s\n", env->name, env->value);
		else if (env->name && *env->name != 63)
			printf("declare -x %s\n", env->name);
		env = env->next;
	}
}

//envsortasciiする

// bool	check_plus_equal(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strnstr(str, "+=", ft_strlen(str)))
// 	{
// 		while (str[i] != '+')
// 		{
// 			if (str[i] == '=')
// 				return (false);
// 			i++;
// 		}
// 		return (true);
// 	}
// 	else
// 		return (false);
// }
