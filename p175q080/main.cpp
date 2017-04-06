#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    static unsigned long i = 0;
    printf("\t%lu;", ++i);

    if(i == 4800)
    {
        printf("\n\tPRESS ANY KEY TO CONTINUE ..... \t");
        getch();
    }

    else if(i >= 65091)
    {
        printf("\n\tPRESS ANY KEY TO CONTINUE ..... \t");
        getch();
    }

    main();

    getch();
    return 0;
}
