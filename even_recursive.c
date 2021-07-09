#include<stdlib.h>
#include<stdio.h>
int even(int num)
{
    int n = 1;
    static int eve = 2;
    if(n<=num)
    {
        printf("%d ",eve);
        eve = eve+2;
        even(num-1);
    }
}
int main()
{
    int num1;
    printf("Enter ho many numbers you want\n");
    scanf("%d",&num1);
    even(num1);
}
