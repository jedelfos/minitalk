/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:43 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/23 15:24:09 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (result);
}

int	launch_signal(int y, int i, int pid, char **argv)
{
	char	c;

	while (argv[2][y])
	{	
		i = 1;
		c = argv[2][y];
		while (c || i != 1)
		{
			usleep(165);
			if ((c & 4096))
			{
				if (kill(pid, SIGUSR1) == -1)
					return (0);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					return (0);
			c = c << 1;
			if (i == 8)
				i = 0 ;
			i++;
		}
		y++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		y;
	int		pid;

	if (argc < 3)
		return (0);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (0);
	i = 1;
	y = 0;
	launch_signal(y, i, pid, argv);
	return (0);
}
