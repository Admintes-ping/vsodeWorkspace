#include <stdio.h>
//求下标为奇数的元素之和
int main()
{
    int array1[10], array2[5];
    int i,k=-1;
    int sum=0;
    for(i=0; i<10; i++)
    {
        scanf("%d", &array1[i]);
    }
    for(i=0; i<10; i++){
        if(i%2!=0){
            k++;
            array2[k]=array1[i];//k作为计数器，当下标是奇数的时候，将元素存入array2
        } 
    }
    printf("Elements with new indices in array2 are: ");
    for(i=0; i<=k; i++){
        printf("%d ", array2[i]);
    }
    for(i=0; i<5; i++){
        sum+=array2[i];
    }
    printf("\nSum of elements in array2 is: %d", sum);
    return 0;
   
}