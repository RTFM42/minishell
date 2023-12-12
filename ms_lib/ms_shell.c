/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:56:29 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/12 17:21:25 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_lib.h"

void	ms_shell(void)
{
	char	*line;

	line = ms_readline();
	ft_printf("%s", line);
}
