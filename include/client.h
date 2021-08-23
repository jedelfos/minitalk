/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jedelfos <jedelfos@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 17:04:18 by jedelfos          #+#    #+#             */
/*   Updated: 2021/08/23 15:23:53 by jedelfos         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h> 

int	ft_atoi(const char *str);
int	launch_signal(int y, int i, int pid, char **argv);
int	main(int argc, char **argv);

#endif