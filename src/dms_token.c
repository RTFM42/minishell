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
	while (chain)
	{
		ft_printf("type: %s\n", chain->type);
		ft_printf("str:  %s\n", chain->str);
		ft_printf("----------\n");
		chain = chain->next;
	}
}
