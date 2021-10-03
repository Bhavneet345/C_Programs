#include<stdio.h>
#include<stdlib.h>

struct circular_queue
{
    int front , rear, size;
    int *arr;
};

int is_empty(struct circular_queue *q)
{
    if(q -> rear == q -> front)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

int is_full(struct circular_queue *q)
{
    if((q -> rear + 1) % q -> size == q -> front)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

void enqueue(struct circular_queue *q,int val)
{
    if(is_full(q))
    {
        printf("Over flow condition\n");
    }

    else
    {
        printf("Element inserted is %d\n",val);
        q -> rear = (q -> rear + 1) % q -> size;
        q -> arr[q -> rear] = val;
    }
}

int deque(struct circular_queue *q)
{
    int val = -1;
    if(is_empty(q))
    {
        printf("Under flow condition\n");
        return 0;
    }

    else
    {
        q -> front = (q -> front + 1) % q -> size;
        val = q -> arr[q -> front];
    }
    return val;
}

void display(struct circular_queue *q)
{
    int i = q -> front + 1;

    if(is_empty(q))
    {
        printf("Underflow condition\n");
    }

    else
    {
        printf("Element as follows\n");
        while(i != q -> rear)
        {
            printf("%d\n",q -> arr[i]);
            i = (i+1) % q -> size;
        }
        printf("%d",q->arr[i]);
    }
}

int main()
{
    
    int n,ch,flag=1,count=1,del_count = 0;
    struct circular_queue *q = (struct circular_queue *)malloc(sizeof(struct circular_queue));
    q -> front = q -> rear = 0;

    while(flag)
    {
        printf("Enter your choice\n1.Insert in the queue\n2.delete from the queue\n3.dispay\n");
        scanf("%d",&ch);
        
        if(ch == 1)
        {
            if(count == 1)
            {
                q -> size = n + 1;
                q -> arr = (int *)malloc(q -> size * (sizeof(int)));
                printf("How many elements you want to enter in the queue\n"); 
                scanf("%d",&n); 
                printf("\nEnter the elements\n");
                for(int i = 1; i <= n; i++)
                {
                    int element;
                    printf("Enter element %d\n",i);
                    scanf("%d",&element);
                    enqueue(q,element);
                }
            }

            else
            {
                printf("Number of elements deleted are %d and number of elments tht can be added are %d\n", del_count,
                del_count);
                printf("\nEnter elements\n");
                for(int i = 1; i <= del_count; i++)
                {
                    int element;
                    printf("Enter element %d\n",i);
                    scanf("%d",&element);
                    enqueue(q,element);
                }
                del_count = 0;
            }
        }
        else if(ch == 2)
        {
            int val = deque(q);
            printf("deleted element is\n");
            printf("%d\n",val);
            del_count++;
        }

        else if(ch == 3)
        {
            display(q);
        }

        else
        {
            exit(0);
        }

        int choice;
        printf("\nDo you want to performe any other operation(yes-1/no-0)\n");
        scanf("%d",&choice);
        if(choice)
        {
            count += 1;
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    return 0;
}
