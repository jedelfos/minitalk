/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:03:30 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/21 18:05:22 by jedelfos         ###   ########lyon.fr   */
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
