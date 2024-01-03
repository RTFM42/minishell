/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:51:35 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/03 16:53:03 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ms_strset(char *dest, char *src)
{
	if (dest != NULL)
		free(dest);
	dest = NULL;
	if (src != NULL)
		dest = ft_strdup(src);
	return (dest);
}
