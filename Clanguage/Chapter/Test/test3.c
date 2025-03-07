#include <stdio.h>

int main()
{
    int i;
    for(i=1;i<=40;i++)
    {
        if(i++%5==0){//30 ，i++ 将 i 的值增加 1，此时 i=31
            if (++i%8==0)//31 ，++i 将 i 的值增加 1，此时 i=32
            {
                printf("%d ",i);
            }
            printf("\n ");
        }
    }
}