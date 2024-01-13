/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:04 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 20:18:04 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"
//+,-も含めて判定、空白もスキップしてる
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
	if (str[i] == '\0' && flag == 0) // 余分な文字がなく、数字があれば true を返す
		return (true);
	else
		return (false);
}

//exitできない場合->false, exitできる場合->true
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
		else if (ft_isalpha(argv[i][0])) //exit a 1 2->すぐexit
			return (true);
		else if (isdigit_str(argv[i])
			&& ft_isalpha(argv[i + 1][0])) //exit 1 a s->exitできない
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
	if (argv[i + 1] || !isdigit_str(argv[i])) //現在の引数が数字の文字列でない
		exit(255);
	else if (!check_exit_args(argv)) //falseのとき
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

/*
exit 255
echo $?
255

exit 256
echo $?
0

exit a 1 2とか, exit a 1 s d 2とかexitの最初の引数が数字じゃなかったらすぐexit
echo $?
255

bash-3.2$ exit -1
exit
c1r19s7% echo $?
255
c1r19s7% bash
bash-3.2$ exit --1
exit
bash: exit: --1: numeric argument required
c1r19s7% echo $?
255


----exit 1 aはexitできない----
bash-3.2$ exit 1 a s
exit
bash: exit: too many arguments
bash-3.2$ echo $?
1


----exit &はexitできない----
bash-3.2$ exit &
[1] 71847
bash-3.2$ echo $?
0
[1]+  Done                    exit

bash-3.2$ exit 1 &
[1] 71741
bash-3.2$ echo $?
0
[1]+  Exit 1                  exit 1

bash-3.2$ exit a &
[1] 71994
bash-3.2$ bash: exit: a: numeric argument required <-ここで固まる。enterを押したら下のようになる。

[1]+  Exit 255                exit a

----exitされない----
bash-3.2$ exit >
bash: syntax error near unexpected token `newline'
bash-3.2$ echo $?
258
*/

// #include <stdio.h>
// #include <stdlib.h>
// # include <stdbool.h>
// # include <string.h>
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <limits.h>
// # include <errno.h>
// # include <ctype.h>
// # include "libft.h"

// extern int exit_command(char **argv);

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         fprintf(stderr, "Usage: %s <exit_code>\n", argv[0]);
//         return 1;

//     char *exit_argv[] = {argv[0], argv[1], NULL};
//     exit_command(exit_argv);

//     printf("This line will not be reached if exit_command works correctly.\n");
// 	}
// 	return 0;
// }
