#include<stdio.h>
#include<stdlib.h>
int main()
{
    int factorial=1,num;
    printf("Enter the number of which you want to calculate the factorial \n");
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        factorial=factorial*i;
    }
    printf("Factorial is: %d",factorial);
    return 0;
}

