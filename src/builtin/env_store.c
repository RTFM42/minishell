/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_store.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:50:07 by yushsato          #+#    #+#             */
/*   Updated: 2024/01/13 17:54:34 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static t_env	**envstore()
{
	static t_env	**chain;
	
	return (chain);
}

t_env	*env_getptr()
{
	return (*envstore());
}
