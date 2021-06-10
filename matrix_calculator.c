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
    printf("Resulting matrix-\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",sum[i][j]) ;
        }
    printf("\n");
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
    printf("Resulting matrix-\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",difference[i][j]) ;
        }
    printf("\n");
    }
}

void multiply()
{
    int sum =0;
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
            for(int k=0;k<3;k++)
            {
                sum+=arr1[i][k]*arr2[k][j];
            }
        pro[i][j] = sum;
        sum = 0;
        }
    }
    printf("Resulting matrix\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",pro[i][j]) ;
        }
    printf("\n");
    }
}
void lower_triangle(int arr2[3][3])
{
    int lower[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i<j)
            {
                arr2[i][j]=0;
                lower[i][j]=arr2[i][j];
            }
            else
            {
                lower[i][j]=arr2[i][j];
            }
        }
    }
    printf("Lower triangle-\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",lower[i][j]);
        }
    printf("\n");
    }
}
void upper_triangle(int arr1[3][3])
{
    int upper[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i>j)
            {
                arr1[i][j]=0;
                upper[i][j]=arr1[i][j];
            }
            else
            {
                upper[i][j]=arr1[i][j];
            }
        }
    }
     printf("Upper triangle-\n");
     for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",upper[i][j]);
        }
    printf("\n");
    }
}
void transpose()
{
    int temp;
    int arr1[3][3];
    int arr2[3][3];
    printf("Enter the array you want to transpose\n");
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
            printf("%d ",arr1[i][j]);
        }
        printf("\n");
    }
    printf("Transposed-\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr2[i][j]=arr1[j][i];
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d ",arr2[i][j]);
        }
    printf("\n");
    }
}
int main()
{
    int arr[3][3];
    int arr1[3][3];
    int ch;
    printf("Enter your choice\n 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Upper and lower triangles\n 5.Transpose\n");
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
        printf("Triangles!!\n");
        printf("Enter the array you want to transpose\n");
        for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    printf("Enter arr[%d][%d]:\n",i,j);
                    scanf("%d",&arr[i][j]);
                }
            }
        for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                   arr1[i][j]=arr[i][j];
                }
            }
        upper_triangle(arr);
        lower_triangle(arr1);
        break;
    case 5:
        printf("Transpose!!\n");
        transpose();
        break;
    default:
        printf("Sorry invalid!!");
    }
    return 0;
}

