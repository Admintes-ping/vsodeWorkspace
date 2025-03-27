#include <stdio.h>
#include <string.h>
void main(){
    char str[]="Srting";
    printf("%d\n",strlen(strcpy(str,"China")));
    int a=2;
    int b=3;
    int *p=&a;
    printf("%d\n",*p);
    printf("%d\n",b*=a+1);
}