/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:56 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/05 03:54:16 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_token	*chain;

	(void)ac;
	(void)av;
	ms_envinit(envp);
	while (1)
	{
		ms_setsignal();
		line = readline("minishell$ ");
		chain = lxr_lexer(line);
		dms_putchain(chain);
		free(line);
		free(chain);
	}
	return (0);
}
