#include<stdio.h>
#include<stdlib.h>
int main()
{
    char choice;
    int num1,num2,res;
    printf("Enter your choice\n");
    scanf("%c",&choice);
    printf("Enter your first number\n");
    scanf("%d",&num1);
    printf("Enter your second number\n");
    scanf("%d",&num2);
    switch(choice)
    {
    case '+':
        res=num1+num2;
        printf("Sum is %d",res);
        break;
    case '-':
        res=num1-num2;
        printf("Difference is %d",res);
        break;
    case'/':
        res=num1/num2;
        printf("Result is %d",res);
        break;
    case'*':
        res=num1*num2;
        printf("Product is %d",res);
        break;
    default:
        printf("Invalid operator used");
    }
    return 0;
}
