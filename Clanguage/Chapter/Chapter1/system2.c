#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENT_NUM 100
struct Student
{
    char ID[100];
    char name[50];
    char yvwen[50];
    char shuxue[50];
    char cyvyan[50];
    int total;
};

void input(struct Student *stu){
    
    printf("please input student number:");
    scanf(" %s",&stu->ID);
    getchar(); // 读取并丢弃换行符
    printf("please input student name:");
    fgets(stu->name, sizeof(stu->name), stdin);
    stu->name[strcspn(stu->name, "\n")] = 0; // 去除末尾的换行符
    printf("please input student yvwen:");
    scanf(" %s",stu->yvwen);
    printf("please input student shuxue:");
    scanf(" %s",stu->shuxue);
    printf("please input student cyvyan:");
    scanf(" %s",stu->cyvyan);
    stu->total = atoi(stu->yvwen) + atoi(stu->shuxue) + atoi(stu->cyvyan);
    printf("success!\n");
}
void display(struct Student stu) {
    printf("ID: %s\t", stu.ID); 
    printf("Name: %s\t", stu.name);
    printf("Yuwen: %s\t", stu.yvwen);
    printf("Shuxue: %s\t", stu.shuxue);
    printf("Cyvyan: %s\t", stu.cyvyan);
    printf("Total score: %d\n", stu.total);
}

void wait_enter(){
    printf("enter any key came back to main menu:");
    getchar(); // 读取并丢弃换行符
    getchar(); // 等待输入任意键
    printf("---------------------------------------\n");
    printf("please choose function(1-7):");
}

int main(){
    printf("----------student score system----------\n");
    printf("1.input student score\n");
    printf("2.find student score\n");
    printf("3.delete student score\n");
    printf("4.revise student score\n");
    printf("5.insert student score\n");
    printf("6.display student score\n");
    printf("7.exit system\n");
    printf("---------------------------------------\n");
    printf("please choose function(1-7):");
    int choice;
    struct Student students[MAX_STUDENT_NUM]; // 定义学生数组
    int count = 0; // 当前学生数量
    char id[100];
    while (1)
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        char c;
        if(count>=MAX_STUDENT_NUM){
                printf("student number is full\n");
                break;
            }
        do{
            input(&students[count]);
            count++;
            printf("is continue?(y/n):");
            scanf(" %c",&c);
            getchar(); // 读取并丢弃换行符 
        }while(c=='y'||c=='Y');
        printf("\nTotal number of students recorded: %d\n", count);
        printf("Student information:\n");
        for(int i = 0; i < count; i++){
            display(students[i]);
        }
        wait_enter();
            break;   
        case 2:
            printf("enter student ID:");
            scanf(" %s",id);
            getchar(); // 读取并丢弃换行符
            for(int i = 0; i < count; i++){
                if(strcmp(students[i].ID,id)==0){
                    display(students[i]);
                }
            }
            wait_enter();
            break;
        case 3:
            printf("There are a total of %d students!\n", count);
            printf("------------------student information------------------\n");
            for(int i = 0; i < count; i++){
                display(students[i]);
            }
            printf("please enter the ID of student :");
            scanf(" %s",id);
            for(int i = 0; i < count; i++){
                if(strcmp(students[i].ID,id)==0){
                    printf("find student success,is delete?(y/n):");
                    scanf(" %c",&c);
                    getchar(); // 读取并丢弃换行符 
                    if(c=='y'||c=='Y'){
                        for(int j = i; j < count-1; j++){
                            students[j] = students[j+1];
                        }
                        count--;
                        printf("delete student success!\n");
                    }else{
                        printf("delete student failed!\n");
                    }
                }
            }
            wait_enter();
            break;
        case 4:
            printf("There are a total of %d students!\n", count);
            for(int x = 0; x < count; x++){
                display(students[x]);
            }
            printf("please choose the ID of the student to be revised:");
            scanf(" %s",id);
            for(int i = 0; i < count; i++){
                if(strcmp(students[i].ID,id)==0){
                    printf("find student success,please revise the student information:\n");
                    printf("ID: %s\n",students[i].ID);
                    printf("Name: %s\n",students[i].name);
                    printf("Yuwen:");
                    scanf(" %s",students[i].yvwen);
                    printf("Shuxue:");
                    scanf(" %s",students[i].shuxue);
                    printf("Cyvyan:");
                    scanf(" %s",students[i].cyvyan);
                }
                display(students[i]);
            }
            wait_enter();
            break;
        case 5:
            printf("There are a total of %d students!\n", count);
            for(int x = 0; x < count; x++){
                display(students[x]);
            }
            int position;
            printf("Please enter the position where you want to insert:");
            scanf(" %d",&position);
            position--;
            if(position<0||position>count){
                printf("Invalid position! Please enter a number between 0 and %d.\n", count);
            }else if(count>=MAX_STUDENT_NUM){
                printf("student number is full\n");
            }else{
                for(int i = count; i>position; i--){
                    students[i] = students[i-1];
                }
                input(&students[position]);
                count++;
                printf("Student inserted successfully at position %d!\n", position+1);
            }
            for(int x = 0; x < count; x++){
                display(students[x]);
            }
            wait_enter();
            break;
        case 6:
            printf("There are a total of %d students!\n", count);
            for(int x = 0; x < count; x++){
                display(students[x]);
            }
            wait_enter();
            break;
        case 7:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}