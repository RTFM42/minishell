/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_siginthandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 02:37:14 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/02 02:40:06 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_siginthandler(int signo)
{
	if (signo == SIGINT)
	{
		ft_printf("\nminishell> ");
		signal(SIGINT, ms_siginthandler);
	}
}
