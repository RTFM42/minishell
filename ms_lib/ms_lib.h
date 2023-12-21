/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:23:09 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/12 18:22:01 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_LIB_H
# define MS_LIB_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_token
{
	struct s_token	*next;
	struct s_token	*prev;
	char			*type;
	char			*value;
}	t_token;

void	ms_exec(t_token *token);
t_token	*ms_lexer(char *value);
char	*ms_readline(void);
void	ms_shell(void);
int		ms_tokenlen(t_token *token);
void	ms_strsfree(char **strs);

#endif
