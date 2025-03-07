#include <stdio.h>
int age(int n){
    if(n==1){
        return 10;
    } 
    return age(n-1)+2;
}
main(){
    printf("%d",age(5));
    printf("\n");
    int year,leap;
    printf("Enter a year: ");
    scanf("%d",&year);
    if ((year%4==0&&year%100!=0)||(year%400==0))
    {
        leap=1;
        /* code */
    }else{
        leap=0;
    }
    if(leap){
        printf("%d is a leap year",year);
    }else{
        printf("%d is not a leap year",year);
    }
    printf("\n");
    int n;
    int fact=1;
    printf("Enter a number: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("fact is %d\n",fact);
    return 0;
}