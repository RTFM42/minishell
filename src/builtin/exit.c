/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:04 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/20 13:23:40 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

bool	isdigit_str(char *str)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_isdigit(str[i]))
			flag = 0;
		else
			break ;
		i++;
	}
	if (str[i] == '\0' && flag == 0)
		return (true);
	else
		return (false);
}

bool	check_exit_args(char **argv)
{
	size_t	i;
	size_t	argc;

	i = 0;
	argc = 0;
	while (argv[argc])
		argc++;
	while (i < argc)
	{
		if (isdigit_str(argv[i])
			&& !ft_isalpha(argv[i + 1][0]))
			return (true);
		else if (ft_isalpha(argv[i][0]))
			return (true);
		else if (isdigit_str(argv[i])
			&& ft_isalpha(argv[i + 1][0]))
			return (false);
		i++;
	}
	return (false);
}

int	exit_command(char **argv)
{
	size_t	i;
	int		status;
	t_env	*def;

	i = 0;
	if (argv[i + 1] || !isdigit_str(argv[i]))
		exit(255);
	else if (!check_exit_args(argv))
	{
		status = 255;
		exit(status);
	}
	else
	{
		def = env_search(*(env_store()), "?");
		if (def == NULL)
			exit(0);
		exit(ft_atoi(def->value));
	}
	return (EXIT_FAILURE);
}
