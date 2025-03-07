#include <stdio.h>

int main()
{
    int cs;
     while ((cs = getchar()) != '\n')//当输入的字符不是回车时循环，cs=2473
    {
        switch (cs - '2')//将输入的字符减2后进行判断
        {
        case 0://第一个字符 '2' 与字符 '2' 的偏移量为 0，cs+4=6
        case 1:
            putchar(cs + 4);
        case 2://第二个字符 '4' 与字符 '2' 的偏移量为 2，
            putchar(cs + 4);//输出字符 '8'。
            break;
        case 3:
            putchar(cs + 2);
        default:
            putchar(cs + 2);
        }
    } 

}