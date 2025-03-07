#include <stdio.h>
int main(){
    int x, y, z, result;
    printf("place enter three digits:");//请输入三位数
    scanf("%d %d %d", &x, &y, &z);//输出三位数
    result = x * y * z;//给结果赋值
    printf("the product is %d", result);
    return 0;

}
