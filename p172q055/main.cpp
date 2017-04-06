#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    int i = 4, j = -4, k = 0, w, x, y, z;

    w = ++i || ++k || ++j;
    x = i || j && ++k;
    y = i && j || ++k;
    z = i && j && k;

    printf("\n\n\n\tw = %d;\tx = %d;\ty = %d;\tz = %d",
           w,x,y,z);

    getch();
    return 0;
}
