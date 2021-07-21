/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 16:53:43 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/21 18:05:23 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

int	launch_pid(int pid)
{
	int	nb;
	int	multi;

	multi = 262144;
	nb = getpid();
	while (multi > 1)
	{
		multi = multi / 2;
		if (nb >= multi)
		{
			if (kill(pid, SIGUSR2) == -1)
				erreur(2);
			nb = nb - multi;
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				erreur(2);
		}
		usleep(200);
	}
	return (0);
}

int	retour(int	pid)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (kill(pid, SIGUSR1) == -1)
			erreur(2);
		i++;
		usleep(200);
	}
	launch_pid(pid);
	return (0);
}

int	envoi_neg(int cha, int pid)
{
	if (cha < 0)
	{
		if (kill(pid, SIGUSR2) == -1)
			erreur(2);
		cha = cha * -1;
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			erreur(2);
	}
	usleep(200);
	return (cha);
}

static void	t_signal(int sig)
{
	static char	prec [5];
	int			i;

	i = 0;
	while (prec[i] != 0)
		i++;
	prec[i] = sig;
	if (prec[0] == 30 && prec[1] == 31 && prec[2] == 30 && prec[3] == 31)
	{
		write(1, "la chaine de caractere a bien etait recu\n", 41);
		exit(0);
	}
}

int	main(int argv, char **argc)
{
	int	pid;
	int	i;
	int	cha;

	t_signal(0);
	signal(30, t_signal);
	signal(31, t_signal);
	if (argv != 3)
		erreur(1);
	pid = ft_atoi(argc[1]);
	i = 0;
	while (argc[2][i])
	{
		cha = argc[2][i];
		cha = envoi_neg(cha, pid);
		envoi(cha, pid);
		i++;
	}
	retour(pid);
	i = 0;
	while (i++ < 5)
		sleep(2);
	write(1, "l envoit a eu un probleme\n", 27);
	return (0);
}
