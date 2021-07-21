/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:18 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/21 17:51:20 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

#include <stdio.h>
#include <signal.h> 
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str);
int	erreur();
int	launch_pid(int pid);
int	retour(int	pid);
int	envoi_neg(int cha, int pid);
int	envoi(int cha, int pid);
int	main(int argv, char **argc);

#endif