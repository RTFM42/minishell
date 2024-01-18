/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:50 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 18:15:50 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../../builtin.h"

bool	option_n(char *str)
{
	if (str && str[0] == '-' && str[1] == 'n' && str[2] == '\0')
		return (true);
	return (false);
}

int	echo_command(char **argv)
{
	size_t	i;

	i = 1;
	while (option_n(argv[i]) == true)
		i++;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (option_n(argv[1]) == false)
		printf("\n");
	env_update("?", "0");
	return (EXIT_SUCCESS);
}
