#include<stdio.h>

int main()
{
    int a, b, c, d;
    printf("请输入一个数: "); // 提示用户输入
    scanf("%d", &a);
    
    b = a * a * a;
    printf("这是%d的立方%d\n", a, b);
    
    c = a * a;
    printf("这是%d的平方%d\n", a, c);
    
    if (a != 0) { // 避免除以零
        d = b / c;
        printf("这是立方除以平方的结果%d\n", d);
    } else {
        printf("除数不能为零\n");
    }
    
    return 0;
}
