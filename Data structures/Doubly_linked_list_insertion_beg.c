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
    if (head != NULL)
    {
        printf("%d\n", head -> data);
        return display(head -> next);
    }
}

struct Node* insert_beg(struct Node *head)
{
   int num;
   struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
   printf("\nEnter the number you want to insert to the new node\n");
   scanf("%d",&num);
   new_node -> prev = NULL;
   new_node -> next = head;
   new_node -> data = num;
   head -> prev = new_node;
   return new_node;
};

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

    printf("\n\nElement in the list\n");
    display(head);

    head = insert_beg(head);
    printf("\n\nUpdated element list\n");
    display(head);

    return 0;

}

