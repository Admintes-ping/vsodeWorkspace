
#include <stdio.h>

int isUpper(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

int isLower(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

void cUpper(char *ch)
{ // 小写转大写
    *ch = *ch - 'a' + 'A';
}

void cLower(char *ch)
{ // 大写转小写
    *ch = *ch - 'A' + 'a';
}

void cDigit(char *ch)
{
    *ch = 9 - (*ch - '0') + '0';
}

void convert(char *ch)
{
    if (isUpper(*ch))
    {
        cUpper(ch);
    }
    else if (isLower(*ch))
    {
        cLower(ch);
    }
    else if (isDigit(*ch))
    {
        cDigit(ch);
    }
}

int main()
{
    char str[81] = "Aidf3F4";
    printf("%s\n",str);
    convert(str);
    printf("%s\n", str);
    return 0;
}