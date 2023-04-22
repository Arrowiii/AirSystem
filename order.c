#include "order.h"

order *head = NULL;
int ORDERNUM;
int planenum1;
plane planelistnow[20];

void DownloadOrderlist() {
    head = NULL;
    ORDERNUM = 0;
    FILE *fp = fopen("orderlist.txt", "r");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while (!feof(fp)) {
        order *neworder = (order *)malloc(sizeof(order));
        fscanf(fp, "%s %s %s", neworder->name, neworder->number, neworder->orderid);
        neworder->next = head;
        head = neworder;
        ORDERNUM ++;//订单编号+1
    }
    fclose(fp);
}

void UploadOrderlist() {
    FILE *fp = fopen("orderlist.txt", "w");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    order *arrow = head;
    while (arrow != NULL) {
        fprintf(fp, "%s %s %s\n", arrow->name, arrow->number, arrow->orderid);
        arrow = arrow->next;
    }
    fclose(fp);
}
void ShowOrderlist() {
    DownloadOrderlist();
    order *arrow = head;
    while (arrow != NULL) {
        printf("用户名: %s, 飞机编号: %s, 订单编号: %s\n", arrow->name, arrow->number, arrow->orderid);
        arrow = arrow->next;
    }
}

void BookOneTicket() {
    DownloadOrderlist();
    DownloadPlanelistInOrder();
    char username[20];
    char flightnumber[20];
    char orderid[6];
    int i;
    srand(time(0));
    for (i = 0; i < 5; i++) {
        int random = rand() % 36;
        if (random < 10) {
            orderid[i] = '0' + random;
        } else {
            orderid[i] = 'A' + random - 10;
        }
    }//随机5位订单编号
    printf("请输入你的姓名\n");
    scanf("%s",username);
    printf("请输入你要预定的飞机编号\n");
    scanf("%s",flightnumber);


    int exist = 0;
    for(i = 0; i < 20; i++){
        if(strcmp(planelistnow[i].number, flightnumber) ==0){
            if(planelistnow[i].peopleall - planelistnow[i].peoplenow > 0){//防止人数溢出
                exist = 1;
            }
        }
    }
    if(exist){
        order* neworder = (order*)malloc(sizeof(order));
        strcpy(neworder->name, username);
        strcpy(neworder->number, flightnumber);// 生成订单编号
        strcpy(neworder->orderid, orderid);// 将新订单添加到订单列表中
        neworder->next = head;
        head = neworder;// 更新订单列表文件
        UploadOrderlist();
        printf("已成功预定！\n");
    }
    else {
        printf("错误，该航线不存在或人数已满\n");
    }

}
void DeleteOneTicket(){//删除某张机票
    DownloadOrderlist();
    char name[20];
    char orderid[20];
    printf("请输入预定时的用户名：\n");
    scanf("%s", name);
    printf("请输入您的订单编号：\n");
    scanf("%s", orderid);
    order *temp = head;
    order *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0 && strcmp(temp->orderid, orderid) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("未找到匹配的订单！\n");
    } else {
        printf("删除成功！\n");
    }
    UploadOrderlist();
    printf("OK\n");
}

void DownloadPlanelistInOrder(){

    FILE *fp;
    fp = fopen("planelist.txt", "r");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    };
    int i = 0;
    planenum1 = 0;
    while(fscanf(fp,"%s %s %s %s %s %d %d %f\n",
                 planelistnow[i].number,
                 planelistnow[i].start,
                 planelistnow[i].end,
                 planelistnow[i].starttime,
                 planelistnow[i].endtime,
                 &planelistnow[i].peopleall,
                 &planelistnow[i].peoplenow,
                 &planelistnow[i].price) != EOF && i < 10){
        i++;
        planenum1++;
    }
    fclose(fp);
}

void QueryByOrderid(){
    DownloadOrderlist();
    char orderid[20];
    printf("请输入您的订单编号：\n");
    scanf("%s", orderid);
    order *arrow = head;
    int exist = 0;
    while(arrow != NULL){
        if(strcmp(arrow->orderid, orderid) == 0){
            exist = 1;
//
            break;
        }
        arrow = arrow->next;
    }
    if(exist){
        printf("查询到订单信息如下：\n用户名：%s\n航班编号：%s\n订单号；%s\n",
               arrow->name,arrow->number,arrow->orderid);
    }
    else {
        printf("没有找到订单信息!\n");
    }
    free(arrow);
}

void QueryByName() {
    DownloadOrderlist();
    char name[20];
    printf("请输入您的订单用名：\n");
    scanf("%s", name);
    order *arrow = head;
    int exist = 0;
    while(arrow != NULL){
        if(strcmp(name, arrow->name) == 0){
            exist = 1;
        }
        if(exist == 1 ){
            printf("查询到订单信息如下：用户名：%s 航班编号：%s 订单号；%s\n",
                   arrow->name,arrow->number,arrow->orderid);
            exist++;
        }

        arrow = arrow->next;
    }
    if(!exist){
        printf("没有找到订单信息!\n");
    }

    free(arrow);
}
void CountNumber(){
    DownloadOrderlist();
    char name[20];
    printf("请输入您的订单用名：\n");
    scanf("%s", name);
    order *arrow = head;
    int number = 0;
    int exist = 0;
    while(arrow != NULL){
        if(strcmp(name, arrow->name) == 0){
            exist = 1;
        }
        if(exist == 1 ){
            printf("查询到订单信息如下：用户名：%s 航班编号：%s 订单号；%s\n",
                   arrow->name,arrow->number,arrow->orderid);
            exist++;
            number++;
        }

        arrow = arrow->next;
    }
    if(!exist){
        printf("没有找到订单信息!\n");
    }
    if(number){
        printf("该用户共乘坐了%d次航班，真厉害！\n",number);
    }
    if(!number){
        printf("用户没有乘坐过航班，呜呜呜\n");
    }
}//统计乘坐次数