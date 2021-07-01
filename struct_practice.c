#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int marks;
    char name[50];
    int rno;
};
struct student bhavneet,harry,jai;
int main()
{
    bhavneet.rno = 25;
    strcpy(bhavneet.name,"Bhavneet");
    bhavneet.marks = 95;
    harry.rno = 26;
    strcpy(harry.name,"Harry");
    harry.marks = 90;
    jai.rno = 36;
    strcpy(jai.name,"Jai");
    jai.marks = 94;
    printf("Name is : %s\nRoll number is : %d\nMarks are: %d\n",bhavneet.name,bhavneet.rno,bhavneet.marks);
    printf("Name is : %s\nRoll number is : %d\nMarks are: %d\n",harry.name,harry.rno,harry.marks);
    printf("Name is : %s\nRoll number is : %d\nMarks are: %d\n",jai.name,jai.rno,jai.marks);
    return 0;
}
