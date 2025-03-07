#include <stdio.h>
#include <math.h>
int is_prime(int x){
    int i;
    for(i=2;i<=sqrt(x);i++){
        if(x%i==0){
            return 0;
        } 
    } 
    return 1;
}

int main()
{
    int x;
    int m,n;
    int count=0;
    for(x=6;x<=100;x++){
        if(x%2==0){
            for(m=2;m<x-2;m++){
                n=x-m;
                if(is_prime(m)&&is_prime(n)){
                    count++;
                    printf("%5d=%d+%d",x,m,n);
                    if(count%5==0){
                        printf("\n");
                    }
                }
            }
        }
    }
}