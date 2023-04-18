//
// Created by 18012 on 2023/4/15.
//

#ifndef AIRSYSTEM_ORDER_H
#define AIRSYSTEM_ORDER_H
#include "touristinfo.h"
#include "string.h"
#include <time.h>


void DownloadOrderlist();//更新订单信息
void UploadOrderlist();//上传订单信息
void ShowOrderlist();//打印订单信息
void BookOneTicket();//预定一个机票
void DeleteOneTicket();//删除一个机票
void DownloadPlanelistInOrder();//预定用，更新飞机名单
void QueryByOrderid();//按订单编号查询，管理用
void QueryByName();//按订单用名查询
void CountNumber();//统计乘坐次数
#endif //AIRSYSTEM_ORDER_H
