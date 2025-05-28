#include<stdio.h>

int main(){
    float score[10];
    float min,max,sum=0,avg;
    int i;
    printf("Enter score:");
    for(i=0;i<10;i++){
        scanf("%f",&score[i]);
        sum+=score[i];
        if(i==0){
            min=max=score[i];
        }else{
            if(score[i]<min){
                min=score[i];
            }
            if(score[i]>max){
                max=score[i];
            }
        }

    }
    avg=sum/10;
    printf("Min score is %.2f\n",min);
    printf("Max score is %.2f\n",max);
    printf("Avg score is %.2f\n",avg);
    return 0;
}