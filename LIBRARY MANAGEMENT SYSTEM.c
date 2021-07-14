#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct library        //Structure to read and write the details of the book//
{
    int serial_no;
    char book_name[50];
    char author_name[50];
    int publish_year;
};
struct library l; //structure object to use structure for reading and writing in the file//

void display_records() //Function to display all the books in the Library//
{
    FILE *fp = NULL; //File pointer to access the file functions//
    fp = fopen("library.txt","rb");
    if(fp == NULL) //If file does not  exists prints the message and exits function is called//
    {
        printf("\t\t\tFile does not exists\n");
        exit(0);
    }
    printf("\t\t\tSerial No.\tBook name\tAuthor name\tPublication date\n");
    while((fread(&l,sizeof(l),1,fp)==1)) //reading the file till it reaches the null value//
    {
         printf("\n\t\t\t    %d   \t %s\t%s  \t   %d",l.serial_no,l.book_name,l.author_name,l.publish_year);
        printf("\n");
    }
    fclose(fp);
}

void insert_book() //Function to insert books in the Library//
{
    FILE *fp = NULL;
    fp = fopen("library.txt","ab");
    if(fp == NULL)
    {
        printf("\t\t\tFile does not exists\n");
        exit(0);
    }
    printf("\t\t\tPrevious records are as follows-:\n");
    display_records();
    printf("\n");
    int n;
    printf("\t\t\tHow many records do you want to enter:"); //Asking user about how many records he/she wants to enter//
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("\t\t\tEnter serial number:");
        scanf("%d",&l.serial_no);
        printf("\n\t\t\tEnter book name:");
        fflush(stdin);
        gets(l.book_name);
        printf("\n\t\t\tEnter Author name:");
        fflush(stdin);
        gets(l.author_name);
        printf("\n\t\t\tEnter year of publish:");
        scanf("%d",&l.publish_year);
        fwrite(&l,sizeof(l),1,fp);
    }
    fclose(fp);
    printf("\t\t\tRecord inserted successfully!!\n"); //Printing the message if record inserted successfully//
}

void search_book() //Function to search a particular book in the Library//
{
    int flag = 0;
    int book_no;
    FILE *fp = NULL;
    fp = fopen("library.txt","rb");
    if(fp == NULL)
    {
        printf("\t\t\tFile does not exists\n");
        exit(0);
    }
    printf("\t\t\tEnter the book serial number you are looking for");
    scanf("%d",&book_no);
    while((fread(&l,sizeof(l),1,fp)>0) && flag == 0)
    {
        if(l.serial_no == book_no) //searching performed on the basis of serial number//
        {
            flag = 1;
            printf("\t\t\tBook Found successfully\n");
            printf("\n\t\t\tSerial No.\tBook name\tAuthor name\tPublication date\n");
            printf("\n\t\t\t    %d   \t   %s   \t   %s  \t   %d",l.serial_no,l.book_name,l.author_name,l.publish_year);
            break;
        }
    }
    if (flag == 0)
    {
        printf("\t\t\tNo book with this book number found!!\n");
    }
    fclose(fp);
}

void delete_book()  //Function to delete a book in the Library//
{
    int flag = 0;
    FILE *fp = NULL;
    FILE *fc = NULL;
    fp = fopen("library.txt","rb");
    fc = fopen("new.txt","ab+");
    char b_name[50];
    printf("\t\t\tPrevious Record is as follows-:\n");
    display_records();
    printf("\t\t\tEnter the name of the book you want to delete:");
    fflush(stdin);
    gets(b_name);

    while((fread(&l,sizeof(l),1,fp)>0))
    {
        if(strcmp(l.book_name,b_name) != 0) //deletion on the basis of name of the book//
        {
            flag = 1;
            fwrite(&l,sizeof(l),1,fc);
            break;
        }
    }

    if(flag == 1)
    {
        printf("\t\t\tBook deleted successfully\n");
    }
    else
    {
        printf("No such book found\n");
    }
    fclose(fp);
    fclose(fc);
    remove("library.txt"); //removing the previous book//
    rename("new.txt","library.txt"); //renaming the book with the new records//
    printf("\t\t\t new record is as follows-:\n");
    display_records();
}

