#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node* delete_beg(struct Node *head)
{
    head = head -> next;
    head -> prev = NULL;
    return head;
};


void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
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

    if (head == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        printf("\nElements in the list\n");
        display(head);

        printf("\nElements after deletion\n");
        head = delete_beg(head);
        display(head);
    }
}
