/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:50:51 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/05 16:52:32 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ms_token_add(t_token *chain, t_token *new)
{
	t_token	*last;

	if (chain == NULL)
		return (new);
	last = ms_token_last(chain);
	last->next = new;
	new->prev = last;
	return (chain);
}

t_token	*ms_token_free(t_token *chain)
{
	t_token	*tmp;

	while (chain)
	{
		tmp = chain->next;
		free(chain->str);
		free(chain->type);
		free(chain);
		chain = tmp;
	}
	return (NULL);
}

t_token	*ms_token_last(t_token *chain)
{
	if (chain == NULL)
		return (NULL);
	while (chain->next)
		chain = chain->next;
	return (chain);
}

t_token	*ms_token_new(char *str, int len, const char *type)
{
	t_token	*new;

	new = (t_token *)ft_calloc(1, sizeof(t_token));
	new->str = ft_calloc(len + 1, sizeof(char));
	ft_memcpy(new->str, str, len);
	new->len = len;
	new->type = ft_strdup(type);
	return (new);
}
