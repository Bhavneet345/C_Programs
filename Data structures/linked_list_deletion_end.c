#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* delete_end(struct Node *head)
{
    struct Node *p = head;

    while(p -> next -> next != NULL)
    {
        p = p->next;
    }
    p -> next = NULL;

    return head;
};

void display(struct Node* head)
{
    while(head != NULL)
    {
        printf("%d\n",head->data);
        head = head -> next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    int num;

    printf("Enter the number you want to insert in the list\n");
    scanf("%d",&num);

    head -> data = num;
    head -> next = second;
    second -> data = num+1;
    second -> next = third;
    third -> data = num+2;
    third -> next = fourth;
    fourth -> data = num+3;
    fourth -> next = NULL;

    if(head == NULL)
    {
        printf("No node found\n");
    }

    printf("\nElement in the list\n\n");
    display(head);

    printf("\nUpdated list\n\n");
    head = delete_end(head);
    display(head);

    return 0;
}






