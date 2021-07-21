#include <stdio.h>
#include <signal.h> 
#include <unistd.h>
#include <stdlib.h>

static void	t_signal(int sig)
{
	
	static char	prec[5];
	printf("test");
	int i;

	i = 0;
	while(prec[i] != 0)
	{
		i++;
	}

	prec[i] = sig;
	if (prec[0] == 30 && prec[1] == 31 && prec[2] == 30 && prec[3] == 31)
	{
		printf("ok\n");
		exit(0);
	}
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

int	erreur(int i)
{
	exit(0);
}

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

int	envoi_neg(int cha, char **argc, int pid)
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

int	main(int argv, char **argc)
{
				printf("\n%i\n", getpid());
	int	pid;
	int	i;
	int	cha;

	signal(30, t_signal);
	signal(31, t_signal);
	if (argv != 3)
		erreur(1);
	pid = ft_atoi(argc[1]);
	i = 0;
	while (argc[2][i])
	{
		cha = argc[2][i];

		cha = envoi_neg(cha, argc, pid);
		envoi(cha, pid);
		i++;
	}
	retour(pid);
	i = 0;
	while (i++ < 5)
		sleep(2);
	printf("ko\n");
	return (0);
}

