#include <stdio.h>
int main()
{
    int a,b,c;
    printf("请输入两个数: ");
    scanf("%d%d",&a,&b);
     c=a+b;
    printf("这两个数的和是%d\n",c);
   
    if(c%2==0){
        printf("这两个数的和是双数\n");
    }else{
        printf("这两个数的和是单数\n");
    }
}