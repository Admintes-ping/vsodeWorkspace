#include <stdio.h>

int main()
{
    char s[]="6789";
    s[1]='\0';//设置字符串s的第二个字符为空字符'\0'
    printf("%s\n",s);//遇到空字符'\0'时，停止输出字符串
}