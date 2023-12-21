/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:56:29 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/16 21:25:27 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lib.h"

void	ms_shell(void)
{
	char	*line;
	t_token	*token;

	line = NULL;
	line = ms_readline();
	token = ms_lexer(line);
	ms_exec(token);
	free(line);
}
