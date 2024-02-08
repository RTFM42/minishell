/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_doll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:17:22 by yushsato          #+#    #+#             */
/*   Updated: 2024/02/05 17:17:22 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../builtin.h"

static int	psr_isdoll(const char c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

char	*psr_doll(char *cache, char **pstr)
{
	char	*tmp;
	char	*env;
	char	*str;
	t_env	*tenv;

	str = *pstr;
	if (*str == '$' && !(psr_isdoll(*(str + 1)) || *(str + 1) == '?'))
	{
		*pstr = ++(*pstr);
		return (ft_strjoin("$", cache));
	}
	if (*(str + 1) == '?')
		env = ft_strnjoin("", str + 1, 1);
	else
	{
		env = ft_strdup("");
		while (*++str && psr_isdoll(*str))
		{
			tmp = env;
			env = ft_strnjoin(env, str, 1);
			free(tmp);
		}
	}
	*pstr = str;
	tenv = env_search(*env_store(), env);
	free(env);
	if (tenv)
		cache = ft_strjoin(tenv->value, cache);
	else
		cache = ft_strdup(cache);
	return (cache);
}
