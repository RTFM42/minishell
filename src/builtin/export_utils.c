/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 22:32:42 by nsakanou         ###   ########.fr       */
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

//envsortascii
void	export_print_env()
{
	const t_env	*env = *(env_store());

	while (env)
	{
		if (env->name && env->value)
			printf("declare -x %s=%s\n", env->name, env->value);
		else if (env->name)
			printf("declare -x %s\n", env->name);
		env = env->next;
	}
}
