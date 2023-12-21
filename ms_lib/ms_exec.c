/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:43:46 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/21 20:43:47 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lib.h"

void	ms_exec(t_token *token)
{
	char	*cmdloc;
	char	**cmdopt;
	int		i;

	if (token)
	{
		cmdloc = ft_strjoin("/bin/", token->value);
		token = token->next;
		cmdopt = ft_calloc(ms_tokenlen(token) + 1, sizeof(char *));
		i = 0;
		while (token)
		{
			cmdopt[i++] = ft_strdup(token->value);
			token = token->next;
		}
		execve(cmdloc, cmdopt, NULL);
		free(cmdloc);
		ms_strsfree(cmdopt);
	}
}
