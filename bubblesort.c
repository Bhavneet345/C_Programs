#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,temp;
    printf("Enter the number of elements you want in an array\n");
    scanf("%d",&n);
    printf("Enter the elements!!\n");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d\n",&arr[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=(n-1)-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("sorted array is..\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
    return 0;
}
