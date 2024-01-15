/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/15 22:22:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

// void	sort_env(t_env *env)
// {
// 	t_env	temp;

// 	if (env == NULL)
// 		return ;
// 	while (env->next)
// 	{
// 		if (ft_strcmp(env->name, env->next->name) > 0)
// 		{
// 			temp = *env;
// 			*env = *env->next;
// 			*env->next = temp;
// 		}
// 		env = env->next;
// 	}
// }

void sort_env(t_env *env)
{
	t_env *head;
	t_env *current;
	int i;
	int j;

	if (env == NULL || env->next == NULL)
		return;
	env = env->next;
	head = env;
	current = env;
	while (env != NULL)
	{
		if (env->name && ft_strcmp(current->name, env->name) > 0)
			current = env;
		env = env->next;
	}
	printf("%s\n", current->name);
	t_env *tmp;
	// char *tmp;
	tmp = env;
	while (1)
	{
		env = head;
		j = 0;
		i = ft_strcmp(current->name, env->name);
		while (env != NULL)
		{
			if (current->name && i < ft_strcmp(current->name, env->name) && current != env)
			{
				j++;
				i = ft_strcmp(current->name, env->name);
				tmp = env;
				printf("%d  %s\n", i, tmp->name);
			}
			env = env->next;
		}
		printf("%s\n", tmp->name);
		current = tmp;
		if (j != 3)
			break ;
	}
}

void export_print_env(void)
{
	t_env *env;

	env = *(env_store());
	sort_env(env);
	// while (env)
	// {
	// 	if (env->name && env->value && *env->name != 63)
	// 		printf("declare -x %s=%s\n", env->name, env->value);
	// 	else if (env->name && *env->name != 63)
	// 		printf("declare -x %s\n", env->name);
	// 	env = env->next;
	// }
}

// envsortasciiする

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
