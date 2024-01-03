/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_readshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:45:23 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/04 02:32:52 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @param quote // 'a':` or 's':' or 'd':" or NULL
 */

char	*ms_readshell(char *str)
{
	char	*input;
	char	*tmp;
	char 	*line;
	int		i;

	input = NULL;
	i = -1;
	input = ms_strset(input, ms_readline(str));
	while (input[++i])
	{
		if (!ft_memcmp(&input[i], "\\\\", 2)
			|| !ft_memcmp(&input[i], "\\\"", 2))
			i++;
		else if (input[i] == '"')
		{
			while (input[++i] != '"')
			{
				if (!ft_memcmp(&input[i], "\\\\", 2)
					|| !ft_memcmp(&input[i], "\\\"", 2))
					i++;
				else if (input[i] == '\0')
				{
					tmp = input;
					input = ft_strjoin(input, "\n");
					free(tmp);
					line = ms_readline("> ");
					if (line != NULL)
					{
						tmp = input;
						input = ft_strjoin(input, line);
						free(tmp);
						free(line);
					}
				}
			}
		}
	}
	return (input);
}
