#include<stdio.h>
#include<stdlib.h>
void TOH(int n,char source,char auxilary,char target)
{
    if(n==1)
    {
        printf("Moving disk %d from %c to %c\n",n,source,target);
        return;
    }
    TOH(n-1,source,target,auxilary);
    printf("Moving disk %d from %c to %c\n",n,source,target);
    TOH(n-1,auxilary,source,target);
}
int main()
{
    int num;
    printf("Enter the number of disks you want:");
    scanf("%d",&num);
    TOH(num,'A','B','C');
    return 0;
}
