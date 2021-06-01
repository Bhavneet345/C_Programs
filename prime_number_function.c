#include<stdio.h>
#include<stdlib.h>
void prime(int l_range,int u_range)
{
    int flag=1;
    for(int i=l_range;i<=u_range;i++)
    {
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
               flag=0;
               break;
            }
            else
            {
                flag=1;
            }
        }
    if(flag)
    {
        printf("%d \n",i);
    }

    }

}
int main()
{
    int number1,number2;
    printf("Enter the lower range\n");
    scanf("%d",&number1);
    printf("Enter the upper range\n");
    scanf("%d",&number2);
    printf("prime numbers are as follows-:\n");
    prime(number1,number2);
    return 0;
}

