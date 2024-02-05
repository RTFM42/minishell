/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:20 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 17:33:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static int	unset_error(void)
{
	ft_eprintf("not a valid identifier\n");
	return (EXIT_FAILURE);
}

int	unset_command(char **argv)
{
	size_t	i;
	t_env	*env;
	int		status;

	i = 1;
	status = 0;
	while (argv[i])
	{
		env = (*env_store())->next;
		if (env_name_judge(argv[i]) == true)
		{
			while (env)
			{
				if (ft_strcmp(env->name, argv[i]) == 0
					&& env_del(env_store(), argv[i]))
					break ;
				env = env->next;
			}
		}
		else
			status = unset_error();
		i++;
	}
	env_update("?", ft_itoa(status));
	return (EXIT_SUCCESS);
}
