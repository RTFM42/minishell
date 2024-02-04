/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 11:00:00 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/20 11:00:00 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	**psr_status_raw(void)
{
	static char	*str = NULL;

	return (&str);
}

void	psr_status_init(void)
{
	char	**str;

	str = psr_status_raw();
	if (*str)
		free(*str);
	*str = NULL;
}

char	*psr_status_set(char *stats)
{
	char	**str;
	char	*tmp;

	str = psr_status_raw();
	if (*str)
	{
		tmp = *str;
		*str = ft_strjoin(*str, stats);
		free(tmp);
	}
	else
		*str = ft_strdup(stats);
	return (*str);
}

char	*psr_status_get(void)
{
	char	*str;

	str = *psr_status_raw();
	return (str);
}