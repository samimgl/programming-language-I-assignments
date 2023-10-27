#include <stdio.h>

int mdc(int num1, int num2);

int main()
{
    int num1, num2, m;

    scanf("%d", &num1);
    scanf("%d", &num2);

    if(num1>num2){
        m = mdc(num1, num2);
    }
    else
    if(num2>num1){
        m = mdc(num2, num1);
    }
    else{
        m = num1;
    }

    printf("\n%d\n", m);

    return 0;
}

int mdc(int num1, int num2)
{
    int r;

    while(num2 != 0){
        r = num1 % num2;
        num1 = num2;
        num2 = r;
    }
    return(num1);
}
