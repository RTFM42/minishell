/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:56 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/02 16:25:54 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	char	*input;

	(void)ac;
	(void)av;
	input = NULL;
	ms_envinit(envp);
	while (1)
	{
		signal(SIGINT, ms_siginthandler);
		signal(SIGQUIT, SIG_IGN);
		input = ms_strset(input, ms_readshell("minishell> "));
		ft_printf("res: %s\n", input);
	}
	free(input);
}
