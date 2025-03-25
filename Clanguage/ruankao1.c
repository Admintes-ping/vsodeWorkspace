#include <stdio.h>
int main(){
 int a[6]={85,40,73,16};
 int i,j,n=sizeof(a)/sizeof(int);
 for(i=0;i<n;++i)
 printf("%d ",a[i]);
 for(i=0,j=n-1;i<j;++i,--j)
 if(a[i]>
    a[j]){
    int t=a[i];
    a[i]=a[j];
    a[j]=t;
 }
 for(i=0;i<n;++i)
 printf("%d ",a[i]);
 return 0;
}