#include <stdio.h>
int main()
{
    int n=4;//菱形的半高度
    for(int i=1;i<=n;i++){//打印上半部分
        for(int j=1;j<=n-i;j++){
            printf(" ");//打印空格
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=n-1;i>=1;i--){//打印下半部分
        for(int j=1;j<=n-i;j++){
            printf(" ");//打印空格
        }
        for(int j=1;j<=2*i-1;j++){
            printf("*");
        }
        printf("\n");
        }
        return 0;
    }
