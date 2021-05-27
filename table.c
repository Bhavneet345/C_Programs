#include<stdio.h>
#include<stdlib.h>
int main()
{
    int num,pro,res=0,i=1;
    printf("Enter the number of which you want to calculate the table-:\n");
    scanf("%d",&num);
    while(i<=10)
    {
        pro=num*i;
        printf("%d*%d=%d \n",num,i,pro);
        res=res+pro;
        i+=1;
    }
    printf("The sum of the values:%d",res);
    return 0;
}
