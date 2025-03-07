#include <stdio.h>
int main()
{
    FILE *fp;
    int i;
    char ch[] = "abcd", t;//t为存储从文件中读取的字节的变量
    fp = fopen("abc.dat", "wb +");
    for (i = 0; i < 4; i++)
    {
        fwrite(&ch[i], 1, 1, fp);
        fseek(fp, -2L, SEEK_END); // 说明：SEEK_END为⽂件尾将文件指针移动到文件末尾的前两个字节处
        fread(&t, 1, 1, fp);//读取字节而不是字符，因为fread()函数读取字节而不是字符
    };
    fclose(fp);
    printf("The last character is: %c\n", t);
}
