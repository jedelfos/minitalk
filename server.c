#include <stdlib.h> 
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

int	retour(int sig)
{
	static int	multi = 262144;
	static int	nb = 0;

	multi = multi / 2;
	if (sig == 31)
	{
		nb = nb + multi ;
		printf ("evoi 1");
	}
	else
		printf ("evoi 0");
	if (multi == 1)
	{
		multi = 262144;
		nb = 0;
		kill(nb, SIGUSR1);
		usleep(100);
		kill(nb, SIGUSR2);
		usleep(100);
		kill(nb, SIGUSR1);
		usleep(100);
		kill(nb, SIGUSR2);
		printf ("\nreset \n");
		return (1);
	}
	return (0);
}

static void	t_signal(int sig)
{
if (sig == 31 )
		printf("    1");
	else
		printf("    0");
	static int	multi = 128;
	static int	nb = 0;
	static int	neg = 1;
	static char	precedent[2];

	if (multi < 0)
	{
		multi = -10;
		if (retour(sig) == 1)
		{
			printf ("\nreset \n");
			sig = 0;
			multi = 256;
			nb = 0;
			neg = 1;
		}
	}

	if (sig == 31 && multi == 128)
		neg = -1;
	else if (sig == 31)
	{
		nb = nb + multi ;
			printf("  *  %i \n", nb);
	}
	if (nb * neg == 0 && precedent[0] == 0 && multi == 1)
		multi = -10;
	if (multi == 1)
	{
		nb = nb * neg;
		precedent[1] = nb;
		if (precedent[0] < 0)
		{
			write(1, precedent, 2);
			neg = 10;
			precedent [0] = 0;
		}
		else if (nb >= 0)
			write(1, &nb, 1);
		printf(" \n");

		multi = 256;
		if (neg != 10)
			precedent [0] = nb;
		neg = 1;
		nb = 0;
	}
	multi = multi / 2;
	return ;
}

int	main(int argc, char *argv[])
{
	printf("%i\n", getpid());
	signal(30, t_signal);
	signal(31, t_signal);
	while (1)
		sleep(10);
	return (0);
}
