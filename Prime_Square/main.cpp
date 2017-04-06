#include<stdio.h>
#include<conio.h>
#include<math.h>

//   Mahmudul   Hasan   Khan   CE09003

int main() {

    printf("\n\n\n\tEnter the size of Prime Square : ");
    int size, row, col, prime = 2, num, top = 0, primeStack[1000];
    bool isPrime;
    scanf("%d", &size);
    for(row = 0; row < size; row++) {
        printf("\n\t");
        primeStack[top++] = prime;
        for(col = 1; col < (size - row); col++) {
            printf("    ");
        }
        for(col = 0; col <= row; col++) {
            do {
                isPrime = true;
                for(num = 2; num <= sqrt(double(prime)); num++) {
                    if(!(prime%num)) {
                        isPrime = false;
                        break;
                    }
                }

                if(isPrime) {
                    printf("%4d", prime);
                }
                prime++;
            } while(!isPrime);
        }
        for(col = 0; col <= (row-1); col++) {
            do {
                isPrime = true;
                for(num = 2; num <= sqrt(double(prime)); num++) {
                    if(!(prime%num)) {
                        isPrime = false;
                        break;
                    }
                }

                if(isPrime) {
                    printf("%4d", prime);
                }
                prime++;
            } while(!isPrime);
        }
    }
    for(row = size-1; row >= 0; row--) {
        printf("\n\t");
        prime = primeStack[--top];
        for(col = 1; col < (size - row); col++) {
            printf("    ");
        }
        for(col = 0; col <= row; col++) {
            do {
                isPrime = true;
                for(num = 2; num <= sqrt(double(prime)); num++) {
                    if(!(prime%num)) {
                        isPrime = false;
                        break;
                    }
                }

                if(isPrime) {
                    printf("%4d", prime);
                }
                prime++;
            } while(!isPrime);
        }
        for(col = 0; col <= (row-1); col++) {
            do {
                isPrime = true;
                for(num = 2; num <= sqrt(double(prime)); num++) {
                    if(!(prime%num)) {
                        isPrime = false;
                        break;
                    }
                }

                if(isPrime) {
                    printf("%4d", prime);
                }
                prime++;
            } while(!isPrime);
        }
    }

    getch();

    return 0;

}
