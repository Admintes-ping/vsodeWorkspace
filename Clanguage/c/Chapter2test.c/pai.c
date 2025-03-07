#include <stdio.h>
main()
{
    double P = 3.14159;
    double radius, dia, perimeter, area; // 定义半径，直径，周长，面积
    printf("please input radius:");
    scanf("%d", &radius);
    printf("dia is %d\n perimeter is %d\n area is %d ", radius * 2, 2 * P * radius, P * radius); // 计算直径，周长，面积
}