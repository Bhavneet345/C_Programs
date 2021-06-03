#include<stdio.h>
#include<stdlib.h>
void add()
{
    int arr1[3][3];
    int arr2[3][3];
    int sum[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr[%d][%d]:\n",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr2[%d][%d]:\n",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum[i][j]= arr1[i][j] + arr2[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("sum[%d][%d]:%d\n",i,j,sum[i][j]) ;
        }
    }
}
void subtract()
{
    int arr1[3][3];
    int arr2[3][3];
    int difference[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr1[%d][%d]:\n",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr2[%d][%d]:\n",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            difference[i][j]= arr1[i][j] - arr2[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("diiference[%d][%d]:%d\n",i,j,difference[i][j]) ;
        }
    }
}

void multiply()
{
    int arr1[3][3];
    int arr2[3][3];
    int pro[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr[%d][%d]:\n",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr2[%d][%d]:\n",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            pro[i][j]= arr1[i][j] * arr2[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("product[%d][%d]:%d\n",i,j,pro[i][j]) ;
        }
    }
}
void divide()
{
    int arr1[3][3];
    int arr2[3][3];
    float div[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr[%d][%d]:\n",i,j);
            scanf("%d",&arr1[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Enter arr2[%d][%d]:\n",i,j);
            scanf("%d",&arr2[i][j]);
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            div[i][j]= arr1[i][j] / arr2[i][j];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("divisor[%d][%d]:%d\n",i,j,div[i][j]) ;
        }
    }
}
int main()
{

    int ch;
    printf("Enter your choice\n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Addition!!\n");
        add();
        break;
    case 2:
        printf("Subtraction!!\n");
        subtract();
        break;
    case 3:
        printf("Multiplication!!\n");
        multiply();
        break;
    case 4:
        printf("Division!!\n");
        divide();
        break;
    default:
        printf("Sorry invalid!!");
    }
    return 0;
}

