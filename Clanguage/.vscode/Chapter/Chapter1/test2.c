#include <stdio.h>

int main()
{
    int men, women, child;//双重循环计算36块砖被36个人分配
    for (men = 1; men < 9; men++)
    {
        for (women = 1; women < 12; women++)
        {
            child = 36 - men - women;
            if (men * 4 + women * 3 + child * 0.5 == 36)
            {
                printf("men:%d,women:%d,child:%d\n", men, women, child);
            }
        }
    }

    int i, j, k;//三重循环计算不同数字的组合（1，2，3，4）
    int count = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (k = 0; k < 4; k++)
            {
                if (i != j && i != k && j != k)
                {
                    printf("%d %d %d\n", i, j, k);
                    count++;
                }
            }
        }
    }
    printf("count:%d\n", count);

    return 0;
}