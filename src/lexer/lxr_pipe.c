/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:21 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/05 16:22:22 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	lxr_pipe(char *str, t_token *chain)
{
	if (!str || !*str)
		return (0);
	if (!ft_memcmp(str, "|", 1))
	{
		ms_token_add(chain, ms_token_new(str, 1, "|"));
		return (1);
	}
	return (0);
}
