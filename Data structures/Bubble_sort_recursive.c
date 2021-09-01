#include<stdio.h>
#include<stdlib.h>

int bubble_sort_recursive(int arr[], int len)
{
    int temp;
    if(len == 1)
    {
        return arr;
    }
    else
    {
        for(int i=0; i<len-1; i++)
            {
                if(arr[i] > arr[i+1])
                {
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }
    return bubble_sort(_recursive(arr,len-1);
    }
}

int main()
{
    int n;
    printf("Enter the number of elements you want in the array\n");
    scanf("%d",&n);
    int arr1[n];
    printf("\nEnter the elements of the array\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    bubble_sort_recursive(arr1, n);
    printf("\nSorted array is as follows\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
}
