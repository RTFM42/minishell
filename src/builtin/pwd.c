/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:15 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 20:09:15 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

int	pwd_command(void)
{
	char	*pwd;

	pwd = ft_calloc(1, PATH_MAX);//mallocしなくてもいいらしい
	if (getcwd(pwd, PATH_MAX) != NULL)
		printf("%s\n", pwd);
	else
	{
		strerror(errno);
		free(pwd);
		env_update("?", "1");
		return (EXIT_FAILURE);
	}
	free (pwd);
	env_update("?", "0");
	return (EXIT_SUCCESS);
}

// int	main()
// {
// 	pwd_command();
// 	return 0;
// }

/*
getcwd: 現在の作業ディレクトリの絶対パスを取得
char *getcwd(char *buffer, size_t size);
・PATH_MAX (#include <limits.h>)ファイルパス用にメモリを確保するために十分な大きさだが、
必ずしも最適なサイズであるとは限らない。
　↓
getcwd 関数が返すパスの長さは、現在の作業ディレクトリに依存するため、
PATH_MAX が実際に必要なサイズよりも大きすぎる可能性がある。
逆に小さすぎる場合はメモリの不足が発生。
このため、適切なサイズを確保するためには、実際のパスの長さを取得することが望ましい
*/
