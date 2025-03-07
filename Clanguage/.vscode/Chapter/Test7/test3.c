#include <stdio.h>
long getFactorial(int n){
    long value=1;
    int i;
    for(i=1;i<=n;i++){
        value*=i;    
    } 
    return value;
}
long getSquare(int m){
    int k;
    long r;
    k=m*m;
    r=getFactorial(k);
    return r;
}
int main(){
    int x,y;
    printf("Enter two numbers: ");
    scanf("%d%d",&x,&y);
    long s=0;
    s=getSquare(x)+getSquare(y);
    printf("\n%d^2 + %d^2 = %ld",x,y,s);
    return 0;
}