#include <iostream>
#include <cmath>
#include<conio.h>

using namespace std;

//   Mahmudul   Hasan   Khan   CSE

int main()
{
    double rem = fmod(3.14,2.1);
    cout <<"\n\n\n\tReminder = "<< rem << endl;
    cout <<"\n\tceil = "<< ceil(rem) << endl;
    cout <<"\n\tfloor = "<< floor(rem) << endl;
    getch();
    return 0;
}
