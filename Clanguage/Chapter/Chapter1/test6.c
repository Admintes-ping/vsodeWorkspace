/* 
#include <stdio.h>
#include <string.h>

int main()
{
    for(int i=100;i<=999;i++)//方法一：直接判断平方数
    {
        int square=i*i;
        char square_str[10];
        snprintf(square_str,sizeof(square_str),"%d",square);
        char num_str[4];
        snprintf(num_str,sizeof(num_str),"%d",i);
        if(strstr(square_str,num_str)!=NULL){
            printf("%d is a perfect square, its square is %d\n",i,square);
        }
   }
    return 0;
} */


// 方法二
#include<stdio.h>
int find(int x)				
{    int t;
       t=x*x;				
        while(t!=0)				
        {   
        if(x==t%1000) return 1;
	    t=t/10;
        }
        return 0;
}
int main()
{       int x;
        printf("i\tpower\n");
        for(x=100;x<1000;x++)
	    if(find(x))
		printf("%d\t%d\n",x,x*x);
        return 0;
}
