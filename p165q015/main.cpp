#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    extern int fun(float);
    int a;
    a = fun(3.14);
    printf("\n\n\n\ta = %d",a);
    getch();
    return 0;
}

int fun(int aa)
{
    return (int)++aa;
}

//   Above   function   int   fun(int)
//   will   generate   compilation   error
//   So,   we   need   int   fun(float)
//   to   overcome   this

int fun(float aa)
{
    ++aa;
    return (int)++aa;
}
