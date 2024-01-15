/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:21:50 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/15 09:34:55 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	psr_parser(t_token *chain)
{
	if (chain == NULL || ft_memcmp(chain->type, "header", 6))
		return (NULL);
	
}
