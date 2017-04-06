#include <stdio.h>
#include <conio.h>

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    union a
    {
        short i;
        char ch[2];
    };

    union a u;

    u.ch[0] = 3;
    u.ch[1] = 2;

    printf("\n\n\n\tu{ ch[0] = %d; ch[1] = %d; i = %hi; };",
           u.ch[0], u.ch[1], u.i);

   //   All members of union use same memory location
   //   u.ch[0] = 3=> 00000011
   //   u.ch[1] = 2=> 00000010
   //   u.i => ch[1]ch[0] => [00000010][00000011]
   //   => 1000000011 => 515

    getch();
    return 0;
}
