/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:08:26 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/04 14:47:42 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	***envstore(void)
{
	static char	**envp = NULL;

	return (&envp);
}

static void	envfree(void)
{
	char	***envpp;
	char	**envp;

	envpp = envstore();
	if (*envpp)
	{
		envp = *envpp;
		while (*envp)
		{
			free(*envp);
			envp++;
		}
		free(*envpp);
		*envpp = NULL;
	}
}

char	**ms_envadd(char *new)
{
	char	***envpp;
	char	**envp;
	char	**tmpp;
	int		i;

	envpp = envstore();
	envp = *envpp;
	i = 0;
	if (envp == NULL)
		envp = ft_calloc(2, sizeof(char *));
	else
	{
		tmpp = envp;
		while (envp[i])
			i++;
		envp = ft_calloc(i + 2, sizeof(char *));
		i = -1;
		while (tmpp[++i])
			envp[i] = tmpp[i];
		free(tmpp);
	}
	envp[i] = ft_strdup(new);
	*envpp = envp;
	return (envp);
}

char	**ms_envget(void)
{
	char	***envpp;

	envpp = envstore();
	return (*envpp);
}

char	**ms_envinit(char **envp)
{
	char	**retp;

	envfree();
	retp = NULL;
	while (envp && *envp)
		retp = ms_envadd(*envp++);
	return (retp);
}
