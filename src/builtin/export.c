/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:53:09 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/15 18:02:54 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

static char	*export_getname(char *argv)
{
	char	*value;
	char	*name;

	value = ft_strchr(argv, '=') + 1;
	name = (char *)ft_calloc(value - argv + 1, 1);
	ft_strlcpy(name, argv, value - argv);
	return (name);
}

static char	*export_getvalue(char *argv)
{
	char	*value;

	value = ft_strdup(ft_strchr(argv, '=') + 1);
	return (value);
}

int	export_command(char **argv)
{
	size_t	i;
	char	*name;
	char	*value;

	if (ft_strcmp(argv[0], "export") == 0 && argv[1] == NULL)
		export_print_env();
	i = 1;
	while (argv[i])
	{
		name = export_getname(argv[i]);
		if (env_name_judge(name))
		{
			value = export_getvalue(argv[i]);
			env_list_add(env_store(), name, value);
			free(name);
			free(value);
			i++;
			continue ;
		}
		free(name);
		strerror(errno);
		i++;
	}
	env_update("?", "0");
	return (0);
}

/*
export MY_VAR="Hello World"
export 変数名=値

+=
ex)
export a=1
export a+="new"
↓
echo $a
1new

 export =
bash: export: `=': not a valid identifier
export=
何も出ない

export " "=" "
export: not valid in this context:  
export '$'="aa"
zsh: not an identifier: $

export a= b
↓二つ定義される
a=‘ ‘
b

bash-3.2$ export a
bash-3.2$ export 1
bash: export: `1': not a valid identifier
bash-3.2$ export a 1
bash: export: `1': not a valid identifier

bash-3.2$ export TEAT="1"
bash-3.2$ export -p | grep TEAT
declare -x TEAT="1"
*/