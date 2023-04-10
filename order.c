//WARNING : this code is non-suitable
void add_order(void);
#ifndef ORDER_H
#define ORDER_H

#include "touristinfo.h"

typedef struct order {
    char order_no[20];      // 订单编号
    flight_t flight;        // 航班信息
    passenger_t passenger;  // 旅客信息
    char order_time[30];    // 购票时间
    int seat_no;            // 座位号
    float price;            // 票价
} order_t;

// 从文件中读取订单信息
void read_orders_from_file(void);

// 将订单信息写入文件
void write_orders_to_file(void);

// 添加订单
void add_order(void);

// 删除订单
void delete_order(void);

// 查询订单
void search_order(void);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "order.h"
#include "utils.h"

#define MAX_ORDERS 10000  // 订单最大数量

static order_t orders[MAX_ORDERS];  // 订单数组
static int num_orders = 0;           // 当前订单数量

// 从文件中读取订单信息
void read_orders_from_file(void) {
    FILE* fp = fopen("orders.dat", "rb");
    if (fp == NULL) {
        return;
    }

    while (fread(&orders[num_orders], sizeof(order_t), 1, fp) == 1) {
        num_orders++;
    }

    fclose(fp);
}

// 将订单信息写入文件
void write_orders_to_file(void) {
    FILE* fp = fopen("orders.dat", "wb");
    if (fp == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    fwrite(orders, sizeof(order_t), num_orders, fp);
    fclose(fp);
}

// 生成订单编号
static void generate_order_no(char* order_no) {
    static int num = 0;
    time_t now = time(NULL);
    struct tm* tm_now = localtime(&now);
    sprintf(order_no, "%04d%02d%02d%02d%02d%02d%04d", tm_now->tm_year + 190

    flight_t* flight = find_flight_by_no(flight_no);
if (flight == NULL) {
    printf("Flight not found!\n");
    return;
}

if (flight->num_seats < num_seats) {
    printf("Not enough seats available!\n");
    return;
}

char id[20];
printf("Please enter your ID number: ");
scanf("%s", id);
passenger_t* passenger = find_passenger_by_id(id);
if (passenger == NULL) {
    printf("Passenger not found!\n");
    return;
}

// 生成订单编号
char order_no[20];
generate_order_no(order_no);

// 获取当前时间
char order_time[30];
get_current_time(order_time);

// 计算票价
float price = num_seats * flight->price;

// 保存订单信息
order_t order = {
    .flight = *flight,
    .passenger = *passenger,
    .seat_no = flight->num_seats - num_seats + 1,
    .price = price,
};
strcpy(order.order_no, order_no);
strcpy(order.order_time, order_time);
orders[num_orders++] = order;

// 更新航班信息
flight->num_seats -= num_seats;

printf("Reservation successful! Your order number is %s\n", order_no);

int found = 0;
for (int i = 0; i < num_orders; i++) {
    if (strcmp(orders[i].order_no, order_no) == 0) {
        orders[i].flight.num_seats += 1;
        found = 1;
        for (int j = i; j < num_orders - 1; j++) {
            orders[j] = orders[j+1];
        }
        num_orders--;
        printf("Order deleted!\n");
        break;
    }
}

if (!found) {
    printf("Order not found!\n");
}

int found = 0;
for (int i = 0; i < num_orders; i++) {
    if (strcmp(orders[i].order_no, order_no) == 0) {
        printf("Order number: %s\n", orders[i].order_no);
        printf("Flight number: %s\n", orders[i].flight.flight_no);
        printf("Passenger name: %s\n", orders[i].passenger.name);
        printf("Passenger ID: %s\n", orders[i].passenger.id);
        printf("Order time: %s\n", orders[i].order_time);
        printf("Seat number: %d\n", orders[i].seat_no);
        printf("Price: %.2f\n", orders[i].price);
        found = 1;
        break;
    }
}

if (!found) {
    printf("Order not found!\n");
}



