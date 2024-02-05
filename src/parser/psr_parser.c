/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:58:19 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/18 14:58:21 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../builtin.h"

static char	*psr_doll(char *cache, char **pstr)
{
	char	*tmp;
	char	*env;
	char	*str;
	t_env	*tenv;

	str = *pstr;
	if (*str != '$')
		return (ft_strdup(cache));
	if (*(str + 1) == '?' || *(str + 1) == '@')
		env = ft_strnjoin("", str + 1, 1);
	else
	{
		env = ft_strdup("");
		while (*++str && (*str == '_' || ft_isalnum(*str)))
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

static char	*psr_2quote(char *cache, char **pstr)
{
	char	*tmp;
	char	*str;

	str = 1 + (*pstr);
	cache = ft_strdup(cache);
	while (*str != '"')
	{
		tmp = cache;
		if (*str == '\0' && psr_status_set("Syntax error: `\"' unexpected\n"))
			return (cache);
		if ((!ft_memcmp(str, "\\\\", 2) || !ft_memcmp(str, "\\\"", 2)
				|| !ft_memcmp(str, "\\\'", 2) || !ft_memcmp(str, "\\$", 2)))
		{
			cache = ft_strnjoin(cache, ++str, 1);
			str++;
		}
		else if (!ft_memcmp(str, "$", 1) && *(str + 1)
			&& (*(str + 1) == '_' || ft_isalnum(*(str + 1))))
			cache = psr_doll(cache, &str);
		else
			cache = ft_strnjoin(cache, str++, 1);
		free(tmp);
	}
	*pstr = ++str;
	return (cache);
}

static char	*psr_1quote(char *cache, char **pstr)
{
	char	*tmp;
	char	*str;

	str = *pstr;
	if (*str != '\'')
	{
		psr_status_set("psr_1quote: First letter is not \"'\".\n");
		return (ft_strdup(cache));
	}
	cache = ft_strdup(cache);
	while (*++str != '\'')
	{
		if (*str == '\0' && psr_status_set("Syntax error: `\'' unexpected\n"))
			return (cache);
		tmp = cache;
		cache = ft_strnjoin(cache, str, 1);
		free(tmp);
	}
	*pstr = ++str;
	return (cache);
}

t_token	*psr_parser(t_token *chain)
{
	char	*str;
	char	*cache;
	char	*tmp;

	if (!(chain == NULL || ft_memcmp(chain->type, "header", 6)))
	{
		chain = chain->next;
		psr_status_init();
		while (chain && chain->str)
		{
			str = chain->str;
			cache = ft_calloc(1, sizeof(char));
			while (*str && !psr_status_get())
			{
				tmp = cache;
				if (!ft_memcmp(str, "\\", 1) && ++str)
				{
					if (*str == '\0'
						&& psr_status_set("Syntax error: `\\' unexpected\n"))
						break ;
					else
						cache = ft_strnjoin(cache, str++, 1);
				}
				else if (!ft_memcmp(str, "\\", 1))
					cache = ft_strnjoin(cache, str++, 1);
				else if (!ft_memcmp(str, "\"", 1))
					cache = psr_2quote(cache, &str);
				else if (!ft_memcmp(str, "\'", 1))
					cache = psr_1quote(cache, &str);
				else if (!ft_memcmp(str, "$", 1) && *(str + 1)
					&& (*(str + 1) == '_' || ft_isalnum(*(str + 1))))
					cache = psr_doll(cache, &str);
				else if (*str)
					cache = ft_strnjoin(cache, str++, 1);
				else
					cache = ft_strdup(cache);
				free(tmp);
			}
			free(chain->str);
			chain->str = cache;
			chain = chain->next;
		}
		if (psr_status_get())
			printf("%s", psr_status_get());
	}
	return (NULL);
}
