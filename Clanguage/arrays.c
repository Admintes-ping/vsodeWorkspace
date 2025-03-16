// 测试数组
#include <stdio.h>
#include <string.h>

int main()
{
    int a[30];
    int b[6];
    int i, j;
    for (i = 0; i < 30; i++)
    {
        a[i] = 2 + i * 2;
    }
    for (i= 0; i < 6; i++)
    {
        int sum=0;
        for(j=0;j<5;j++){
            sum+=a[i*5+j];
        }
        b[i]=sum/5;
    }
    printf("每5个数的平均值为：");
    for (i = 0; i < 6; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    return 0;
}