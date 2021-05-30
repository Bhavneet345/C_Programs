#include<stdio.h>
#include<stdlib.h>
int recursive_fibonacci(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    else
    {
        return (recursive_fibonacci(n-2)+recursive_fibonacci(n-1));

    }
}
int main()
{
    int fibonacci;
    int num;
    printf("Enter which fibonnaci term you want??\n");
    scanf("%d",&num);
    fibonacci=recursive_fibonacci(num);
    printf("The %dth fibonacci term is:%d",num,fibonacci);
}
