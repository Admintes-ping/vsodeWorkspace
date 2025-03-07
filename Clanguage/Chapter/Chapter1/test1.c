#include <stdio.h>
#include <math.h>
#define eps 1e-6//0.000001
int main(){
    int y=1;
    float x1,x0,f,f1;
    x1=1.0;
    for(int i=1;i<=9;i++){//逆推法求猴子吃桃问题
        y=(y+1)*2;
    }
    printf("%d",y);
    printf("\n");
    do{//牛顿迭代法求根
        x0=x1;
        f=((2*x0-4)*x0+3)*x0-6;
        f1=(6*x0-8)*x0+3;
        x1=x0-f/f1;
    }while(fabs(x1-x0)>eps);//判断我们能接受的精度，等于0.000001的时候跳出
    printf("%.6f",x1);
    return 0;
}