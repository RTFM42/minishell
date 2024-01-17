/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:44:16 by yushsato          #+#    #+#             */
/*   Updated: 2023/10/15 21:47:39 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_list)
{
	t_list	*tmp;

	if (!new_list || !lst)
		;
	else if (!*lst)
		*lst = new_list;
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new_list;
	}
}
