/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:30:40 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/15 09:18:33 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ms_setsignal(void)
{
	signal(SIGINT, sigint);
	signal(SIGQUIT, SIG_IGN);
}

// void	ms_isctrld(char *stdin, char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i] && ft_memcmp(env[i], "?=", 2))
// 		i++;
// 	if (stdin == NULL)
// 	{
// 		ft_printf("exit\n");
// 		if (env[i] == NULL)
// 			exit(0);
// 		exit(ft_atoi(env[i] + 2));
// 	}
// }

void	ms_isctrld(char *stdin)
{
	if (stdin == NULL)
	{
		ft_printf("exit\n");
		exit(0);
	}
}
