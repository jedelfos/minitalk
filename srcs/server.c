/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:50 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/23 15:26:36 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

static char	*calcul_itoa(char *result, int i, int save)
{
	result = (char *)malloc(sizeof(char) * (i + 2));
	if (result == NULL)
		return (NULL);
	result[i + 1] = '\0';
	while (i >= 0)
	{
		result[i] = (save % 10) + 48;
		save = save / 10;
		i--;
	}
	return (result);
}

int	ft_itoa(int n)
{
	int		i;
	int		save;
	char	*result;

	i = 0;
	result = 0;
	save = n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	result = calcul_itoa(result, i, save);
	if (result == NULL)
		return (1);
	write(1, result, i + 1);
	write(1, "\n", 1);
	free (result);
	return (0);
}

static void	t_signal(int sig)
{
	static int	i = 0;
	static int	c = 0;

	if (sig == 31 || sig == 30)
	{
		if (sig == 30)
			c = c | 1;
		i ++;
		if (i == 8)
		{
			write(1, &c, 1);
			i = 0;
			c = 0;
		}
		c = c << 1;
	}
}

int	main(void)
{
	if (ft_itoa(getpid()) == 1)
		return (0);
	signal(30, t_signal);
	signal(31, t_signal);
	t_signal(0);
	while (1)
		sleep(10);
	return (0);
}
