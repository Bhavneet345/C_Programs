#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* insert_at_position(struct Node *head, int pos, int data1)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int count = 1;
    while(count < pos-1)
    {
        p = p->next;
        count += 1;
    }
    new_node -> next = p -> next;
    new_node -> data = data1;
    p -> next = new_node;
    return head;
};

void display(struct Node *head)
{
    while(head != NULL)
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

    int num,new_num,position;
    printf("Enter number you want to add\n");
    scanf("%d",&num);
    printf("\nEnter the position at which you want to insert the node\n");
    scanf("%d", &position);
    printf("\nEnter the data you want to insert at the new node\n");
    scanf("%d", &new_num);
    head -> data = num;
    head -> next = second;
    second -> data = num+1;
    second -> next = third;
    third -> data = num+2;
    third -> next = NULL;

    printf("\nElement in the list\n");
    display(head);

    printf("\nUpdated list");
    head = insert_at_position(head, position, new_num);
    printf("\n");
    display(head);

    return 0;
}
