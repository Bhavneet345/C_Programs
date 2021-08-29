#include<stdio.h>
#include<stdlib.h>

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


int binary_search(int arr[], int pos_arr[], int n, int item)
{
    int mp = (n-1)/2;
    int new_arr[n];
    int new_pos_arr[n];
    int a = 0;
    if (arr[mp] > item)
    {
        if(n%2 != 0)
        {
            for(int i=0; i<mp; i++)
                {
                    new_arr[i] = arr[i];
                    new_pos_arr[i] = pos_arr[i];
                }
            return binary_search(new_arr, new_pos_arr, n-(mp+1), item);
        }
        else
        {
            for(int i=0; i<mp; i++)
                {
                    new_arr[i] = arr[i];
                    new_pos_arr[i] = pos_arr[i];
                }
            return binary_search(new_arr, new_pos_arr, n-(mp+2), item);
        }
    }
    else if(arr[mp] < item)
    {
        for(int i = mp+1 ; i<=n-1; i++)
        {
            new_arr[a] = arr[i];
            new_pos_arr[a] = pos_arr[i];
            a = a+1;
        }
        return binary_search(new_arr, new_pos_arr, n-(mp+1), item);
    }
    else if (arr[mp] == item)
    {
        printf("\n\nElement located at %d in the array\n",pos_arr[mp]);
    }
    else if (n == 1)
    {
        printf("\n\nElement located at %d in the array\n",pos_arr[0]);
    }
    else
    {
        printf("\n\nNo such element found");
    }
    return 0;
}

int main()
{
    int n,element;
    printf("Enter the number of elements you want in the array\n");
    scanf("%d",&n);
    int arr1[n];
    int pos_arr1[n];
    for (int i=0;i<n;i++)
    {
        pos_arr1[i] = i;
    }
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
    binary_search(arr1, pos_arr1, n, element);
    return 0;
}
