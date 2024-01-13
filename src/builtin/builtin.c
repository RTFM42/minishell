/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:11:27 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 19:51:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

int	exec_builtin(char **argv)
{
	if (ft_strcmp(argv[0], "echo") == 0)
		echo_command(argv);
	else if (ft_strcmp(argv[0], "cd") == 0)
		cd_command(argv);
	else if (ft_strcmp(argv[0], "pwd") == 0)
		pwd_command();
	else if (ft_strcmp(argv[0], "export") == 0)
		export_command(argv);
	else if (ft_strcmp(argv[0], "env") == 0)
		env_command();
	else if (ft_strcmp(argv[0], "exit") == 0)
		exit_command(argv);
	return (256);
}
