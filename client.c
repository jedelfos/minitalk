#include <stdio.h>
 #include <signal.h> 
#include <unistd.h>
#include <stdlib.h>

int			ft_atoi(const char *str)
{
	int result;
	int i;

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

int erreur(int i)
{
	exit(0);
}

int main(int argv, char **argc)
{
    int pid;
	if (argv != 3)
		erreur(1);
    pid = ft_atoi(argc[1]);

        printf("%s\n%i",argc[1], pid);




	int i;
	i = 0;
	int nb;
	int cha;
	char test;
	while (argc[2][i])
	{
		cha = argc[2][i];
		printf ("\n%i  ",cha);

		if (cha < 0)
		{
			if (kill(pid, SIGUSR2) == -1)
				erreur(2);		
			printf ("1 -\n");
			cha = cha * -1;
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				erreur(2);	
			printf ("0 -\n");
		}
		usleep(100);
		test = cha;
		nb = 128;
		while (nb > 1)
		{
			nb = nb / 2;
			printf ("%i  ",test);
			if (test >= nb)
			{
				test = test - nb;
				if (kill(pid, SIGUSR2) == -1)
					erreur(2);

				printf ("1\n");

			}
			else
			{
				if (kill(pid, SIGUSR1) == -1)
					erreur(2);
				printf ("0\n");
			}
			usleep(100);

		}
		i++;
	}

    return 0;
}
