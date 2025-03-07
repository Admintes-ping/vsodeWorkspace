#include <stdio.h>
#include <math.h>
int main()
{
    int m, j, isPrime;
    printf("Primenumber is:");
    for (m = 100; m <= 200; m++)
    {
        isPrime = true; // 假设m是素数
        for (j = 2; j <= sqrt(m); j++)
        {
            if (m % j == 0)
            {
                isPrime = false; // m能被j整除，不是素数
                break;
            }
        }
        if (isPrime == true && m > 1)
        {

            printf("%d ", m); // 输出素数
        }
    }
    printf("\n");
    // 找出分段和平方数
    int i = 1000, frontNum, rearNum;
    while (i < 10000)
    {
        rearNum = i % 100;
        frontNum = i / 100;
        if (i == (rearNum + frontNum) * (rearNum + frontNum))
        {
            printf("\n%d Segments and square roots\n", i);
        }
        i++;
    }
    // 求完数
    printf("\n");
    printf("a perfect number is:");
    int num = 1, remainder, q, sum = 0;
    while (num < 1000)
    {
        sum = 0;
        q = 1;
        while (q < num)
        {
            if ((remainder = num % q) == 0)
            {
                sum += q;
            }
            q++;
        }
        if (sum == num)
        {
            printf("%d ", num);
        }
        num++;
    }
    // 练习
    printf("\n");
    int a = 3;
    do
    {
        printf("%d ", a--); //先使用a,然后-1
    } while (!(-a)); //直到a为负数时停止
    printf("%d\n", a); 
    return 0;
}
