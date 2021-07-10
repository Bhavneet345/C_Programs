#include<stdio.h>
#include<stdlib.h>
void write_emp()
{
    FILE *ptr1 = "NULL";
    ptr1 = fopen("employe.txt","a");
    int n;
    char name[100];
    int emp_no;
    int salary;
    printf("Enter the number of employees whose data you want to enter\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter employee number\n");
        scanf("%d",&emp_no);
        printf("Enter employee name\n");
        scanf("%s",&name);
        printf("Enter employee salary\n");
        scanf("%f",&salary);
        fprintf(ptr1,"%d %s %d \n",emp_no,name,salary);
    }
    printf("File updated successfully\n");
}
void read_emp()
{
    FILE *ptr1 = "NULL";
    ptr1 = fopen("employe.txt","r");
    char c = fgetc(ptr1);
    while((fscanf(ptr1,"%c",&c)) != EOF)
    {
        printf("%c",c);
    }
}
void write_man()

{
    FILE *ptr2 = "NULL";
    ptr2 = fopen("manager.txt","a");
    int n;
    char name[100];
    int man_no;
    int salary;
    printf("Enter the number of managers whose data you want to enter\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("Enter manager number\n");
        scanf("%d",&man_no);
        printf("Enter manager name\n");
        scanf("%s",&name);
        printf("Enter manager salary\n");
        scanf("%d",&salary);
        fprintf(ptr2,"%d %s %d \n",man_no,name,salary);
    }
    printf("File updated successfully\n");
}
void read_man()
{
    FILE *ptr2 = "NULL";
    ptr2 = fopen("manager.txt","r");
    char c;
    while((fscanf(ptr2,"%c",&c)) != EOF)
    {
        printf("%c",c);
    }
}
int main()
{
    int ch;
    printf("Enter your choice\n 1.Write in employee file\n 2.read employee file\n"
            " 3.Write in manager file\n 4.read manager file\n 5.exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("Writing the employee file\n");
        write_emp();
        break;
    case 2:
        printf("Reading employee file\n");
        read_emp();
        break;
    case 3:
        printf("Writing the manager file\n");
        write_man();
        break;
    case 4:
        printf("Reading the manager file\n");
        read_man();
        break;
    case 5:
        exit(0);
        break;
    default:
        printf("invalid request\n!!");
    }
    return 0;
}
