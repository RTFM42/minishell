/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:18:44 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/17 21:38:46 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EPRINTF_H
# define FT_EPRINTF_H
# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include "extra/extra.h"

int	ft_eprintf(char *fmt, ...);

#endif
