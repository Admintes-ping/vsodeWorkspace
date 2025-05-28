#include<stdio.h>

int findMaxConsecutiveOnes(int a[], int n){
    int maxCount = 0, count = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 0)
            count = 0;
        else{
            count++;
            maxCount = (maxCount > count) ? maxCount : count;
        }
    }
    return maxCount;
}

int main(){
    int n=8;
    int a[] = {1,1,0,1,1,1,1,0};
    int maxCount = findMaxConsecutiveOnes(a, n);
    printf("The count of maximum consecutive 1's is %d", maxCount);
    return 0;
}
