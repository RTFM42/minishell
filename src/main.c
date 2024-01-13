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
#include "../builtin.h"

static int	freestrs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (0);
}

static int	test(t_token *chain)
{
	char	**strs;
	if (chain == NULL || ft_memcmp(chain->type, "header", 6))
		return (0);
	if (chain->next != NULL && ft_memcmp(chain->next->str, "export", 6))
	{
		strs = dms_lxrtochar2(chain);
		freestrs(strs);
		return (1);
	}
	return (0);
}

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
		ms_isctrld(line, envp);
		chain = lxr_lexer(line);
		dms_putchain(chain);
		dms_putenv(envp);
		free(line);
		ms_token_free(chain);
	}
	return (0);
}
