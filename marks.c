#include<stdio.h>
#include<stdlib.h>
int main()
{
    int marks1,marks2,marks3,marks4,marks5;
    float percentage;
    char grade;
    printf("Enter marks of your subjects\n");
    scanf("%d %d %d %d %d",&marks1,&marks2,&marks3,&marks4,&marks5);
    percentage=(marks1+marks2+marks3+marks4+marks5)/5;
    printf("Percentage is %f",percentage);
    if(percentage>90 && percentage<=100)
    {
        grade='A+';
        printf("Grade is %c",grade);
    }
    else if(percentage>80 && percentage<=90)
    {
        grade='A';
        printf("Grade is %c",grade);
    }
    else if(percentage>70 && percentage<=80)
    {
        grade='B';
        printf("Grade is %c",grade);
    }
    else if(percentage>60 && percentage<=70)
    {
        grade='C';
        printf("Grade is %c",grade);
    }
    else if(percentage>50 && percentage<=60)
    {
        grade='D';
        printf("Grade is %c",grade);
    }
    else
    {
        printf("Sorry!Can't display marks");
    }
    return 0;
}
