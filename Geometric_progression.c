#include<stdlib.h>
#include<math.h>
int main()
{
    int a;  /*for 1st term of the Geometric Progression*/
    int common_difference; /*for the common difference of the GP*/
    int n;/*For term upto which user want the sum of the Geometric Progression*/
    int GP;
    printf("WELCOME TO THE PROGRAM OF GEOMETRIC PROGRESSION\n");
    printf("Enter the first term\n");
    scanf("%d",&a);
    printf("Enter the common difference\n");
    scanf("%d",&common_difference);
    printf("Enter the last term\n");
    scanf("%d",&n);
    GP =(a*(pow(common_difference,n)-1)/(common_difference-1));
    printf("GP IS: %d",GP);
    return 0;
}

