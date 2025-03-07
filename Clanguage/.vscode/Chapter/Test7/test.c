#include <stdio.h>
void printRect(int row,int col,char ch){
    int i,j;
    for(i=0;i<=row;i++){
        for(j=0;j<col;j++){
            printf("%c",ch);  
        }
        printf("\n");
    }
}
int main()
{
int r,c;
char ch;
scanf("%d%d%c",&r,&c);
printf("Enter the character for the rectangle: ");
getchar();// 清除缓冲区中的换行符
scanf("%c",&ch);
printRect(r,c,ch);
return 0;
}