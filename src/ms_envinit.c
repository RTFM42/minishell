/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_envinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 02:20:38 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/02 02:28:27 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_envinit(char **env)
{
	int	i;

	i = 0;
	g_env = ft_calloc(ms_2dimlen(env) + 1, sizeof(char *));
	while (env[i])
	{
		g_env[i] = ft_strdup(env[i]);
		i++;
	}
}
