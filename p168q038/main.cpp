#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    int x, y, z;
    x=y=z=2;
    z = ++x||++y&&++z;
    printf("\n\n\n\tx = %d, y = %d, z = %d",
           x, y, z);
    getch();
    return 0;
}
