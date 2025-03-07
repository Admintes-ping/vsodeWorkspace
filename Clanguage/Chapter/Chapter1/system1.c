
#include <stdio.h>
#include <string.h>
#define MAX_DEVICES 10
#define MAX_DEVICE_TYPE_LENGTH 20

void All_device_information(char device_num[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],
                            char device_type[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],
                            char device_name[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],
                            char device_price[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],
                            char purchase_date[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],
                            char is_scrapped[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],
                            char scrap_date[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],int current_device_num){
    printf("----------------------all the Equipment information----------------------\n");
     
    for(int i=0;i<current_device_num;i++){
        printf("Equipment number\t");
        printf("Device type\t");
        printf("Device name\t");
        printf("Device price\t");
        printf("purchase date\t");
        printf("Is it scrapped\t");
        printf("Scrap date\n");
            printf("\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\n", 
               device_num[i], 
               device_type[i], 
               device_name[i], 
               device_price[i], 
               purchase_date[i], 
               is_scrapped[i], 
               scrap_date[i]);
        }
}
int counScrappedDevices(char is_scrapped[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],int current_device_num){
int scrapped_count=0;
for(int i=0;i<current_device_num;i++){
    if(strcmp(is_scrapped[i],"Yes")==0){
        scrapped_count++;
        }
    }  
    return scrapped_count;
}
int Total_number_of_devices(char device_type[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH],int current_device_num){
    int total_num=0;
    int total_num2=0;
    int total_num3=0;
    for(int i=0;i<current_device_num;i++){
        if(strcmp(device_type[i],"A")==0){
            total_num++;  
        }
        if(strcmp(device_type[i],"B")==0){
            total_num2++;
        }
        if(strcmp(device_type[i],"C")==0){
            total_num3++;
        }
    }
    printf("A: %d\n",total_num);
    printf("B: %d\n",total_num2);
    printf("C: %d\n",total_num3);
    return total_num;
}
int main(){
    printf("Laboratory Equipment Management System\n");
    printf("****************************************\n");
    printf("1.show all devices\n");
    printf("2.Equipment intformation entry\n");
    printf("3.Modification of equipment information\n");
    printf("4.Classification statistics of equipment infofrmation\n");
    printf("5.delete a device\n");
    printf("6.Find a device\n");
    printf("7.exit\n");
    printf("****************************************\n");
    printf("please enter your choice(1-7):");
    int choice;
    int current_device_num=4;
    char device_num[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"1","2","3", "4", "", "", "", "", "", ""};
    char device_type[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"A","B","C", "A", "", "", "", "", "", ""};
    char device_name[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"Device 1","Device 2","Device 3", "Device2", "", "", "", "", "", ""};
    char device_price[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"1000","2000","3000", "2345", "", "", "", "", "", ""};
    char purchase_date[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"2021-01-01","2021-02-01","2021-03-01", "2024-03-01", "", "", "", "", "", ""};
    char is_scrapped[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"No","No","No", "Yes", "", "", "", "", "", ""};
    char scrap_date[MAX_DEVICES][MAX_DEVICE_TYPE_LENGTH]={"-","-","2021-01-01", "-", "", "", "", "", "", ""};
    scanf("%d",&choice);
    char YN;
    int num;
    char is_modify;
    while (1)
    {
        printf("please enter your choice(1-7):");
        int choice;
        scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        All_device_information(device_num,device_type,device_name,
                             device_price,purchase_date,is_scrapped,
                             scrap_date,current_device_num);    
        break;
    case 2:
        printf("Equipment information entry:\n");
        printf("Equipment number (1-10): ");
        scanf("%d", device_num[current_device_num]);
        while (current_device_num < 1 || current_device_num > MAX_DEVICES || current_device_num >= MAX_DEVICES) {
            printf("Invalid equipment number! Please enter a number between 1 and %d:\n", MAX_DEVICES);
            // 清空输入缓存
            while (getchar() != '\n'); // 读取并丢弃到下一个换行符
            printf("Equipment number (1-10): ");
            scanf("%d", &device_num);
        }
        printf("Device type: ");
        scanf("%s", device_type[current_device_num]); 
         // 存储输入的设备类型
        printf("Device name: ");
        scanf("%s", device_name[current_device_num]);
        printf("Device price: ");
        scanf("%s", device_price[current_device_num]);
        printf("Purchase date: ");
        scanf("%s", purchase_date[current_device_num]);
        printf("Is it scrapped? (Yes/No): ");
        scanf("%s", is_scrapped[current_device_num]); 
        if (strcmp(is_scrapped[current_device_num], "Yes") == 0) {
            printf("Scrap date: ");
            scanf("%s", scrap_date[current_device_num]);
        }
        current_device_num++;
        printf("\nDo you want to continue? (Y/N): ");
        scanf(" %c", &YN);
        if(YN == 'Y'){
        printf("Equipment information entry:\n");
        printf("Equipment number (1-10): ");
        scanf("%d", &device_num);
        printf("Device type: ");
        scanf("%s", device_type[current_device_num]); 
         // 存储输入的设备类型
        printf("Device name: ");
        scanf("%s", device_name[current_device_num]);
        printf("Device price: ");
        scanf("%s", device_price[current_device_num]);
        printf("Purchase date: ");
        scanf("%s", purchase_date[current_device_num]);
        printf("Is it scrapped? (Yes/No): ");
        scanf("%s", is_scrapped[current_device_num]); 
        if (strcmp(is_scrapped[current_device_num], "Yes") == 0) {
            printf("Scrap date: ");
            scanf("%s", scrap_date[current_device_num]);
        }
        current_device_num++;
        }else{
            printf("Thank you for using the system!\n");
        } 
        break;
    case 3:
        printf("Do you want to modify device information(y/n):");
        scanf(" %c", &is_modify);
        if(is_modify == 'y'){
            printf("please enter the equipment number you want to modify:");
            scanf("%d", &num);
            printf("Are you sure you want to modify the name of this device(y/n):");
            scanf(" %c", &is_modify);
            if(is_modify == 'y'){
                printf("please enter the new name of this device:");
                scanf(" %s",device_name[num-1]);
            }
            printf("Are you sure you want to modify the type of this device(y/n):");
            scanf(" %c", &is_modify);
            if(is_modify == 'y'){
                printf("please enter the new type of this device:");
                scanf(" %s",device_type[num-1]);
                getchar(); // 清除换行符
            }
            printf("Are you sure you want to modify the price of this device(y/n):");
            scanf(" %c", &is_modify);
            if(is_modify == 'y'){
                printf("please enter the new price of this device:");
                scanf(" %s",device_price[num-1]);
            }
            printf("Are you sure you want to modify the purchase date of this device(y/n):");
            scanf(" %c", &is_modify);
            if(is_modify == 'y'){
                printf("please enter the new purchase date of this device:");
                scanf(" %s",purchase_date[num-1]);
            }
            getchar(); 
        }
        if(is_modify == 'n'){
            printf("Thank you for using the system!\n");
        }
        printf("successfully modified the device information\n");
        All_device_information(device_num,device_type,device_name,
                             device_price,purchase_date,is_scrapped,
                             scrap_date,current_device_num); 
        break;
    case 4:
        printf("Enter the information you want to count");
        printf("(1 represents the total number of scrapped equipment/2 represents the total number of devices):");
        scanf("%d", &num);
        if(num == 1){
           int total_scrapped=counScrappedDevices(is_scrapped,MAX_DEVICES);
           printf("The total number of scrapped equipment is %d\n",total_scrapped);
        }
        if(num==2){
            int totalnum=Total_number_of_devices(device_type,MAX_DEVICES);
        }
        break;
    case 5:
        All_device_information(device_num,device_type,device_name,
                             device_price,purchase_date,is_scrapped,
                             scrap_date,current_device_num);
        printf("delete a number:");
        scanf("%d", &num);
          // 验证设备编号
    if (num < 1 || num > current_device_num) {
        printf("Invalid device number! Please enter a number between 1 and %d.\n", current_device_num);
    } else {
        // 删除设备信息的逻辑
        for (int i = num - 1; i < current_device_num - 1; i++) {
            // 向前移动数据
            strcpy(device_num[i], device_num[i + 1]);
            strcpy(device_type[i], device_type[i + 1]);
            strcpy(device_name[i], device_name[i + 1]);
            strcpy(device_price[i], device_price[i + 1]);
            strcpy(purchase_date[i], purchase_date[i + 1]);
            strcpy(is_scrapped[i], is_scrapped[i + 1]);
            strcpy(scrap_date[i], scrap_date[i + 1]);
        }
        current_device_num--;
        printf("Device number %d has been deleted successfully.\n", num);
           // 打印更新后的设备信息
        printf("Updated device information after deletion:\n");
        All_device_information(device_num, device_type, device_name,
                               device_price, purchase_date, is_scrapped,
                               scrap_date, current_device_num);
        break;
    case 6:
        All_device_information(device_num, device_type, device_name,
                               device_price, purchase_date, is_scrapped,
                               scrap_date, current_device_num);
        printf("Find a number:\n");
        scanf("%d", &num);
        if (num < 1 || num > current_device_num) {
            printf("Invalid device number! Please enter a number between 1 and %d.\n", current_device_num);
        } else {
            // 打印该设备的信息
        printf("Device Information:\n");
        printf("Equipment number: %s\n", device_num[num - 1]);
        printf("Device type: %s\t", device_type[num - 1]);
        printf("Device name: %s\t", device_name[num - 1]);
        printf("Device price: %s\t", device_price[num - 1]);
        printf("Purchase date: %s\t", purchase_date[num - 1]);
        printf("Is it scrapped? %s\t", is_scrapped[num - 1]);
        
        if (strcmp(is_scrapped[num - 1], "Yes") == 0) {
            printf("Scrap date: %s\n", scrap_date[num - 1]);
        }
    }
        break;
    case 7:
        printf("exit the system\n");
        return 0;
    default:
        break;
    }
}
    }  
}
