/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:20 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 16:19:23 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static int	unset_error(void)
{
	ft_eprintf("not a valid identifier\n");
	reteurn (EXIT_FAILURE);
}

int	unset_command(char **argv)
{
	size_t	i;
	t_env	*env;

	env = *(env_store());
	i = 1;
	while (argv[i])
	{
		if (env_name_judge(argv[i]) == true)
		{
			if (ft_strcmp(env->name, argv[i]) == 0)
				env_del(&env, argv[i]);
		}
		else
			unset_error();
		i++;
	}
	env_update("?", "0");
	return (EXIT_SUCCESS);
}

/*
bash-3.2$ unset a 2 = b 2
bash: unset: `2': not a valid identifier
bash: unset: `=': not a valid identifier
bash: unset: `2': not a valid identifier

環境変数が存在しなくてもエラーとはなりません
*/
