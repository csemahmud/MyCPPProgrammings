#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    struct emp
    {
        char name[20];
        int age;
        float sal;
    };

    struct emp e = {"Tiger"};
    printf("\n\n\n\tname = %s;\n\n\tage = %d;\n\n\tsal = %f;",
           e.name, e.age, e.sal);
    getch();
    return 0;
}
