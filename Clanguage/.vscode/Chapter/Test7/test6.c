#include <stdio.h>

float s1,s2,s3;//全局变量/外部变量

float fun(float a,float b,float c){
    float v;
    v=a*b*c;
    s1=a*b;
    s2=a*c;
    s3=b*c;
    return v;
}

int fun1(int a,int b){//局部变量
    int m;
    m=a+b;
    printf("fun1:m=%d\n",m);
    return m;
}
int fun2(int x,int y){//局部变量
    int n;
    n=x*y;
    printf("fun2:n=%d\n",n);
    return n;
}

int main(){//局部变量
    int m,n;
    m=0;
    n=0;
    m=fun1(3,4);
    n=fun2(3,4);
    printf("main:m=%d,n=%d\n",m,n);
    float v,l,w,h;
    printf("\ninput length,width and height:");
    scanf("%f%f%f",&l,&w,&h);
    v=fun(l,w,h);
    printf("\n v=%f,s1=%f,s2=%f,s3=%f\n",v,s1,s2,s3);
}