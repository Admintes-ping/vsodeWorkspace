// 输出九九乘法表
// 求Π值
// 求两个数之间的最大公约数
#include <stdio.h>
#include <math.h>
int main()
{
    // 九九乘法表
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%1d*%1d=%-5d ", i, j, i * j);
        }
        printf("\n");
    }
    // 求Π值
    int numerator;               // 存放分子
    float denominator, item, pi; // 分别存放分母、单个数据项和Π值
    item = 1, denominator = 1.0, numerator = 1;
    pi = 0; // 初始化
    while (fabs(item) > 1e-6)
    {
        pi += item;       // 累加数据项
        denominator += 2; // 分母加2
        numerator = -numerator;
        item = numerator / denominator;
    }
    pi = pi * 4;
    printf("pi=%10.9f\n", pi);
    // 求两个数之间的最大公约数
    int n, m, max, r;
    printf("enter m,n:");
    scanf("%d %d", &m, &n);
    if (m < n)
    {
        max = m;
        m = n;
        n = max;// 交换使得m为两数中较大的数，n为较小的数
    }
    while (n!= 0)
    {
        r = m % n;
        m = n;//最后的除数即为最大公约数
        n = r;
    }
    printf("greatest common divisor is:%d\n", m);
    return 0;
}