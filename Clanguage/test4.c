#include <stdio.h>
int process(int num) {
    int count =   0   ;
    while (num!=    1 ) {
        if (num % 2 ==    0  ) {
            num /= 2;
        } else {
            num = num * 3 + 1;
        }
        count++;
    }
    return count   ;
}
int main() {
    int n;
    printf("请输入一个正整数：");
    scanf("%d", &n);
    int times = process(n);
    printf("经过 %d 次操作后得到 1。\n",   times);
    return 0;
}
