#include <stdio.h>
#include <string.h>
//统计数字1、2、3在输入的长整数中出现的次数
int main()
{
    int c1=0,c2=0,c3=0;
    char number[1000];//必须指定大小，否则会出现缓冲区溢出
    printf("Input a long integer:");
    scanf("%s",&number);
    //strlen字符串处理函数，计算字符串的长度
    for(int i=0;i<strlen(number);i++)//i小于字符串的长度时进行循环
    {
        if(number[i]=='1')
            c1++;
        else if(number[i]=='2')
            c2++;
        else if(number[i]=='3')
            c3++;
    }
    printf("Occurrences of 1: %d\n",c1);
    printf("Occurrences of 2: %d\n",c2);
    printf("Occurrences of 3: %d\n",c3);
    return 0;
}