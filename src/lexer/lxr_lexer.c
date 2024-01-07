/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 03:07:45 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/05 15:22:17 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*lxr_lexer(char *str)
{
	t_token	*chain;
	int		i;

	if (str == NULL || *str == '\0')
		return (NULL);
	i = 0;
	chain = ms_token_new(str, 0, "header");
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if (str[i] == '>' || str[i] == '<')
			i += lxr_redirect(&str[i], chain);
		else if (str[i] == '|')
			i += lxr_pipe(&str[i], chain);
		else
			i += lxr_token(&str[i], chain);
	}
	return (chain);
}
