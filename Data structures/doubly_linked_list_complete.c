#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    struct Node *next;
    struct Node *prev;
    int roll_no;
    char name[20];
};

void display(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        while(head != NULL)
        {
            printf("Name is : %s and roll number is: %d\n", head->name, head->roll_no);
            head = head -> next;
        }
    }
}

struct Node *create_new_node(int n)
{
    char name1[20];
    int rno;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the name you want to insert at node 1\n");
    fflush(stdin);
    gets(name1);
    strcpy(head->name,name1);
    printf("Enter the roll number you want to insert at node 1\n");
    scanf("%d",&rno);
    head -> roll_no = rno;
    head -> next = NULL;
    head -> prev = NULL;
    struct Node *p = head;

    for(int i = 2; i <= n; i++)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter the name you want to insert at node %d\n", i);
        fflush(stdin);
        gets(name1);
        strcpy(new_node->name,name1);

        printf("Enter the roll number you want to insert at node %d\n",i);
        scanf("%d",&rno);

        new_node -> roll_no = rno;
        new_node -> next = NULL;
        new_node -> prev = p;

        p -> next = new_node;
        p = p -> next;
    }

    return head;
};

int count_node(struct Node *head)
{
    int count = 1;
    struct Node *p = head;

    if(head == NULL)
    {
        printf("List is empty");
        return;
    }

    else
    {
        while(p -> next != NULL)
        {
            count = count + 1;
            p = p -> next;
        }

        return count;
    }
}

struct Node *insert_new_node(struct Node *head)
{
    int ch,rno;
    char name1[20];

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        printf("Elements in list are\n");
        display(head);
        printf("Enter at which position you want to insert node\n1.beginning\n2.specified position\n3.end\n");
        scanf("%d",&ch);

        if(ch == 1)
            {
                struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
                printf("Insertion at beginning\n");

                new_node -> prev = NULL;

                printf("Enter the name you want to insert at new node\n");
                fflush(stdin);
                gets(name1);
                strcpy(new_node->name,name1);

                printf("Enter the roll number you want to insert at new node\n");
                scanf("%d",&rno);
                new_node -> roll_no = rno;

                new_node -> next = head;
                head -> prev = new_node;

                head = new_node;

                return head;
            }

            else if(ch == 2)
                {
                    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
                    struct Node *p = head;
                    int pos,count=1;
                    printf("Insertion at specified position\n");
                    printf("Enter at which position you want to insert the new node\n");
                    scanf("%d",&pos);

                    while(count < pos-1)
                        {
                            p = p -> next;
                            count += 1;
                        }

                    printf("Enter the name you want to insert at new node\n");
                    fflush(stdin);
                    gets(name1);
                    strcpy(new_node->name,name1);

                    printf("Enter the roll number you want to insert at new node\n");
                    scanf("%d",&rno);
                    new_node -> roll_no = rno;

                    new_node -> next = p -> next;
                    new_node -> prev = p;
                    p -> next = new_node;
                    new_node -> next -> prev = new_node;

                    return head;
                }

                else if(ch == 3)
                    {
                        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
                        struct Node *p = head;

                        while (p -> next != NULL)
                            {
                                p = p -> next;
                            }

                        printf("Enter the name you want to insert at new node\n");
                        fflush(stdin);
                        gets(name1);
                        strcpy(new_node->name,name1);

                        printf("Enter the roll number you want to insert at new node\n");
                        scanf("%d",&rno);
                        new_node -> roll_no = rno;

                        new_node -> prev = p;
                        new_node -> next = NULL;

                        p -> next = new_node;

                        return head;
                    }

                else
                    {
                        printf("Invalid choice\n");
                        exit(0);
                    }
    }
};

struct Node *delete_node(struct Node *head)
{
    int ch;
    printf("Elements in list are\n");
    display(head);
    printf("Enter at which position you want to delete the node\n1.beginning\n2.specified position\n3.end\n");
    scanf("%d",&ch);

    if (head == NULL)
    {
            printf("List is empty\n");
            return;
    }

    else
    {
        if(ch == 1)
        {
            printf("Deletion at the beginning\n");
            head = head -> next;
            head -> prev = NULL;
            return head;
        }

        else if(ch == 2)
            {
                printf("Deletion at the specified position\n");
                struct Node *p = head;
                int pos,count=1;
                printf("Enter at which position you want to insert the new node\n");
                scanf("%d",&pos);

                while(count < pos-1)
                    {
                        p = p -> next;
                        count = count + 1;
                    }

                p -> next = p -> next -> next;
                p -> next -> prev = p;

                return head;
            }

        else if(ch == 3)
            {
                struct Node *p = head;
                printf("Deletion at the end\n");

                while(p -> next -> next != NULL)
                    {
                        p = p -> next;
                    }

                    p -> next = NULL;
                    return head;
            }

        else
            {
                printf("Invalid choice\n");
                exit(0);
            }
    }

};

struct Node *reverse_node(struct Node *head)
{
    struct Node *first = head;
    int count = count_node(first);

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    else
    {
        if (count == 1)
        {
            return head;
        }

        else
        {
          struct Node *first = head;
          struct Node *second = head -> next;
          struct Node *third = second -> next;

          first -> next = NULL;
          first -> prev = second;
          second -> next = first;
          second -> prev = third;

          while(third !=  NULL)
            {
                first = second;
                second = third;
                second -> next = first;
                third = third -> next;
                second -> prev =  third;
            }

        head = second;
        return head;

        }
    }
};

int main()
{
    struct Node *head = NULL;
    int ch, choice;
    int flag = 1;
    printf("Enter your choice \n1.Create node\n2.Insert node\n3.Delete node\n4.count node\n5.reverse node\n6.display\n7.exit\n");
    scanf("%d",&ch);

    while (flag == 1)
    {
        if(ch == 1)
            {
                int num;
                printf("\nEnter the number of nodes\n");
                scanf("%d", &num);
                head = create_new_node(num);
                printf("\nElements of the nodes are\n");
                display(head);
            }
        else if(ch == 2)
            {
                head = insert_new_node(head);
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
                head = reverse_node(head);
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
