/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:41 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/13 20:03:51 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
getcwd: 現在の作業ディレクトリを取得
getenv: ホームディレクトリを取得

j
cd ..    cd ../  ←移動　　　cd .   cd ./Desktop
cd /some/directory　←絶対パス
cd some/directory　←相対パス

cd 引数無し→homeディレクトリに移動

"cd -"の処理いる？
*/

#include "../../builtin.h"

bool	sarch_path(char **argv)
{
	int	i;

	if (!argv[1] || argv[1][0] == '/') // 相対or絶対パスで始まる
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
	return (true); // ./a.out cd Desktopとかの場合
}

/*
access関数 成功すると 0 、失敗すると -1
F_OK: ファイルが存在するかどうかを確認するフラグ。
R_OK: 読み取り権限があるかどうかを確認するフラグ。
W_OK: 書き込み権限があるかどうかを確認するフラグ。
X_OK: 実行権限があるかどうかを確認するフラグ。
*/

void	check_file_permission(const char *path)
{
	if (access(path, F_OK) != -1) // ファイルが存在する場合
	{
		if (access(path, R_OK) == 0)
			printf("Read permission is granted.\n");
		else
			perror("Read permission denied");
		if (access(path, W_OK) == 0)
			printf("Write permission is granted.\n");
		else
			perror("Write permission denied");
		if (access(path, X_OK) == 0)
			printf("Execute permission is granted.\n");
		else
			perror("Execute permission denied");
	}
	else
		perror("File not found");
}

static void	cd_home(void)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (home_dir && chdir(home_dir) == 0) // ディレクトリの移動成功
		return ;
	else
		ft_error();
}

int	change_current_dir(const char *path)
{
	char	*cur_dir;

	if (chdir(path) != 0)
		ft_error();
	cur_dir = getcwd(NULL, 0); // 現在のdirectory
	if (cur_dir == NULL)
		ft_error();
	free(cur_dir);
	return (EXIT_SUCCESS);
}

// argv[0]: cd 
// argv[1]: path
// argv[2]: その他

int	cd_command(char **argv)
{
	check_file_permission(argv[1]);//argv[1]??
	if (!argv[1]) // 引数ないときホームディレクトリ移動
		cd_home();
	if (chdir(argv[1]) != 0)
		ft_error();
	env_update("?", "0");
	return (EXIT_SUCCESS);
}

// int main(int ac, char **av)
// {
// 	char *cur_dir;
// 	char *str[3];

// 	printf("cd \n");
//     str[0] = av[1];
//     str[1] = av[2];
//     str[2] = NULL;

// 	cd_command(str);

// 	printf("pwd\n");
// 	cur_dir = getcwd(NULL, 0); // 現在のdirectory
// 	printf("pwd %s\n", cur_dir);

// 	return 0;
// }
