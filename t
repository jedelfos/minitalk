
static void signal_1(int sig)
{
    static int multi = 128;
    static int nb = 0;
    static int neg = 1;
    static char precedent [2];
    if (sig == 31 && multi == 128)
        neg = -1;
    else if (sig == 31)
        nb = nb + multi ;
//    printf ("%i    %i    %i  \n", multi, sig - 30, nb);

    if (multi == 1)
    {
        nb = nb * neg;
    	precedent[1] = nb;
        if (precedent[0] < 0)
        {
            write(1, precedent, 2);
        	write(1, "-- \n", 5);
            neg = 10;
        }
        else if (nb >= 0)
        {
            write(1, &nb, 1);
    	    write(1, "\n", 1);
        }
        multi = 256;
        if (neg != 10)
        precedent [0] = nb;

        neg = 1;
        nb = 0;
    }
    multi = multi / 2;

//    printf ("%i\n",sig - 30);
