#include<stdio.h>
#include<stdlib.h>

void binary_search(int arr[], int item, int len)
{
    int end = len - 1;
    int beg = 0;
    int mp;
    int flag = 0;
    while(beg != end)
    {
        mp = (beg + end) / 2;
        if (arr[mp] == item)
        {
            flag = 0;
            printf("Element located at %d position\n", mp);
            break;
        }
        else
        {
            flag = 1;
            if(arr[mp] > item)
            {
                end = mp -1;
            }
            else
            {
                beg = mp+1;
            }
        }
    }
    if (flag == 1)
    {
        if(arr[beg] == item)
        {
            printf("\nElement located at %d position\n", beg);
        }
        else
        {
            printf("\nNo such element found\n");
        }
    }
}


int bubble_sort(int arr[], int len)
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

    return bubble_sort(arr, len-1);
    }
}


int main()
{
    int n,element;
    printf("Enter the number of elements you want in the array\n");
    scanf("%d",&n);
    int arr1[n];
    printf("\nEnter the elements of the array\n");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
    printf("\nEnter item you want to search for\n");
    scanf("%d", &element);
    bubble_sort(arr1,n);
    printf("\nSorted array is\n");
    for (int i=0;i<n;i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    binary_search(arr1,element,n);
    printf("Made by -\nBhavneet Singh\n02513202720\n");
    return 0;
}
