/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psr_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:58:01 by yushsato          #+#    #+#             */
/*   Updated: 2024/03/08 23:39:32 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*psr_toslash(char *str)
{
	char	*cache;
	char	*tmp;
	char	*cpy;

	cpy = str;
	cache = ft_strdup("");
	while (*str)
	{
		tmp = cache;
		if (*str != ' ')
		{
			cache = ft_strnjoin(cache, "\\", 1);
			free(tmp);
			tmp = cache;
			if (*str == '\\' && *(str + 1) != '\0')
				str++;
		}
		cache = ft_strnjoin(cache, str++, 1);
		free(tmp);
	}
	free(cpy);
	return (cache);
}

static char	*psr_doll(char *cache, char **pstr)
{
	char	*tmp;
	char	*env;
	char	*str;
	t_env	*tenv;

	str = *pstr;
	if ((*(str + 1) == '?' || *(str + 1) == '@') && str++)
		env = ft_strnjoin("", str++, 1);
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
	tenv = env_search(*env_store(), env);
	free(env);
	if (ft_memcpy(pstr, &str, sizeof(void *)) &&  tenv)
		cache = ft_strjoin(tenv->value, cache);
	else
		cache = ft_strdup(cache);
	return (cache);
}

static char	*psr_2quote(char *cache, char **pstr)
{
	char	*tmp;
	char	*str;

	str = *pstr;
	cache = ft_strdup(cache);
	while (*++str != '\"')
	{
		if (*str == '\0')
		{
			*pstr = str;
			return (cache);
		}
		tmp = cache;
		cache = ft_strnjoin(cache, str, 1);
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
	cache = ft_strdup(cache);
	while (*++str != '\'')
	{
		if (*str == '\0')
		{
			*pstr = str;
			return (cache);
		}
		tmp = cache;
		cache = ft_strnjoin(cache, str, 1);
		free(tmp);
	}
	*pstr = ++str;
	return (cache);
}

char	*psr_env(char *str)
{
	char	*cache;
	char	*tmp;
	int		ignore;

	cache = ft_strdup("");
	while (*str)
	{
		tmp = cache;
		if (str[i] == '\\' && str[i + 1])
		{			
			cache = ft_strnjoin(cache, str, 2);
			str += 2;
		}
		else if (str[i] == '\'')
			cache = psr_1quote(cache, &str);
		else if (str[i] == '\"')
			cache = psr_2quote(cache, &str);
		else if (str[i] == '$')
			cache = psr_doll(cache, &str);
		else
			cache = ft_strnjoin(cache, str++, 1);
		free(tmp);
		str++;
	}
	return (cache);
}
