#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d\n",head -> data);
        head = head -> next;
    }
}

struct Node *delete_postion(struct Node *head, int position)
{
    struct Node *p = head;
    struct Node *q = head;
    int count = 1;
    int i = 1;

    while(count < position - 1)
    {
        p = p -> next;
        count = count + 1;
    }

    p -> next = p -> next -> next;
    p -> next -> prev = p;1

    return head;
};

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    int num, pos;

    printf("Enter the number you want to insert in the node\n");
    scanf("%d", &num);
    printf("Enter the position of the node you want to delete\n");
    scanf("%d", &pos);


    head -> data = num;
    head -> next = second;
    head -> prev = NULL;

    second -> data = num+1;
    second -> next = third;
    second-> prev = head;

    third -> data = num+2;
    third -> next = fourth;
    third -> prev = second;

    fourth -> data = num+3;
    fourth -> next = NULL;
    fourth -> prev = third;

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        printf("\nElement in the list\n");
        display(head);

        printf("\nUpdated list\n");
        head = delete_postion(head, pos);
        display(head);

    }

    return 0;
}
