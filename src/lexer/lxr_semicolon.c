/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr_semicolon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:15:59 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/08 00:16:00 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	lxr_semicolon(char *str, t_token *chain)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (!ft_memcmp(str, ";", 1))
	{
		ms_token_add(chain, ms_token_new(str, 1, ";"));
		return (1);
	}
	return (0);
}
