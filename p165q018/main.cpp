#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    int X = 40;
    {
        int X = 20;
        printf("\n\n\n\tX, Inside Loop : %d",X);
    }
    printf("\n\n\tX, Outside Loop : %d",X);
    getch();
    return 0;
}
