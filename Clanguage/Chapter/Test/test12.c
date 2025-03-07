#include <stdio.h>
#define N 10

int main()
{
    int a[N][N], i, j, k;

    // 初始化数组
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            a[i][j] = 1;
        }
    }

    // 计算杨辉三角形
    for (i = 2; i < N; i++)// 从第3行开始计算
    {
        for (j = 1; j < i; j++)// 计算第i行的第j列的数值
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    // 打印杨辉三角形
    for (i = 0; i < 5; i++)
    {
        for (k = 0; k < 34 - i * 3; k++)// 控制输出格式
        {
            printf(" ");
        }
        for (j = 0; j < i + 1; j++)
        {
            printf("%6d ", a[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}
