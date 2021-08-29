#include<stdio.h>
#include<stdlib.h>

void linear_search(int arr[], int element, int len)
{
    for (int i=0; i<len; i++)
    {
        if (arr[i] == element)
        {
            printf("Element found at position %d of the array\n",i);
            break;
        }
        else
        {
            continue;
        }
    }

}

int main()
{
    int n,item;
    printf("Enter the number of elements you want in the array\n");
    scanf("%d",&n);
    int arr1[n];
    printf("\nEnter the elements of the array\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("\nEnter the element you want to search for\n");
    scanf("%d",&item);
    linear_search(arr1,item,n);
}
