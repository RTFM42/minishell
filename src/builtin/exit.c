/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:04 by nsakanou          #+#    #+#             */
/*   Updated: 2024/03/30 17:49:45 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"
//与えられた文字列が数字のみから構成されるかどうかをチェック
bool	ft_all_digit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
//true　数字のみ、 false　数字以外

static int	count_argc(char **argv)
{
	int	argc;
	int	i;

	i = 1;//exitの分
	argc = 0;
	if (argv[i + 1])//引数がある時
	{
		while (argv[argc + 1])
			argc++;
	}
	return (argc);
}

int	cannot_exit(char **argv)
{
		printf("88888");
	if (count_argc(argv) > 1 && !ft_all_digit(*argv))//exit a d s できない
		printf("numeric argument required\n");
	else if (count_argc(argv) > 1 && ft_all_digit(*argv))//exit 1 2 できない
		printf("too many arguments\n");
	return (0);
}
/*
exitできない
→exit 1 2, exit 1 a   :too many arguments最初の引数が数字だとexitしない
→exit a d s    ：numeric argument required引数に数字がないとexitできない
*/

int	can_exit(char **argv)
{
	int		status;

	status = 0;
	if (count_argc(argv) == 0) // exitのみ
		exit(0);
	else if (count_argc(argv) == 1 && ft_all_digit(*argv))// exit 1とか
	{
		printf("sdaaa\n");
		status = ft_atoi(argv[1]);
		while (status > 255)
			status = status % 255;
		exit (status);
	}
	else if (count_argc(argv) >= 1 && (ft_isalpha(argv[1][1]) || !ft_all_digit(argv[1])))//exit status 255-> exit a,exit a 3 5 exit 234sdfg, exit asd1234,
	{
		printf("111111a\n");
		printf("numeric argument required\n");
		status = 255;
		exit(status);
	}
	else
		cannot_exit(argv);
	return (0);
}
/*
exitできる
→exit 234sdfg, exit asd1234, exit 12qwer 2 4 :numeric argument required   status 255
→exit a 3 5, exit a  :numeric argument required  status 255
→exit 255   :status 255
→exit   :status 0
*/

int	exit_command(char **argv)
{
	t_env	*def;

	can_exit(argv);
	def = env_search(*(env_store()), "?");
	if (def == NULL)
		exit(0);
	exit(ft_atoi(def->value));
	ft_eprintf("argument error.\n");
	return (EXIT_FAILURE);
}
