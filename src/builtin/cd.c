/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:41 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 15:36:18 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

bool	sarch_path(char **argv)
{
	int	i;

	if (!argv[1] || argv[1][0] == '/')
		return (false);
	i = 1;
	while (argv[i])
	{
		if (ft_strncmp(argv[i], ".", 2) == 0
			|| ft_strncmp(argv[i], "..", 2) == 0
			|| ft_strncmp(argv[i], "./", 2) == 0
			|| ft_strncmp(argv[i], "../", 3) == 0)
			return (false);
		i++;
	}
	return (true);
}

int	check_file_permission(const char *path)
{
	if (access(path, F_OK) != -1)
	{
		if (access(path, R_OK) == 0)
			printf("Read permission is granted.\n");
		else
		{
			ft_eprintf("Read permission denied.\n");
			return (EXIT_FAILURE);
		}
		if (access(path, W_OK) == 0)
			printf("Write permission is granted.\n");
		else
			ft_eprintf("Write permission denied.\n");
		{
			return (EXIT_FAILURE);
		}
		if (access(path, X_OK) == 0)
			printf("Execute permission is granted.\n");
		else
		{
			ft_eprintf("Execute permission denied.\n");
			return (EXIT_FAILURE);
		}
	}
	else
	{
		ft_eprintf("File not found.\n");
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

static void	cd_home(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (home_dir && chdir(home_dir) == 0)
		return ;
	else
		cd_error();
}

int	change_current_dir(const char *path)
{
	char	*cur_dir;

	if (chdir(path) != 0)
		cd_error();
	cur_dir = getcwd(NULL, 0);
	if (cur_dir == NULL)
		cd_error();
	free(cur_dir);
	return (EXIT_SUCCESS);
}

int	cd_command(char **argv)
{
	if (argv[1])
		check_file_permission(argv[1]);
	if (!argv[1])
		cd_home();
	if (chdir(argv[1]) != 0)
		cd_error();
	env_update("?", "0");
	return (EXIT_SUCCESS);
}