void update_book()  //Function to update the details of a book in the Library//
{
    int book_no;
    int flag = 0;
    FILE *fp,*fp1 = NULL;
    fp = fopen("library.txt","rb");
    fp1 = fopen("copy.txt","ab");
    if(fp == NULL)
    {
        printf("\t\t\tNo such file exists!!\n");
    }
    printf("\t\t\tPrevious Record is as follows-:\n");
    display_records();
    printf("\t\t\tEnter the book number of the book you want to update:");
    scanf("%d",&book_no);
    while((fread(&l,sizeof(l),1,fp) == 1) && flag == 0)
    {
        if(l.serial_no != book_no)
        {
          fwrite(&l,sizeof(l),1,fp1);
        }
        if(l.serial_no == book_no)  //returns 1 if the record is found//
        {
            flag = 1;
        }
    }
    if (flag == 1)  //condition to write new record in the file//
    {
        printf("\t\t\tRecord Found successfully\n");
        printf("\t\t\tEnter the new details-:\n");
        printf("\t\t\tEnter serial number:");
        scanf("%d",&l.serial_no);
        printf("\n\t\t\tEnter book name:");
        fflush(stdin);
        gets(l.book_name);
        printf("\n\t\t\tEnter Author name:");
        fflush(stdin);
        gets(l.author_name);
        printf("\n\t\t\tEnter year of publish:");
        scanf("%d",&l.publish_year);
        fwrite(&l,sizeof(l),1,fp1);
    }
    else if (flag == 0)
    {
        printf("\t\t\tNo such record found!!\n");
    }
    fclose(fp);
    fclose(fp1);
    remove("library.txt");
    rename("copy.txt","library.txt");
    printf("\t\t\tUpdated records are are follows\n");
    display_records();
}

int main() //main function to access the whole program and user is provided with various options//
{
    int ch;
    printf("\n");
    printf("\t\t*************************LIBRARY MANAGEMENT SYSTEM*****************************\n");
    printf("\n\t\tMADE BY-\n\t\tSNO.\t\tNAME\t\tENROLMENT NUMBER\n\t\t 1.\t BHAVNEET SINGH\t\t\t 025\n\t\t 2.\t HAR RANJAN PAL SINGH\t\t 040\n\t\t 3.\t DAVINDERPAL SINGH\t\t 030\n\t\t 4.\t ISHANT CHOUDHARY\t\t 054");
    printf("\n\n");
    printf("\t\t\t**********************ENTER YOUR CHOICE*************************\n");
    while (1) //loop runs till the user enter 6 which uses exit() function to move out of the loop//
    {
        printf("\t\t\t 1.DISPLAY BOOKS\n");
        printf("\t\t\t 2.INSERT BOOK\n");
        printf("\t\t\t 3.SEARCH BOOK\n");
        printf("\t\t\t 4.DELETE BOOK\n");
        printf("\t\t\t 5.UPDATE BOOK\n");
        printf("\t\t\t 6.EXIT");
        scanf("\n\t\t\t%d",&ch);
        printf("\t\t\tCHOICE ENTERED: %d",ch);
        switch (ch)
        {
        case 1:
            printf("\n\t\t\t 1.DISPLAY BOOKS\n");
            display_records();
            printf("\n");
            break;
        case 2:
            printf("\n\t\t\t 2.INSERT BOOK\n");
            insert_book();
            printf("\n");
            break;
        case 3:
            printf("\n\t\t\t 3.SEARCH BOOK\n");
            search_book();
            printf("\n");
            break;
        case 4:
            printf("\n\t\t\t 4.DELETE BOOK\n");
            delete_book();
            printf("\n");
            break;
        case 5:
            printf("\n\t\t\t 5.UPDATE BOOK\n");
            update_book();
            printf("\n");
        default:
            exit(0);
        }
    }

    return 0;
}



