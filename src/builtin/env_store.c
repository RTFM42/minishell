/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:50:07 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/13 18:00:36 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

t_env	**env_store()
{
	static t_env	**chain;
	
	return (chain);
}