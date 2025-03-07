/* #include <stdio.h>
int negative_number(int num){
    if (num < 0) {
        return -num; // 如果输入的数小于0，返回其相反数
    } else {
        return num; // 如果输入的数大于等于0，直接返回该数
    }
}

int main()
{
    int num;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    int neg_num = negative_number(num);
    
    printf("The absolute value of the number is: %d\n",  neg_num);
    
    return 0;
} */
#include <stdio.h>
int negative_number(int num){

    if(num<0){
        num=-num;
        printf("the number is %d",num);
    }else{
        return num;
        printf("the number is %d",num);
    }
}
int main()
{
    int num;
    printf("enter a number:");
    scanf("%d",&num);
    negative_number(num);
    return 0;
}
