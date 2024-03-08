/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:26 by yushsato          #+#    #+#             */
/*   Updated: 2024/03/08 20:08:02 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/ft_eprintf/ft_eprintf.h"

int	g_signal;

typedef struct s_token
{
	char			*str;
	int				len;	
	char			*type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

void	dms_putchain(t_token *chain);
void	dms_putenv(void);
char	**dms_lxrtochar2(t_token *chain);

void	ms_setsignal(void);
void	ms_isctrld(char *stdin);
t_token	*ms_token_add(t_token *chain, t_token *new);
t_token	*ms_token_free(t_token *chain);
t_token	*ms_token_last(t_token *chain);
t_token	*ms_token_new(char *str, int len, const char *type);
t_token	*lxr_lexer(char *str);
int		lxr_pipe(char *str, t_token *chain);
int		lxr_redirect(char *str, t_token *chain);
int		lxr_semicolon(char *str, t_token *chain);
int		lxr_token(char *str, t_token *chain);
void	psr_error_init(void);
char	*psr_error_set(char *stats);
char	*psr_error_get(void);
t_token	*psr_parser(t_token *chain);

#endif
