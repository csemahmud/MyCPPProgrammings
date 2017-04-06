#include<stdio.h>
#include<conio.h>

//   Mahmudul   Hasan   Khan   CE09003

void printBest3Marks(float ctA, float ctB, float ctC)
{
    printf("\n\n\t(%f + %f + %f) / 3.000 = %f",
           ctA, ctB, ctC, (ctA+ctB+ctC)/3.000);
}

int main()
{
    printf("\n\n\n\tEnter Marks of 4 Class Tests [Separated By ' '( space )]: \n\t");
    float classTest1, classTest2, classTest3, classTest4;
    scanf("%f %f %f %f",&classTest1,&classTest2,&classTest3,&classTest4);

    if((classTest1<=classTest2)&&(classTest1<=classTest3)&&(classTest1<=classTest4))
        printBest3Marks(classTest2,classTest3,classTest4);
    else if((classTest2<=classTest3)&&(classTest2<=classTest4))
        printBest3Marks(classTest1,classTest3,classTest4);
    else if(classTest3<=classTest4)
        printBest3Marks(classTest1,classTest2,classTest4);
    else
        printBest3Marks(classTest1,classTest2,classTest3);

    getch();

    return 0;
}
