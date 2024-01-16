/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:41:00 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/16 22:37:50 by nsakanou         ###   ########.fr       */
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

int	export_command(char **argv)
{
	t_env	*env;

	env = (*env_store())->next;
	if (argv[1] == NULL)
		export_putenvs(env);
	else if (!check_plus_equal(argv[1]))
		
	else if (check_plus_equal(argv[1]))
	{
		env_update(env->name, env->name);
		export_putenvs(env);
	}
	return (0);
}
