/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dms_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:01:16 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/07 16:04:33 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	dms_putchain(t_token *chain)
{
	ft_printf("\x1b[33m----------\x1b[0m\n");
	while (chain)
	{
		ft_printf("\x1b[33mtype: \x1b[44m%s\x1b[0m\n", chain->type);
		ft_printf("\x1b[33mstr:  \x1b[44m%s\x1b[0m\n", chain->str);
		ft_printf("\x1b[33m----------\x1b[0m\n");
		chain = chain->next;
	}
}
