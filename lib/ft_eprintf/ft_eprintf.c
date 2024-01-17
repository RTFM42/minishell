/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:46:20 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/17 21:38:10 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eprintf.h"
#include <stdio.h> 

static int	is_include(char c, char *s)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

int	ft_eprintf(char *fmt, ...)
{
	va_list	ap;
	int		flag;
	int		len;

	va_start(ap, fmt);
	len = 0;
	while (*fmt != '\0')
	{
		if (fmt[0] == '%' && fmt[1] != '\0')
		{
			flag = is_include(fmt[1], "cspdiuxX%");
			if (flag)
			{
				len = ex_uadd(len, ex_putva_fd((const char)fmt[1], &ap, 2));
				fmt += 2;
			}
			else
				len = ex_uadd(len, ex_putchar_fd(*fmt++, 2));
		}
		else
			len = ex_uadd(len, ex_putchar_fd(*fmt++, 2));
	}
	va_end(ap);
	return (len);
}
