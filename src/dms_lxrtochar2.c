/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dms_execbuiltin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:04:32 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/13 17:05:00 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	chainlen(t_token *chain)
{
	int	i;

	i = 0;
	while (chain)
	{
		i++;
		chain = chain->next;
	}
	return (i);
}

char	**dms_lxrtochar2(t_token *chain)
{
	char	**ary;
	int		i;

	if (chain == NULL && ft_memcmp(chain->type, "header", 6))
		return (0);
	chain = chain->next;
	ary = (char **)ft_calloc(chainlen(chain) + 1, sizeof(char *));
	while (chain)
	{
		ary[i++] = ft_strdup(chain->str);
		chain = chain->next;
	}
	return (ary);
}
