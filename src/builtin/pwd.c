/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:15 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/20 13:25:31 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

int	pwd_command(char *init)
{
	char		*pwd;
	static char	*save;
	char		*tmp;

	pwd = ft_calloc(1, PATH_MAX);
	if (init)
		save = ft_strdup(init);
	else if (getcwd(pwd, PATH_MAX) != NULL)
	{
		tmp = save;
		save = ft_strdup(pwd);
		printf("%s\n", pwd);
		if (!tmp)
			free(tmp);
	}
	else if (!printf("%s\n", save))
	{
		free(pwd);
		env_update("?", "1");
		return (EXIT_FAILURE);
	}
	free (pwd);
	env_update("?", "0");
	return (EXIT_SUCCESS);
}
