#include <stdio.h>
#include <stdlib.h> // 添加此行以声明abs函数
// 计算最大公约数（GCD）用于约分
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int n;
    // 分子和分母初始化
    int numerator = 0;// 分子
    int denominator = 1;// 分母

    // 输入验证
    do
    {
        printf("Enter a number (greater than 1 and less than or equal to 100): "); 
        scanf("%d", &n);
    } while (n <= 1 || n > 100);
    
    // 计算表达式 s = 1 - 1/2 + 1/3 - 1/4 + ... + 1/(2n-1) - 1/(2n)
    for (int i = 1; i <= 2 * n; i++) {
        int sign = (i % 2 == 0) ? -1 : 1;
        // 先将分子调整为当前的分子
        numerator = numerator * i + sign * denominator;
        // 更新分母为当前i
        denominator *= i;
        // 约分
        int divisor = gcd(abs(numerator), denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    // 打印结果
    printf("result = %d/%d\n", numerator, denominator);
    
    return 0;
}

