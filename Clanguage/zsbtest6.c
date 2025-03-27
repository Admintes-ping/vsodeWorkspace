#include <stdio.h>
int sanjiaoxing(int a, int b, int c){
    if(a+b>c && a+c>b && b+c>a){
        printf("可以构成三角形\n");
        if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a){
            printf("是等腰直角三角形\n");
        }
    }
}


int main() {
    int a, b, c;
    int x=10;
    while (x>5)
    {
        --x;
    }
    printf("x=%d\n",x);
    
    printf("请输入三个整数：");
    scanf("%d%d%d", &a, &b, &c);
    sanjiaoxing(a, b, c);
    return 0;

}