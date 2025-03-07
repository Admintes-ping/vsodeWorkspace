#include<stdio.h>

double sum(double s){//使用循环求和

    for(int i=1;i<=100;i++){
        s+=i;
    }
    return s;
}
int sum_int(int n){//使用递归求和
    if(n==1){
        return 1;
    }
    return sum_int(n-1)+n;
} 


int main(){
    double s=0;
    printf("1+2+3+...+100 = %.0lf",sum(s));
    printf("\n");
    printf("1+2+3+...+100 = %d",sum_int(100));

    return 0;
}