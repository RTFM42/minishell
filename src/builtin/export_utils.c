/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:43:23 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/15 18:09:37 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"
//envsortascii
void	export_print_env()
{
	const t_env	*env = *(env_store());

	while (env)
	{
		if (env->name && env->value && *env->name != 63)
			printf("declare -x %s=%s\n", env->name, env->value);
		else if (env->name && *env->name != 63)
			printf("declare -x %s\n", env->name);
		env = env->next;
	}
}

// bool	check_plus_equal(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strnstr(str, "+=", ft_strlen(str)))
// 	{
// 		while (str[i] != '+')
// 		{
// 			if (str[i] == '=')
// 				return (false);
// 			i++;
// 		}
// 		return (true);
// 	}
// 	else
// 		return (false);
// }
