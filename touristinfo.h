//
// Created by 18012 on 2023/4/1.
//
#ifndef AIRSYSTEM_TOURISTINFO_H
#define AIRSYSTEM_TOURISTINFO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct user{
    char name[20];//用户名
    char idnumber[20];//身份证号
    char phonenumber[20];//手机号
    char password[20];//用户密码
    char question[20];//密保验证问题
    char answer[20];//密保答案
    int notAd;//判定是否为管理
}user;//用户

typedef struct plane{
    char number[20];//飞机编号
    char start[20];//飞机出发地
    char end[20];//飞机到达地
    char starttime[20];//飞机出发时间
    char endtime[20];//飞机到达时间
    int peopleall;//飞机载客总人数
    int peoplenow;//当前载客人数
    float price;//单程价格
}plane;//飞机

typedef struct order{
    char name[20];//预定用户名
    char number[20];//预定飞机编号
    char orderid[20];//订单编号
    struct order *next;//
}order;
#endif //AIRSYSTEM_TOURISTINFO_H
