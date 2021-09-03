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
    struct Node *p = head;

    printf("\n\nElement from the beginning\n");
    while (head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }

    printf("\nElements from the end\n");
    while (p -> next != NULL)
    {
        p = p -> next;
    }

    while(p != NULL)
    {
        printf("%d\n",p->data);
        p = p->prev;
    }
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    int num;

    printf("Enter the number you want to insert at the node\n");
    scanf("%d",&num);

    head -> data = num;
    head -> next = second;
    head -> prev = NULL;

    second -> data = num+1;
    second -> next = third;
    second -> prev = head;

    third -> data = num+2;
    third -> next = fourth;
    third -> prev = second;

    fourth -> data = num+3;
    fourth -> next = NULL;
    fourth -> prev = third;

    display(head);

    return 0;
}
