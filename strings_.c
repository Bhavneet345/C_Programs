#include<stdio.h>
#include<stdlib.h>
int count_char(char str1[])
{
    int i=0;
    int count=0;
    for(i=0;str1[i]!='\0';i++)
    {
        count+=1;
    }
    return count;
}
void concate(char str1[],char str2[])
{
    int n;
    printf("Enter the dimension of the Concatenated string\n");
    scanf("%d",&n);
    char conacte[n];
    int l =  count_char(str1);
    for(int i=0;i<l;i++)
    {
        conacte[i] = str1[i];
    }
    int len = count_char(str2);
    int k = l;
    for(int j=0;j<len;j++)
    {
       conacte[k] = str2[j];
       k = k+1;
    }
    printf("Concatenated string is:");
    puts(conacte);
}
int copy_string(char str1[])
{
    int len = count_char(str1);
    int j=0;
    char copied[len];
    for(int i=0;str1[i]!='\0';i++)
    {
        j = j+1;
        copied[i] = str1[i];
    }
    copied[j] = '\0';
    printf("Copied String is:");
    puts(copied);
}
void reversal(char str1[])
{
    char temp;
    int last = count_char(str1)-1;
    int len = (count_char(str1)-1) / 2;
    for(int i=0;i<=len;i++)
    {
        temp = str1[i];
        str1[i] = str1[last-i];
        str1[last-i] = temp;
    }
    printf("Reversed string is: ");
    puts(str1);
}
int main()
{
    int ch;
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        printf("String length!!\n");
        char str[100];
        printf("Enter the string which length you want to know\n");
        scanf("%s",&str);
        int l = count_char(str);
        printf("Length is : %d",l);
        break;
    case 2:
        printf("String concatenation!!\n");
        char str1[100];
        printf("Enter the string which you want to concatenate\n");
        scanf("%s",&str1);
        char str2[100];
        printf("Enter the string2 which you want to concatenate\n");
        scanf("%s",&str2);
        concate(str1,str2);
        break;
    case 3:
        printf("String copy\n");
        char str3[100];
        printf("Enter the string which you want to copy\n");
        scanf("%s",&str3);
        copy_string(str3);
        break;
    case 4:
        printf("String reversal\n");
        char str5[100];
        printf("Enter the string which you want to reverse\n");
        scanf("%s",&str5);
        reversal(str5);
        break;
    default:
        printf("Invalid request!!");
    }
    return 0;
}
