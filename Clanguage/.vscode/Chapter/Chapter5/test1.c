#include <stdio.h>  
int main()  {
    int a;
    int digit[4];
    int length=0;
    printf("Enter an integer of no more than four digits: ");
    scanf("%d", &a);
    while(a>0){//循环直到a为0
        digit[length]=a%10;//存储每一位数字
        a=a/10;//去掉最后一位数字
        length++;//每去掉一位数字，length加1
    }
    for(int i=length-1;i>=0;i--){//倒序输出每一位数字
        printf("%d",digit[i]);
    }
    printf("\ndigit number: %d",length);

}