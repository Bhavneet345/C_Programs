#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *new1;
    int num;
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    new1 = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the number you want to add\n");
    scanf("%d",&num);

    head -> data = num;
    head -> next = second;
    second -> data = num+1;
    second -> next = third;
    third -> data = num+2;
    third -> next = NULL;

    //Insertion at the beginning//
    int data1;
    printf("Enter the number you want to add to new node\n");
    scanf("%d",&data1);
    new1 -> data = data1;
    new1 -> next = head;

    printf("\n");

    while (new1 != NULL)
    {
        printf("%d\n", new1->data);
        new1 = new1->next;
    }
    return 0;
}
