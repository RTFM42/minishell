/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:04 by nsakanou          #+#    #+#             */
/*   Updated: 2024/03/22 19:18:56 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"
//与えられた文字列が数字のみから構成されるかどうかをチェック
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
//true　数字のみ、 false　数字以外

// bool	check_exit_args(char **argv)
// {
// 	size_t	i;
// 	size_t	argc;

// 	i = 0;
// 	argc = 0;
// 	while (argv[argc])
// 		argc++;
// 	while (i < argc)
// 	{
// 		if (isdigit_str(argv[i])
// 			&& !ft_isalpha(argv[i + 1][0]))
// 			return (true);
// 		else if (ft_isalpha(argv[i][0]))
// 			return (true);
// 		else if (isdigit_str(argv[i])
// 			&& ft_isalpha(argv[i + 1][0]))
// 			return (false);
// 		i++;
// 	}
// 	return (false);
// }
//true->exitできる、 false->exitできない

static int	check_exit_args(char **argv)
{
	int	argc;
	int	i;
	int	status;

	i = 1;
	argc = 1;
	status = 0;
	while (argv[argc])
		argc++;
	while (i < argc)
	{
		if (isdigit_str(argv[i]) && argv[i + 1])//exit 2
			status = i;//exit 256以上の処理を入れる(メモみる)
		else if ((ft_isalpha(argv[1][0]) && ft_isdigit(argv[i + 1][0]))
			|| (ft_isdigit(argv[1][0]) && ft_isalnum(argv[1][1])))//exit a 3 5, exit a 3asd, exit 234sdfg
		{
			printf("numeric argument required\n");
			status = 255;
		}
		else if (isdigit_str(argv[i])
			&& ft_isalpha(argv[i + 1][0]))
		{
			ft_eprintf("argument error.\n");
			return (false);
		}
		i++;
	}
	return (status);
}

/*
exitできない
→exit 1 2, exit 1 a   :too many arguments最初の引数が数字だとexitしない
→exit a d s    ：numeric argument required引数に数字がないとexitできない
*/

/*
exitできる
→exit 234sdfg, exit 12qwer 2 4 :numeric argument required   status 255
→exit a 3 5  :numeric argument required  status 255
→exit 255   :status 255
→exit   :status 0
*/

int	exit_command(char **argv)
{
	size_t	i;
	int		status;
	t_env	*def;

	i = 0;
	status = 0;
	if (argv[i + 1])//exitのみ
		exit(0);
	if (!isdigit_str(*argv))//exit a d s
		printf("numeric argument required\n");
	if (isdigit_str(*argv))//exit 1 2
		printf("too many arguments\n");
	if (check_exit_args(argv))
		exit(status);
	else
	{
		def = env_search(*(env_store()), "?");
		if (def == NULL)
			exit(0);
		exit(ft_atoi(def->value));
	}
	ft_eprintf("argument error.\n");
	return (EXIT_FAILURE);
}
