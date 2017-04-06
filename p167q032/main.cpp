#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    float a = 0.700000;

    if(0.700000 == a)
        printf("\n\n\n\tHi, a = %f",a);
    else if(0.700000 > a)
        printf("\n\n\n\tHello, a = %f",a);
    else
        printf("\n\n\n\tHow are you ?, a = %f",a);

    if(0.700000f == a)
        printf("\n\n\n\tHi, a = %f",a);
    else if(0.700000f > a)
        printf("\n\n\n\tHello, a = %f",a);
    else
        printf("\n\n\n\tHow are you ?, a = %f",a);

    getch();
    return 0;
}
