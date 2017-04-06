#include<stdio.h>
#include<conio.h>
#include<math.h>

//   Mahmudul   Hasan   Khan   CE09003

int main() {

    int range, count = 2;
    unsigned long long ofpNum1 = 3, ofpNum2 = 5, ofpNum3;
    bool isPrime;
    printf("\n\n\n\tHow many Odd Fibonacci Prime Numbers do you want ?\n\n\tEnter it : ");
    scanf("%d", &range);
    printf("\n\n\t%d Odd Fibonacci Primes are : ",range);
    if(range>=2) {
        printf("\t3,\t5,");
    }
    else if(range==1) {
        printf("\t3");
    }
    while(count < range) {
        ofpNum3 = ofpNum1 + ofpNum2;
        isPrime = true;
        if(!(ofpNum3%2)) {
           isPrime = false;
        }
        else {
            for(unsigned long long i = 3; i <= sqrt((long double)ofpNum3); i+=2) {
                if(!(ofpNum3%i)) {
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime) {
            printf("\t%llu,", ofpNum3);
            count++;
        }
        ofpNum1 = ofpNum2;
        ofpNum2 = ofpNum3;
    }
    getch();
    return 0;

}
