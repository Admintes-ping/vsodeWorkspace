#include <stdio.h>
//水仙花数
// 一个n位的数，它的每个位上的数字的n次方之和等于这个数本身
// 例如：1^3 + 5^3 + 3^3 = 153
int main()
{
    int i,j,k;
    for(i=1;i<=9;i++){
        for(j=1;j<=9;j++){
            for(k=1;k<=9;k++){
                int num=i*100+j*10+k;
                if(i*i*i+j*j*j+k*k*k==num){
                    printf("%d\n",num);
                }
            }
        }
    }
}