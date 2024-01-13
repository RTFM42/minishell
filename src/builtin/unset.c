/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:20 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 21:27:05 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
test1=123
echo $test1
123
unset teset1
echo $test1

↑削除されたことが確認できる


bashで定義した変数や関数を削除するコマンド [unset 変数名] 環境変数を削除
環境変数の識別子
１ 英字（大文字または小文字）、数字、およびアンダースコア _ 
	ただし、最初の文字は数字ではない.
2 大文字と小文字を区別 ex)PATH と Path は異なる環境変数

同じ名前の関数と変数があった場合、変数を削除
*/

#include "../../builtin.h"

int	unset_command(char **argv)
{
	size_t	i;
	t_env	*env;

	env = *(env_store());
	i = 1;
	while (argv[i])
	{
		if (env_name_judge(argv[i]) == true)
			env_del(&env, argv[i]);
		else
			strerror(errno);
		i++;
	}
	env_update("?", "0");
	return (EXIT_SUCCESS);
}

/*
bash-3.2$ export a=gggggggggggggggggggggg
bash-3.2$ export b=zzzzzzzzzzzzzzzzz

bash-3.2$ unset a 2 = b 2
bash: unset: `2': not a valid identifier
bash: unset: `=': not a valid identifier
bash: unset: `2': not a valid identifier

bash-3.2$ env | grep zzzzzzzzzzzzzzzzz
bash-3.2$ export b=zzzzzzzzzzzzzzzzz
bash-3.2$ env | grep zzzzzzzzzzzzzzzzz
b=zzzzzzzzzzzzzzzzz
bash-3.2$ unset a 2 = b 2
bash: unset: `2': not a valid identifier
bash: unset: `=': not a valid identifier
bash: unset: `2': not a valid identifier
bash-3.2$ echo $?
1
*/
