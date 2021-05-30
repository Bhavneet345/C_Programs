#include<stdio.h>
#include<stdlib.h>
void star(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=i)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}
int main()
{
    int num;
    printf("Enter number of stars you want to be printed\n");
    scanf("%d",&num);
    star(num);
    return 0;
}
