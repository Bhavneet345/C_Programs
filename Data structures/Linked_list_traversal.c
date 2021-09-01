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
   int num;
   head = (struct Node *) malloc(sizeof(struct Node));
   second = (struct Node *) malloc(sizeof(struct Node));
   third = (struct Node *) malloc(sizeof(struct Node));
   printf("Enter the number you want to store in the list\n");
   scanf("%d", &num);
   head -> data = num;
   head -> next = second;
   second -> data = num+1;
   second -> next = third;
   third -> data = num+2;
   third -> next = NULL;
   printf("\nElement are as follows\n");
   while (head != NULL)
   {
       printf("%d\n", head->data);
       head = head->next;
   }
   return 0;
}
