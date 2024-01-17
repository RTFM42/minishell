/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:23:20 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/17 21:37:46 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# define DEBUG() printf("[%s](%d)\n", __func__, __LINE__)

# include "lib/ft_eprintf/ft_eprintf.h"
# include "lib/libft/libft.h"
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <ctype.h>

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}t_env;

int		exec_builtin(char **argv);
//command
int		echo_command(char **argv);
int		pwd_command(void);
int		unset_command(char **argv);
int		exit_command(char **argv);
int		cd_command(char **argv);
int		export_command(char **argv);

//env
int		env_command(void);
t_env	*env_search(t_env *env, char *name);
void	env_list_add(t_env **env_list, char *name, char *value);
void	env_list_print(t_env *env_list);
t_env	*env_create(char **envp);
t_env	**env_store(void);

//env_utils
bool	env_name_judge(char *name);
void	env_del(t_env **env_list, char *name);
void	*env_update(char *name, char *value);
t_env	*lstlast(t_env *lst);

//export
void	export_putenvs(t_env *env);
char	*export_strjoin(const char *s1, const char *s2);

//utils
void	ft_error(void);
int		ft_strcmp(const char *s1, const char *s2);

#endif
