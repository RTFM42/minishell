/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokensfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:10:43 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/21 20:10:45 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lib.h"

void	ms_tokensfree(t_token *token)
{
	t_token	*tmp;

	while (token->prev)
		token = token->prev;
	while (token)
	{
		tmp = token->next;
		free(token->type);
		free(token->value);
		free(token);
		token = tmp;
	}
}
