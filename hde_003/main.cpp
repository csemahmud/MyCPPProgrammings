#include <stdio.h>
#include <conio.h>

int rec_x_fun(int x, int sum){
    int yn;
    if(x > 0){
        scanf("%d",&yn);
        if(yn > 0){
            sum += (yn*yn);
        }
        return rec_x_fun(x-1,sum);
    }
    printf("%d\n",sum);
    return 0;
}

int rec_n_fun(int n){
    int x;
    if(n > 0){
        scanf("%d",&x);
        rec_x_fun(x,0);
        return rec_n_fun(n-1);
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d",&n);
    rec_n_fun(n);
    getch();
    return 0;
}
