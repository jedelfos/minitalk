#include <stdio.h>
# include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int test;

    int tt;
    test = 0;
    i = 1;

    if(argv[1][0] == '1')
    {
        while (argv[2][test] || i != 1)
        {
            if ((argv[2][test] & 1) == 1)
                printf("1");
            else 
                printf("0");
            argv[2][test] = argv[2][test] >> 1;
            if (i == 8)
            {
                i = 0 ;
                test++;
            }
            i++;
        }
    }
    else if (argv[1][0] == '2')
    {
       while (argv[2][test])
        {
            printf("%i %c\n",tt, argv[2][test]);

            if (argv[2][test] == '1')
                tt = tt | 1;

            test ++;
            if (argv[2][test])
                tt = tt << 1;

        }

        printf("%c     %i\n",tt, tt);

    }
    else if (argv[1][0] == '3')
    {
        argv[2][0] = 42706;
        write (1,argv[1][0],2);
    }


    return 0;
}
