/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:03:27 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/21 17:43:50 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

int	envoi(int cha, int pid)
{
	int	nb;

	nb = 128;
	while (nb > 1)
	{
		nb = nb / 2;
		if (cha >= nb)
		{
			cha = cha - nb;
			if (kill(pid, SIGUSR2) == -1)
				erreur(2);
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

int	erreur()
{
	write(1, "erreur d envoi (PID incorecte)\n", 32);
	exit(0);
}
