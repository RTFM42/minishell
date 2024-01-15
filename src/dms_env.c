/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dms_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:31:44 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/15 09:18:20 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../builtin.h"

void	dms_putenv(void)
{
	int		i;
	t_env	*env;

	env = *(env_store());
	i = 0;
	if (env != NULL)
		env = env->next;
	while (env && env->name)
	{
		ft_printf("\x1b[33m%d: \x1b[44m%s=%s\x1b[0m\n", i++,
			env->name, env->value);
		env = env->next;
	}
}
