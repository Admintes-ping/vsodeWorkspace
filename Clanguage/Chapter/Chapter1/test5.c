#include <stdio.h>
#define YEAR 2017
int is_leap_year(int year){//判断是否为闰年
    return (year%4==0&&year%100!=0) || year%400==0;
}
int days_in_month(int year,int month){//返回某年某月的天数,都是作为判断
    if(month==2){
        return is_leap_year(year)?29:28;
    }else if(month==4 || month==6 || month==9 || month==11){
        return 30;
    }else{
        return 31;
    }
}
int total_days(int year,int month,int day){//计算总天数
    int total_days=0;
    for(int y=2017;y<year;y++){
        total_days+=is_leap_year(y)?366:365;
    }
    for(int m=1;m<month;m++){
        total_days+=days_in_month(year,m);
    }
    total_days+=day-1;
    return total_days;
}
int main()
{
    int year,month,day;
    int work,rest;
    printf("Enter year, month, and day: ");
    scanf("%d %d %d",&year,&month,&day);
    while (year<YEAR)
    {
        printf("the year is error,please input again :");
        scanf("%d %d %d",&year,&month,&day);
    }
    int total=total_days(year,month,day);
    printf("Total days: %d\n",total);
    int num=total%5;
    if(num<=3){
        printf("the day is work\n");
    }else{
        printf(" the day is rest\n");
    }

}