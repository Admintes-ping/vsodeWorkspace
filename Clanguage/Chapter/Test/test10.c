#include <stdio.h>

int main()
{
    int i, a[10], pos = -1, x;
    
    // 提示用户输入数组元素
    printf("input a[10]: ");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &a[i]);// 输入数组元素
    }
    
    // 提示用户输入要查找的数字
    printf("Enter a number: ");
    scanf("%d", &x);
    
    // 查找数字在数组中的位置
    for (i = 0; i < 10; i++)
    {
        if (a[i] == x)
        {
            pos = i;
            break;
        }
    }
    
    // 输出结果
    if (i < 10){
        printf("The number %d is at position %d\n", x, pos + 1); // 位置从1开始
    }
    else{
        printf("The number %d is not in the array\n", x);
    }
    
    return 0;
}
