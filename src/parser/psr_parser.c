/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 19:30:58 by yushsato          #+#    #+#             */
/*   Updated: 2024/03/08 20:59:26 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*psr_parser(t_token *chain)
{
	// char	*str;
	t_token	*head;

	head = chain;
	// if (!(chain == NULL || ft_memcmp(chain->type, "header", 6)))
	// {
	// 	chain = chain->next;
	// 	psr_status_init();
	// 	while (chain && chain->str)
	// 	{
	// 		str = chain->str;
	// 		cache = ft_calloc(1, sizeof(char));
	// 		while (*str && !psr_status_get())
	// 		{
	// 			tmp = cache;
	// 			if (!ft_memcmp(str, "\\\0", 1) && ++str
	// 				&& psr_status_add("Syntax error: `\\' unexpected\n"))
	// 				cache = ft_strdup(cache);
	// 			else if (!ft_memcmp(str, "\\", 1) && ++str)
	// 				cache = ft_strjoin(cache, str++, 1);
	// 			else if (!ft_memcmp(str, "\'", 1))
	// 				cache = psr
	// 		}
	// 	}
	// }
	return (head);
}
