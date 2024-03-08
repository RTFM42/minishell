/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lxr_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:18 by yushsato          #+#    #+#             */
/*   Updated: 2024/03/08 21:41:25 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	lxr_1quote(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '\'')
		return (0);
	while (str[i])
	{
		if (!ft_memcmp(&str[i], "'", 1))
			break ;
		else
			i += 1;
	}
	if (str[i])
		i++;
	return (i);
}

static int	lxr_2quote(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '\"')
		return (0);
	while (str[i])
	{
		if (!ft_memcmp(str + i, "\\\\", 2))
			i += 2;
		else if (!ft_memcmp(str + i, "\\\"", 2))
			i += 2;
		else if (!ft_memcmp(str + i, "\"", 1))
			break ;
		else
			i += 1;
	}
	if (str[i])
		i++;
	return (i);
}

int	lxr_token(char *str, t_token *chain)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '>' || str[i] == '<' || str[i] == '|'
			|| str[i] == ';')
			break ;
		else if (str[i] == '\"')
			i += lxr_2quote(&str[i]);
		else if (str[i] == '\'')
			i += lxr_1quote(&str[i]);
		else if (str[i] == '\\')
			i += 2;
		else
			i++;
	}
	ms_token_add(chain, ms_token_new(str, i, "token"));
	return (i);
}
