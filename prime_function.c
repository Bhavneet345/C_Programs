#include<stdio.h>
#include<stdlib.h>
void prime(int num)
{
    int flag=1;
    for(int i=2;i<num;i++)
    {
        if(num%i==0)
        {
            flag = 0;
            break;
        }
        else
        {
            flag = 1;
        }
    }
    if(flag)
    {
        printf("Prime number");
    }
    else
    {
        printf("Not a prime number");
    }
}
int main()
{
    int number;
    printf("Enter the number\n");
    scanf("%d",&number);
    prime(number);
    return 0;
}
