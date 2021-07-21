/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:50 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/21 17:55:46 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

int	retour(int sig)
{
	static int	multi = 262144;
	static int	nb = 0;

	multi = multi / 2;
	if (sig == 31)
		nb = nb + multi ;
	if (multi == 1)
	{
		usleep(200);
		kill(nb, SIGUSR1);
		usleep(200);
		kill(nb, SIGUSR2);
		usleep(200);
		kill(nb, SIGUSR1);
		usleep(200);
		kill(nb, SIGUSR2);
		multi = 262144;
		nb = 0;
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int	signal_2(int *nb, int *neg, char *precedent, int *multi)
{
	if (nb[0] * neg[0] == 0 && precedent[0] == 0 && multi[0] == 1)
		multi[0] = -10;
	if (multi[0] == 1)
	{
		nb[0] = nb[0] * neg[0];
		precedent[1] = nb[0];
		if (precedent[0] < 0)
		{
			write(1, precedent, 2);
			neg[0] = 10;
			precedent [0] = 0;
		}
		else if (nb[0] >= 0)
			write(1, &nb[0], 1);
		multi[0] = 256;
		if (neg[0] != 10)
			precedent [0] = nb[0];
		neg[0] = 1;
		nb[0] = 0;
	}
	multi[0] = multi[0] / 2;
	return (0);
}

static void	t_signal(int sig)
{
	static int	multi = 128;
	static int	nb = 0;
	static int	neg = 1;
	static char	precedent[2];

	if (multi < 0)
	{
		multi = -10;
		if (retour(sig) == 1)
		{
			sig = 0;
			multi = 256;
			nb = 0;
			neg = 1;
		}
	}
	if (sig == 31 && multi == 128)
		neg = -1;
	else if (sig == 31)
		nb = nb + multi;
	signal_2(&nb, &neg, precedent, &multi);
	return ;
}

int	main()
{
	if (ft_itoa(getpid()) == 1)
		return (0);
	signal(30, t_signal);
	signal(31, t_signal);
	while (1)
		sleep(10);
	return (0);
}
