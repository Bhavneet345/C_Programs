#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int rno;
    char name[20];
    struct Node *next;
};

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("Name is : %s and roll number is : %d\n", head -> name, head -> rno);
        head = head -> next;
    }
}

struct Node *create_node()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    int num,rno,n;
    char name[20];


    printf("How many student nodes you want to create\n");
    scanf("%d",&n);

    if(n >= 1)
    {
        printf("\nEnter the name you want to insert at node 1\n");
        fflush(stdin);
        gets(name);

        strcpy(head -> name,name);

        printf("\nEnter the roll number you want to insert at node\n");
        scanf("%d",&rno);

        head -> rno = rno;

        head -> next = NULL;

        struct Node *p = head;

        for(int i = 2; i <= n; i++)
        {
            struct Node *new_node =  (struct Node *)malloc(sizeof(struct Node));
            char name[20];

            printf("\nEnter the name you want to insert at node %d\n",i);
            fflush(stdin);
            gets(name);

            strcpy(new_node -> name,name);

            printf("\nEnter the roll number you want to insert at node\n");
            scanf("%d",&rno);

            new_node -> rno = rno;

            p -> next = new_node;
            p = p -> next;
        }
        return head;
    }

    else
    {
        return NULL;
    }

};

struct Node *reverse(struct Node *head)
{
    struct Node *first = head;
    struct Node *second = first -> next;
    struct Node *third = second -> next;

    if (first == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        first -> next = NULL;
        second -> next = first;

        while (third != NULL)
            {
                first = second;
                second = third;
                third = third -> next;
                second -> next = first;
            }

        first = second;
        return first;
    }
}

int count_node(struct Node *head)
{
    int count = 1;

    if (head == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        while(head -> next != NULL)
        {
            head = head -> next;
            count += 1;
        }
        return count;
    }
}

struct Node *insert_node(struct Node *head)
{
    int ch;
    char name[20];
    int rno;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        printf("\nElements in the list\n");
        display(head);

        printf("\nEnter your choice at which position you want to add the node\n1.Beginning\n2.Specified position\n3.End\n");
        scanf("%d",&ch);

        if(ch == 1)
        {
            int num;
            printf("\n\nInsert node at beginning\n");
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

            printf("\nEnter the name you want to insert at new node\n");
            fflush(stdin);
            gets(name);

            strcpy(new_node -> name,name);

            printf("\nEnter the roll number you want to insert at node\n");
            scanf("%d",&rno);

            new_node -> rno = rno;
            new_node -> next = head;
            head = new_node;
            printf("\n\nUpdated list is as follows\n");
            return head;
        }

         if(ch == 2)
        {
            int num, pos,count=1;
            struct Node *p = head;
            printf("\n\nInsert node at positon\n");
            printf("At which position you want to add the node\n");
            scanf("%d",&pos);
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

            while (count < pos -1)
            {
                p = p -> next;
                count = count + 1;
            }

            printf("\nEnter the name you want to insert at the new node\n");
            fflush(stdin);
            gets(name);
            strcpy(new_node -> name,name);

            printf("\nEnter the roll number you want to insert at node\n");
            scanf("%d",&rno);
            new_node-> rno = rno;

            new_node -> next = p -> next;
            p -> next = new_node;

            printf("\n\nUpdated list is as follows\n");
            return head;
        }

         if(ch == 3)
        {
            int num;
            struct Node *p = head;
            printf("\n\nInsert node at end\n");
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));


            while ( p-> next != NULL)
            {
                p = p -> next;
            }


            printf("\nEnter the name you want to insert at the new node\n");
            fflush(stdin);
            gets(name);
            strcpy(new_node -> name,name);

            printf("\nEnter the roll number you want to insert at node\n");
            scanf("%d",&rno);
            new_node -> rno = rno;

            p -> next = new_node;

            printf("\n\nUpdated list is as follows\n");
            return head;
        }
    }
};

struct Node *delete_node(struct Node *head)
{
    int ch;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }

    else
    {
        printf("\nElements in the list\n");
        display(head);

        printf("\nEnter your choice at which position you want to delete the node\n1.Beginning\n2.Specified position\n3.End\n");
        scanf("%d",&ch);

        if(ch == 1)
        {
            printf("\n\nDelete node at beginning\n");
            head = head -> next;
            printf("\n\nUpdated list is as follows\n");
            return head;
        }

         if(ch == 2)
        {
            int num, pos,count=1;
            struct Node *p = head;
            printf("\n\nDelete node at position\n");
            printf("At which position you want to delete the node\n");
            scanf("%d",&pos);

            while (count < pos -1)
            {
                p = p -> next;
                count = count + 1;
            }

            p -> next = p -> next -> next;

            printf("\n\nUpdated list is as follows\n");
            return head;
        }

         if(ch == 3)
        {
            int num;
            struct Node *p = head;
            printf("\n\nDelete node at end\n");
            while ( p-> next -> next != NULL)
            {
                p = p -> next;
            }

            p -> next = NULL;

            printf("\n\nUpdated list is as follows\n");
            return head;
        }
    }
};


int main()
{
    struct Node *head = NULL;
    int ch, choice, flag = 1;
    printf("Enter your choice \n1.Create node\n2.Insert node\n3.Delete node\n4.count node\n5.reverse node\n6.display\n7.exit\n");
    scanf("%d",&ch);

    while (flag == 1)
    {
        if(ch == 1)
            {
                head = create_node();
                printf("\nElements of the nodes are\n");
                display(head);
            }
        else if(ch == 2)
            {
                head = insert_node(head);
                display(head);
            }
        else if(ch == 3)
            {
                head = delete_node(head);
                display(head);
            }
        else if(ch == 4)
            {
                int count;
                count = count_node(head);
                printf("\n\nNumber nodes :%d",count);
            }
        else if(ch == 5)
            {
                head = reverse(head);
                printf("\nreversed list is\n");
                display(head);
            }
        else if(ch == 6)
        {
            printf("\n\nElements are\n");
            display(head);
        }
        else if(ch == 7)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid choice\n");
        }

        printf("\n\nDo you want to perform any other operation (yes - 1)/ (no - 0)??\n");
        scanf("%d",&choice);

          if (choice == 1)
          {
              printf("\nEnter your choice \n1.Create node\n2.Insert node\n3.Delete node\n4.count node\n5.reverse node\n6.display\n7.exit\n");
              scanf("%d",&ch);
              flag = 1;
          }

          else
          {
              flag = 0;
          }

    }

    return 0;
}


