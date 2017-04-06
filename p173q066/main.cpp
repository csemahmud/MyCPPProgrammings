#include <stdio.h>
#include <conio.h>
#include <math.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    const float num = 43.540000f;
    printf("\n\n\n\tGiven Value = %f;\t%e;\t%g;\t%lf"
           ,num, num, num, num);

    int round_value = int(num + 0.5);
    printf("\n\n\tRound Off value = %d"
           ,round_value);
    printf("\n\n\tln(43.54) = %f;\tlog(43.54) = %f"
           ,log(num), log10(num));
    printf("\n\n\tremainder = %f",
           fmod(num, 1.3f));
    printf("\n\n\tSize = %d;\t%d;\t%d;\t%d",
           sizeof(num),sizeof(43.540000f),
           sizeof(43.540000),sizeof(43.540000l));

    if(num == 43.540000)
        printf("\n\n\t%f is Equal to %f .....",
               num, 43.540000);
    else if(num < 43.540000)
        printf("\n\n\t%f is Less than %f .....",
               num, 43.540000);
    else
        printf("\n\n\t%f is Else to %f .....",
               num, 43.540000);

    getch();
    return 0;
}
