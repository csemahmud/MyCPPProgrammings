#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    int a = 0, b = 1, c = 3;
    *((a)?&b:&a) = a?b:c;
    printf("\n\n\n\ta = %d, b = %d, c = %d",
           a,b,c);
    getch();
    return 0;
}
