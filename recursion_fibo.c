#include<stdio.h>
#include<stdlib.h>
int fibonacci(int term)
{
    if (term>0)
    {
        static int c;
        static int a=0,b=1;
        c = a+b;
        a = b;
        b = c;
        printf(",%d",c);
        fibonacci(term -1);
    }
}

int main()
{
    int term;
    printf("Enter number of terms\n");
    scanf("%d",&term);
    printf("%d,%d",0,1);
    fibonacci(term-2);
    return 0;
}
