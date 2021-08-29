#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,pos,item,k;

    printf("Enter number of elements you want in the array\n");
    scanf("%d",&n);
    int arr[n+1];

    printf("Enter the elements of the array\n");

    for(int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Array-:\n");

    for(int i = 0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\nEnter the position at which you want to insert the element in an array\n");
    scanf("%d",&pos);
    printf("Enter the element you want to insert\n");
    scanf("%d",&item);

    int j = n-1;

    while(pos-1<=j)
    {
        arr[j+1] = arr[j];
        j = j-1;
    }

    arr[pos] = item;
    printf("Position updated successfully\n");
    printf("\nNew array as follows\n\n");

    for(int i = 0; i<n+1 ; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n\nBY-:");
    printf("\nName : BHAVNEET SINGH\n");
    printf("Roll no. : 02513202720\n");

    return 0;
}
