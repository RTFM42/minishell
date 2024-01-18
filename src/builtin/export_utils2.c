/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:15:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 15:39:11 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

char	*export_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (s1 == NULL)
		len1 = 0;
	else
		len1 = ft_strlen(s1);
	if (s2 == NULL)
		len2 = 0;
	else
		len2 = ft_strlen(s2);
	ret = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!ret)
		return (0);
	ft_bzero(ret, len1 + len2 + 1);
	ft_memcpy(ret, s1, len1);
	ft_memcpy(ret + len1, s2, len2);
	return (ret);
}

char	check_type(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return ('=');
		else if (str[i] == '+' && str[i + 1] == '=')
			return ('+');
		i++;
	}
	return (0);
}