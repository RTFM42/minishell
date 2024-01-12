/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsakanou <nsakanou@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:52:50 by nsakanou          #+#    #+#             */
/*   Updated: 2024/01/11 16:59:29 by nsakanou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../../builtin.h"

bool	option_n(char *str)
{
	if (str && str[0] == '-' && str[1] == 'n' && str[2] == '\0')
		return (true);
	return (false);
}

int	echo_command(char **argv)
{
	size_t	i;

	i = 1;
	if (option_n(argv[1]) == true)
		i = 2;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1] != NULL) //次の要素があれば
			printf(" ");
		i++;
	}
	if (option_n(argv[1]) == false) //オプション無し
		printf("\n");
	return (EXIT_SUCCESS);
}

/*
echo 1 2 3 オプション無し
1 2 3
%
echo -n 1 2 3 オプションあり
1 2 3%

echo -n-n-n-n 1 2 3 オプションなし
-n-n-n-n 1 2 3
%

echo -n -n-n -n 1 2 3 オプションあり
-n-n -n 1 2 3%

echo -n -n -n -n 1 2 3 オプションあり
1 2 3%

終了ステータスは0,1ではなくEXIT_SUCCESS,EXIT_FAILURE
*/
/*
 int main(int argc, char **argv) {
     if (argc >= 2) {
         echo_command(argv);
     } else {
         printf("Usage: %s <args>\n", argv[0]);
     }

     return EXIT_SUCCESS;
 }
 */
