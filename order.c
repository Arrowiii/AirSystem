#include "order.h"

order *head = NULL;

void DownloadOrderlist() {
    FILE *fp = fopen("orderlist.txt", "r");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    while (!feof(fp)) {
        order *new_order = (order *)malloc(sizeof(order));
        fscanf(fp, "%s %s %s", new_order->name, new_order->number, new_order->orderid);
        new_order->next = head;
        head = new_order;
    }
    fclose(fp);
}

void SaveOrderlist() {
    FILE *fp = fopen("orderlist.txt", "w");
    if (fp == NULL) {
        printf("打开文件失败\n");
        return;
    }
    order *current = head;
    while (current != NULL) {
        fprintf(fp, "%s %s %s\n", current->name, current->number, current->orderid);
        current = current->next;
    }
    fclose(fp);
}