/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 16:45:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

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

void	export_print_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '=')
			ft_putchar_fd(str[i], 1);
		else if (str[i] == '=')
		{
			ft_putchar_fd(str[i], 1);
			ft_putchar_fd('"', 1);
		}
		i++;
	}
	ft_putchar_fd('"', 1);
}

void	export_print_env(t_env *env)
{
	while (env)
	{
		printf("declare -x %s", env->name);
		if (env->value)
		{
			if (check_plus_equal(env->value) || ft_strchr(env->value, '='))
				export_print_equal(env->value);
			else
				printf("%s", env->value);
		}
		printf("\n");
		env = env->next;
	}
}
/*
int main()
{
    t_env *env_list = (t_env *)malloc(sizeof(t_env));
    env_list->name = strdup("MY_VAR");
    env_list->value = strdup("Hello World");
    env_list->next = NULL;

    export_print_env(env_list);

    free(env_list->name);
    free(env_list->value);
    free(env_list);

    return 0;
}
*/
