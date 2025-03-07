#include <stdio.h>
//求10个学生的成绩的总和和平均值
int main()
{
    int score[10];
    int average;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &score[i]);
    }
    for (int i = 0; i < 10; i++){
        sum += score[i];
    }
    average = sum / 10;
    printf("The sum is %d\n", sum);
    printf("The  average is %d\n", average);
}