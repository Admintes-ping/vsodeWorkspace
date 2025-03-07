#include <stdio.h>
#include <stdbool.h>//引入bool类型
#include <stdlib.h>//引入标准库
//输出n以内的所有素数。它遍历从2到n的每个数，调用 is_prime 函数判断是否为素数，如果是素数，则使用 printf 函数打印输出
bool is_prime(int num){//is_prime函数，判断一个数是否为素数
    if(num<2){
        return false;
    }
    for(int i=2;i*i<=num;i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}
//void表示无类型返回值的函数
//print_primes函数是一个用于打印小于等于给定数字的所有素数的函数
void print_primes(int n){
    for(int num=2;num<=n;num++){
        if(is_prime(num)){//is_prime来判断一个数是否为素数，然后根据判断结果来输出素数
            printf("%d ", num);
        }
    }
}
int main()
{
    printf("Enter the range for determining prime numbers: ");
    int n;
    scanf("%d", &n);
    print_primes(n);
    return 0;
}