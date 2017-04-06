#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    int x = 3;
    float y = 3.0;
    const long double Z = 3.000000L;

    if(x==y)
        printf("\n\n\n\tx and y are equal.");
    else
        printf("\n\n\n\tx and y are not equal.");

    if(x==Z)
        printf("\n\n\tx and Z are equal.");
    else
        printf("\n\n\tx and Z are not equal.");

    getch();
    return 0;
}
