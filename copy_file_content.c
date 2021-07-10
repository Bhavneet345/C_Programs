#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *ptr1 = "NULL";
    FILE *ptr2 = "NULL";
    char filename[100];
    printf("Enter the file name from which the content is to be copied\n");
    scanf("%s",&filename);
    if (filename == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        ptr1 = fopen("copy1.txt","r");
    }
    printf("Enter the file name to which content is to be copied\n");
    scanf("%s",&filename);
    if(filename == NULL)
    {
        printf("File does not exist\n");
    }
    else
    {
        ptr2 = fopen("copy2.txt","w");
    }
    char c = fgetc(ptr1);
    while(c!=EOF)
    {
        fputc(c,ptr2);
        c = fgetc(ptr1);
    }
    printf("File copied successfully\n");
    fclose(ptr1);
    fclose(ptr2);
    return 0;
}
