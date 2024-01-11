/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:54:39 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/11 16:12:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 ./pipex file1 cmd1 cmd2 file2
 < file1 cmd1 | cmd2 > file2

  ./pipex infile "ls -l" "wc -l" outfile
  < infile ls -l | wc -l > outfile

   ./pipex infile "grep a1" "wc -w" outfile
   < infile grep a1 | wc -w > outfile

   command1 | command2 の形式のコマンドでは、command1 の出力が command2 の入力に渡され、これにより複数のプロセスが連携してデータを処理
 */

/*
二つのプロセス間でデータを双方向に転送
→片方のプロセスが書き込むと、もう片方のプロセスが読み取る

create_pipe
pipe システムコールを使用して生成。
新しいパイプが作成され、2つのファイルディスクリプタが返される。一方のディスクリプタは読み取り専用で、もう一方は書き込み専用

2つのプロセスがパイプを介して連携する一般的な手順は以下の通りです。
親プロセスが pipe システムコールを使用して新しいパイプを作成し、2つのファイルディスクリプタを取得します。
親プロセスが fork システムコールを使用して子プロセスを生成します。
子プロセスが dup2 システムコールを使用して、標準入出力をパイプのディスクリプタにリダイレクトします。
親プロセスと子プロセスがそれぞれ必要な処理を実行します。
パイプの片方のディスクリプタは親プロセスが閉じ、もう片方は子プロセスが閉じます。


close_pipe
*/

//成功した場合には新しいパイプが生成され、そのファイルディスクリプタが t_pipe 構造体に格納される。
void  create_pipe(t_pipe *pipe)
{
  if (pipe(pipe->pipe_fd) == -1)
    ft_error();
}

void  close_pipe(t_pipe *pipe)
{
  close(pipe->pipe_fd[0]);
  close(pipe->pipe_fd[1]);
}

int read_pipe(t_pipe *pipe, void *buf, size_t size)
{
  close(pipe->pipe_fd[1]);//書き込み側をクローズ
                          
  ssize_t bytes_read;//負の値も含む
  bytes_read = read(pipe->pipe_fd[0], buf, size);
  if (byte_read == -1)
    ft_error();
  return (bytes_read);
}

void  write_pipe(t_pipe *pipe, void *buf, size_t size)
{
  close(pipe->pipe_fd[0]);//読み取り側をクローズ
                          
  ssize_t bytes_write;
  bytes_write = write(pipe->pipe_fd[1], buf, size);
  if (bytes_write == -1)
    ft_error();
}


