#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* insert_at_end(struct Node *head, int data1)
{
    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    while(p -> next != NULL)
    {
        p = p->next;
    }
    p -> next = ptr;
    ptr -> data = data1;
    ptr -> next = NULL;
    return head;
};

void print_data(struct Node *head)
{
    if(head != NULL)
    {
        printf("%d\n", head->data);
        return print_data(head->next);
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    int num,new_num;
    printf("Enter number you want to add\n");
    scanf("%d",&num);
    head -> data = num;
    head -> next = second;
    second -> data = num+1;
    second -> next = third;
    third -> data = num+2;
    third -> next = NULL;

    printf("Enter the number you want to insert at new node at the end\n");
    scanf("%d",&new_num);
    head = insert_at_end(head,new_num);
    printf("\nData in the linked list is as follows\n");
    print_data(head);
    return 0;
}
