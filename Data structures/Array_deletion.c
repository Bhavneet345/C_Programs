#include<stdio.h>
#include<stdlib.h>

int main()
{
    int len,position;
    printf("Enter number of elements\n");
    scanf("%d", &len);
    int arr[len];
    printf("\nEnter the elements\n");
    for(int i = 0; i<len; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the position you want to delete\n");
    scanf("%d", &position);

    printf("\nArray is as follows\n");

    for(int i = 0; i< len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\nElement to be deleted at position %d is %d",position,arr[position]);

    while(position<len-1)
    {
        arr[position] = arr[position+1];
        position = position+1;
    }

    printf("\nNew array after deletion is- \n\n");

    for(int i = 0; i<len-1 ; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n\nBY-:");
    printf("\nName : BHAVNEET SINGH\n");
    printf("Roll no. : 02513202720\n");

    return 0;
}
