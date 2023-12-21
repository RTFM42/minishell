/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:39:14 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/21 19:39:15 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lib.h"

t_token	*ms_lexer(char *value)
{
	t_token	*token;
	t_token	*current;
	char	**split;
	int		i;

	token = NULL;
	split = ft_split(value, ' ');
	i = -1;
	while (split[++i])
	{
		current = ft_calloc(1, sizeof(t_token));
		current->prev = token;
		if (token)
			token->next = current;
		current->type = ft_strdup("TOKEN");
		current->value = ft_strdup(split[i]);
		token = current;
	}
	free(split);
	while (token->prev)
		token = token->prev;
	return (token);
}
