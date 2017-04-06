#include<stdio.h>
#include<conio.h>

// Mahmudul   Hasan   Khan   CE09003

int main() {

	while(true) {

		int i = 0;
			printf("\n");
			while(true) {
				i++;
				printf("\n\n\tFrom Infinite While Loop i = %d",i);
				if(i==5) {
					printf("\n\n\tBreaking Infinite While Loop, when i = %d",i);
					break;
					printf("\n\n\tAfter Breaking Infinite While Loop");
					i = 1000;
				}
			}

			for(;true;) {
				i++;
				printf("\n\n\tFrom Infinite For Loop i = %d",i);
				if(i==10) {
					printf("\n\n\tBreaking Infinite For Loop, when i = %d",i);
					break;
					printf("\n\n\tAfter Breaking Infinite For Loop");
				}
			}

			printf("\n\n\tOut side of Inner Loops . i = %d",i);

			if(i==10) {
				break;
				printf("\n\tLoop is broken . This will not be printed .");
			}

	}

	getch();

	return 0;

}
