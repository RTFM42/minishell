/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:42:38 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/18 17:04:26 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../builtin.h"

bool	env_name_judge(char *name)
{
	size_t	i;

	i = 0;
	if (!(ft_isalpha(name[i]) || name[i] == '_'))
		return (false);
	i++;
	while (name[i] && !((name[i] == '=') || \
		(name[i] == '+' && name[i + 1] == '=')))
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (false);
		i++;
	}
	return (true);
}

t_env	*env_del(t_env **env_list, char *name)
{
	t_env	*prev;
	t_env	*current;

	prev = NULL;
	current = (*env_list)->next;
	while (current)
	{
		if (ft_strcmp(current->name, name) == 0)
		{
			if (prev)
				prev->next = current->next;
			else
				*env_list = current->next;
			free(current->name);
			free(current->value);
			free(current);
			return (*env_list);
		}
		prev = current;
		current = current->next;
	}
	return (*env_list);
}

void	*env_update(char *name, char *value)
{
	t_env	*current;
	t_env	**env_list;

	env_list = env_store();
	current = env_search(*env_list, name);
	if (current)
		current->value = ft_strdup(value);
	else
		env_list_add(env_list, name, value);
	return (env_list);
}

t_env	*lstlast(t_env *lst)
{
	int	i;

	i = 0;
	(void)i;
	while (lst && lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (lst);
}
