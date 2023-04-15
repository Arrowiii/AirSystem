#include "order.h"

order *head = NULL;

void DownloadOrderlist() {
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
    order *arrow = head;
    while (arrow != NULL) {
        printf("用户名: %s, 飞机编号: %s, 订单编号: %s\n", arrow->name, arrow->number, arrow->orderid);
        arrow = arrow->next;
    }
}
void BookOneTicket(){

}