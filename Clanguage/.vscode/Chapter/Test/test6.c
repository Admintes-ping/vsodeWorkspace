// 输出奇数的数字和总和
//计算100-200的所有素数
#include <stdio.h>
#include <math.h>
int main()
{
    int i,sum = 0;
    for (i = 1; i <= 10; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d ", i); // 输出奇数   
        }
        if(i%2==0){
            continue;//跳出当前循环，继续下一个
        }
        else{
            sum += i; // 计算总和
        }
    }
    printf("\n");
    printf("Sum of odd numbers is: %d", sum); // 输出总和
    return 0;
}
