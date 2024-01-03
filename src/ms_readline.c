/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 16:26:07 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/02 19:05:55 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ms_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	len1 = 0;
	len2 = 0;
	if (s1 != NULL)
		len1 = ft_strlen(s1);
	if (s2 != NULL)
		len2 = ft_strlen(s2);
	ret = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!ret)
		return (0);
	ft_bzero(ret, len1 + len2 + 1);
	ft_memcpy(ret, s1, len1);
	ft_memcpy(ret + len1, s2, len2);
	return (ret);
}

char	*ms_readline(char *str)
{
	char	*buf;
	char	*tmp;
	char	*line;
	int		res;

	ft_printf("%s", str);
	buf = ft_calloc(2, sizeof(char));
	line = NULL;
	while (1)
	{
		res = read(0, buf, 1);
		if (res == 0)
			exit(1);
		if (*buf == '\n')
			break ;
		tmp = line;
		line = ms_strjoin(line, buf);
		free(tmp);
	}
	free(buf);
	return (line);
}
