#include <stdio.h>
#include <ctype.h>//ctype.h头文件包含了一些字符处理函数，如isalpha()、isdigit()、isspace()等。
int main()
{
    char input[1000];
    int letters=0, digits=0, spaces=0, others=0;
    printf("Enter a string: ");
    //fgets()函数从标准输入流中读取字符串，并存储到input数组中,sizeof(input)是数组的大小，stdin是标准输入流。
    fgets(input, sizeof(input), stdin);
    for (int i = 0; input[i] != '\0'; i++)//空字符 \0 以表示字符串的结束。
    {
        if (isalpha(input[i])) {//isalpha()函数判断是否为字母，给定的字符是字母，则返回真；否则返回0。
            letters++;
        } else if (isdigit(input[i])) {//isdigit()函数判断是否为数字，给定的字符是数字，则返回真；否则返回0。
            digits++;
        } else if (isspace(input[i])) {//isspace()函数判断是否为空格，给定的字符是空格，则返回真；否则返回0。
            spaces++;
        } else {
            others++;
        }
    }

    printf("Statistical results:\n");
    printf("Number of English letters:%d\n", letters);
    printf("Number of digits:%d\n", digits);
    printf("Number of spaces:%d\n", spaces);
    printf("Number of other characters:%d\n", others);

    return 0;
    
}