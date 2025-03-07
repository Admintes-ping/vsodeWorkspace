#include <stdio.h>
#include <string.h>

int main()
{
   /*  char str[3][50]; // 用于存储三个字符串，每个字符串最多50个字符
    int i, j;
    char temp[50];

    // 输入三个字符串
    for(i = 0; i < 3; i++)
    {
        printf("Enter string %d: ", i + 1);
        scanf("%s", str[i]);
    }

    // 对字符串按字母顺序进行排序
    for(i = 0; i < 2; i++)
    {
        for(j = i + 1; j < 3; j++)
        {
            if(strcmp(str[i], str[j]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }
    }

    // 输出排序后的字符串
    printf("Strings in alphabetical order:\n");
    for(i = 0; i < 3; i++)
    {
        printf("%s\n", str[i]);
    } */

   
    char str[100]; // 用于存储输入的字符串，假设最多100个字符
    int i, j, length;
    char temp;

    // 输入一串字符
    printf("Enter a string: ");
    scanf("%s", str);

    // 计算字符串的长度
    length = strlen(str);

    // 对字符数组按字母顺序进行排序
    for(i = 0; i < length - 1; i++)
    {
        for(j = i + 1; j < length; j++)
        {
            if(str[i] > str[j])
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    // 输出排序后的字符数组
    printf("Characters in alphabetical order: ");
    for(i = 0; i < length; i++)
    {
        printf("%c ", str[i]);
    }

    return 0;
}
