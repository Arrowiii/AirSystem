//
// Created by 18012 on 2023/4/8.
//

#ifndef AIRSYSTEM_PLANE_H
#define AIRSYSTEM_PLANE_H

#include "touristinfo.h"
#include <string.h>
void ShowPlanelist();//展示当前航线列表
void DownloadPlanelist();//下载航线列表
void UploadPlanelist();//上传航线列表
void ChangePlaneStarttime();//改变飞机出发时间
void ChangePlaneEndtime();//改变飞机到达时间
void ChangePlanePrice();//改变飞机价格
void QueryBySeatAvailble();//按空余座位查询
void QueryByStart();//按出发地查询
void QueryByEnd();//按到达地查询
//void SortByStart();//按出发时间排序
void SortByPrice();//按价格排序
void Quicksort(plane arr[], int, int);//快排
int partition(plane arr[], int, int);//快排用，选择轴元素
void swap(plane *, plane *);//交换
//
#endif //AIRSYSTEM_PLANE_H
