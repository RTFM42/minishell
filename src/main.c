/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:07:56 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/18 17:59:18 by nsakanou         ###   ########.fr       */
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
	int		ret;
	char	**strs;

	if (chain == NULL || ft_memcmp(chain->type, "header", 6))
		return (0);
	strs = dms_lxrtochar2(chain);
	ret = 0;
	if (exec_builtin(strs) != 256)
		ret++;
	freestrs(strs);
	return (ret);
}

int	main(int ac, char **av, char **envp)
{
	char	*line;
	t_token	*chain;
	char	*save;

	(void)ac;
	(void)av;
	save = ft_calloc(1, PATH_MAX);
	getcwd(save, PATH_MAX);
	env_create(envp);
	pwd_command(save);
	free(save);
	while (1)
	{
		ms_setsignal();
		line = readline("minishell$ ");
		ms_isctrld(line);
		chain = lxr_lexer(line);
		if (test(chain))
			continue ;
		dms_putchain(chain);
		dms_putenv();
		free(line);
		ms_token_free(chain);
	}
	return (0);
}
