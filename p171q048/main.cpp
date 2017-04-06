#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

double return_value(double a, double b)
{
    double c = 0, max = 0;
    a>b?c=30.000000:c=40.000000;
    max = a>b?a>c?a:c:b>c?b:c;
    return (a>b)?(max):(c);
}

int main()
{
    printf("\n\n\n\tReturn Value of (35, 35) is : %Lf",
           return_value(35, 35));
    printf("\n\n\tAnd Return Value of (35.01, 35) is : %Lf",
           return_value(35.01, 35));

    getch();
    return 0;
}
