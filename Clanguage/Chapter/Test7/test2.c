#include <stdio.h>
void swap(int x, int y){
    int t;
    t=x;
    x=y;
    y=t;
    printf("After swap: x=%d, y=%d\n", x, y);
}
int main()
{
    int a=10, b=20;
   swap(a, b);
   printf("Before swap: a=%d, b=%d\n", a, b);
    return 0;
}