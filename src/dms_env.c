/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dms_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:31:44 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/08 07:36:51 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dms_putenv(char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i++])
		ft_printf("\x1b[33m%d: \x1b[44m%s\x1b[0m\n", i, envp[i - 1]);
}
