/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:23 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/23 13:36:58 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdlib.h> 

static char	*calcul_itoa(char *result, int i, int save);
int	ft_itoa(int n);
static void	t_signal(int sig);
int	main(void);

#endif