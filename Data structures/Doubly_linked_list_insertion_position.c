#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node*prev;
};

struct Node* insert_pos(struct Node *head, int position)
{
    int count = 1;
    int num;
    struct Node *p = head;

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    while (count < position - 1)
    {
        p = p -> next;
        count += 1;
    }

    printf("\n\nEnter the number you want to insert at the new node\n");
    scanf("%d",&num);

    new_node -> data = num;
    new_node -> next = p -> next;
    new_node -> prev = p;
    p -> next = new_node;
    new_node -> next -> prev = new_node;

    return head;

};

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d\n",head -> data);
        head = head -> next;
    }
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    int num, pos;

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

    printf("\nElements in the list\n");
    display(head);

    printf("\n\nEnter the position at which you want to insert the node\n");
    scanf("%d",&pos);


    head = insert_pos(head, pos);
    printf("\n\nUpdated list elements\n");
    display(head);

    return 0;

}
