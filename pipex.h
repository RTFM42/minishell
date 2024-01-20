/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:05:31 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/20 14:06:46 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pipe
{
	int	pipe_fd[2];
}t_pipe;

void	create_pipe(t_pipe *pipe);
void	close_pipe(t_pipe *pipe);
int		read_pipe(t_pipe *pipe, void *buf, size_t size);
void	write_pipe(t_pipe *pipe, void *buf, size_t size);

#endif
