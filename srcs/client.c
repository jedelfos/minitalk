/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:43 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/23 13:34:02 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
	{
		i++;
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
    int i;
    int y;
    int pid;
    char c;

    if (argc < 2)
        return (0);
    pid = ft_atoi(argv[1]);
    i = 1;
    y = 0;

    while (argv[2][y])
    {    
        i = 1;
        c = argv[2][y];
        while (c || i != 1)
        {
            if ((c  & 4096))
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(280);
            c = c << 1;
            if (i == 8)
                i = 0 ;
            i++;
        }
        y++;
    }
    return 0;
}
