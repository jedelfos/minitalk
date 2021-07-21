/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:23 by jedelfos          #+#    #+#             */
/*   Updated: 2021/07/21 18:10:13 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
#define SERVER_H

# include <stdlib.h> 
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <string.h>

int	ft_itoa(int n);
int	retour(int sig);
int	signal_2(int *nb, int *neg, char *precedent, int *multi);
int	main(void);

#endif