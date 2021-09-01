#include<stdio.h>
#include<stdlib.h>

int bubble_sort(int arr[], int len)
{
    int temp;
    for(int i = 1; i<=len-1; i++)
    {
        printf("\n");
        printf("Pass %d\n", i);
        for(int j = 0; j<len - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            for(int i = 0; i<len; i++)
            {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
    return arr;
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
    bubble_sort(arr1, n);
    printf("\nSorted array is as follows\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr1[i]);
    }
    printf("\nMade by -\nBhavneet Singh\n02513202720\n");
}
