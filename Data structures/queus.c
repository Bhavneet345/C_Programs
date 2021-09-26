#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int rear,front,top;
    int size;
    int *arr;
};

int is_empty(struct queue *q)
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

int is_full(struct queue *q)
{
    if(q -> rear == (q -> size)- 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void enqueue(struct queue *q,int val)
{
    if(is_full(q))
    {
        printf("Overflow condition\n");
    }

    else
    {
        q->rear++;
        q->arr[q -> rear] = val;
    }
}

int deque(struct queue *q)
{
    if(is_empty(q))
    {
        printf("Underflow condition\n");
    }

    else
    {
        q->front++;
        int val = q -> arr[q ->front];
        return val;
    }
}

void display(struct queue *q,int start)
{
    if(!is_empty(q))
    {
        printf("Following are the elements\n");
        while (start <= (q -> size) - 1)
        {
            printf("%d\n",q -> arr[start]);
            start += 1;
        }
    }

    else
    {
        printf("No element found\n");
    }
}

int main()
{
    int n,element,ch,flag=1,i=0;
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q -> front = q -> rear = -1;
       
    while(flag)
    {
        printf("Enter your choice\n1.Insert in the queue\n2.delete from the queue\n3.dispay\n");
        scanf("%d",&ch);
        if(ch == 1)
        {
            q -> front = -1;
            q -> rare = -1;   
            printf("Enter how many elements you want in the queue\n");
            scanf("%d",&n);
            q -> size = n;
            q -> arr = (int *)malloc(q -> size * (sizeof(int)));
            for(int i = 1; i <= n; i++)
            {
                printf("Enter element %d\n",i);
                scanf("%d",&element);
                enqueue(q,element);
            }
        }

        else if(ch == 2)
        {
            int val = deque(q);
            i += 1;
            if(i == n+1)
            {
                return 0;
            }
            printf("deleted element is\n");
            printf("%d\n",val);
        }

        else if(ch == 3)
        {
            display(q,i);
        }

        else
        {
            exit(0);
        }

        int choice;
        printf("Do you want to performe any other operation(yes-1/no-0)\n");
        scanf("%d",&choice);
        if(choice)
        {
            flag = 1;
        }
        else
        {
            flag = 0;
        }
    }
    return 0;
}
