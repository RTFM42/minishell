/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:24:24 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/12 16:46:02 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lib.h"

char	*ms_readline(void)
{
	char	*line;

	line = readline("minishell> ");
	if (line == NULL)
	{
		write(1, "-minishell: Cannot allocate memory.\n", 36);
		exit(1);
	}
	return (line);
}
