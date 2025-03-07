#include <stdio.h>
#define M 20
#define N 4
int main()
{
    int i,j;
    float s[M][N],average[M],sum;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            scanf("%f",&s[i][j]);
        }
    }
    for(i=0;i<M;i++){
        sum=0.0;
        for(j=0;j<N;j++){
            sum+=s[i][j];
        }
        average[i]=sum/N;
    }
    for(i=0;i<M;i++){
        printf("Average[%d] =%0.1f\n",i+1,average[i]);
    }
    return 0;
}