#include<stdio.h>
#include<stdlib.h>

int main()
{
    int row,col,count=0;

    printf("Enter the number of rows\n");
    scanf("%d",&row);
    printf("Enter the number of columns\n");
    scanf("%d",&col);

    int arr[row-1][col-1];

    printf("Enter the elements\n");

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("Enter at arr[%d][%d]:",i,j);
            scanf("%d",&arr[i][j]);
        }
    }

    printf("\nElement entered are\n\n");

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] != 0)
            {
                count = count + 1;
            }

            else
            {
                continue;
            }
        }
    }
    
    int sparsematrix[20][20];
    sparsematrix[0][0] = row;
    sparsematrix[0][1] = col;
    sparsematrix[0][2] = count;
    
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(arr[i][j] != 0)
            {
                sparsematrix[i+1][0] = i+1;
                sparsematrix[i+1][1] = j+1;
                sparsematrix[i+1][2] = arr[i][j];
            }
        }
    }

    printf("\nThe following is the sparse matrix obtained\n\n");

    for(int i = 0; i <= count; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d ", sparsematrix[i][j]);
        }
        printf("\n");
    }

    printf("\nMade by - Bhavneet Singh\n");

    return 0;

}
