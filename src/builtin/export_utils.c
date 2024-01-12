/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/12 11:19:48 by nsakanou         ###   ########.fr       */
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
	while(env)
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
