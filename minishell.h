/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:26 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/04 00:35:18 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"

/**
 * @param sstr // this param will have not encoded strring (example: "\\\"")
 * @param dstr // this param will have encoded string (example: \")
*/

typedef struct s_token
{
	char			*str;
	char			*type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

char	**g_env;

int		ms_2dimlen(char **str);
void	ms_envinit(char **envs);
char	*ms_readline(char *str);
char	*ms_readshell(char *str);
void	ms_siginthandler(int signo);
char	*ms_strset(char *dest, char *src);

#endif
