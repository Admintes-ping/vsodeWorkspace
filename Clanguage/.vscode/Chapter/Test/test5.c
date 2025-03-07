//判断一个数是否为质数
#include <stdio.h>
#include <math.h>
int main()
{
    int n, k, i;
    scanf("%d", &n);
    k = sqrt(n);
    for (i = 2; i <= k; i++)
    {
        if (n % i == 0)
        {
          printf("%d is not a prime number\n", n); 
        } break;
        if(i>k){
            printf("%d is a prime number\n", n);
        }
    }
    return 0;
}