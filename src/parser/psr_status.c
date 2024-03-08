/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:00:00 by yushsato          #+#    #+#             */
/*   Updated: 2024/03/08 20:07:29 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	**psr_error_raw(void)
{
	static char	*str = NULL;

	return (&str);
}

void	psr_error_init(void)
{
	char	**str;

	str = psr_error_raw();
	if (*str)
		free(*str);
	*str = NULL;
}

char	*psr_error_add(char *stats)
{
	char	**str;
	char	*tmp;

	str = psr_error_raw();
	if (*str)
	{
		tmp = *str;
		*str = ft_strjoin(*str, stats);
		free(tmp);
	}
	else
		*str = ft_strjoin(stats, "\n");
	return (*str);
}

char	*psr_error_get(void)
{
	char	*str;

	str = *psr_error_raw();
	return (str);
}