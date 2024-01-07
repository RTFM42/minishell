/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr_redirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:27 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/05 16:22:29 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	lxr_redirect(char *str, t_token *chain)
{
	if (!str || !*str)
		return (0);
	if (!ft_memcmp(str, ">>", 2))
	{
		ms_token_add(chain, ms_token_new(str, 2, ">>"));
		return (2);
	}
	if (!ft_memcmp(str, "<<", 2))
	{
		ms_token_add(chain, ms_token_new(str, 2, "<<"));
		return (2);
	}
	if (!ft_memcmp(str, ">", 1))
	{
		ms_token_add(chain, ms_token_new(str, 1, ">"));
		return (1);
	}
	if (!ft_memcmp(str, "<", 1))
	{
		ms_token_add(chain, ms_token_new(str, 1, "<"));
		return (1);
	}
	return (0);
}
