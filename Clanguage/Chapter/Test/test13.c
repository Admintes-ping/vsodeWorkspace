/* #include <stdio.h>
#define N 5

int main()
{
    int a[N][N]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int i,j,sum=0,count=0;
    printf("this a 2D array is:\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){
            printf("%3d ",a[i][j]);
            count++;
            if(count%N==0){
                printf("\n");
            }
        }
    }
    printf("\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            sum+=a[i][j];
        }
    }
    printf("The sum of all elements in the array is: %d\n",sum);
    return 0;
}
 */
#include <stdio.h>
#define N 5

int main()
{
    int a[N][N]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int i, j;
    
    printf("Right upper triangle of the 2D array:\n");
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(j >= i) // Check if current element is in the right upper triangle
            {
                printf("%3d ", a[i][j]);
            }
            else
            {
                printf("    "); // Print spaces for elements outside the triangle
            }
        }
        printf("\n");
    }
    
    return 0;
}
