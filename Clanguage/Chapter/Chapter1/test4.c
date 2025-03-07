#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand(time(NULL));//使用当前时间作为随机数种子
    int x=rand()%71+10;
    int num=5;
    int y;
    int count=0;
    for(int i=0;i<num;i++){
        scanf("%d",&y);
        count++;
         int remaining = num - count;
          if (remaining > 0){
            printf("you remaining %d times",num-count);
            printf("\n");
            if(count==num){
            printf("Game over,you failed! the answer is %d\n",x);       
            } 
        }
        if(x==y){
          printf("congratulation,You did it!\n"); 
        }else{
            if(x>y){
                printf("Too small,try again!\n");
            }else{
                printf("Too big,try again!\n");
            }
        }    
    }
    return 0;
}