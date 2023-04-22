//
// Created by 18012 on 2023/4/13.
//

#include "plane.h"
plane planelist[20];
int planenum;
plane newlist[20];
void DownloadPlanelist(){

    FILE *fp;
    fp = fopen("planelist.txt", "r");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    };
    int i = 0;
    planenum = 0;
    while(fscanf(fp,"%s %s %s %s %s %d %d %f\n",
                 planelist[i].number,
                 planelist[i].start,
                 planelist[i].end,
                 planelist[i].starttime,
                 planelist[i].endtime,
                 &planelist[i].peopleall,
                 &planelist[i].peoplenow,
                 &planelist[i].price) != EOF && i < 20){
        i++;
        planenum++;
    }
    fclose(fp);
}

void ShowPlanelist(){
    DownloadPlanelist();
    printf("当前所有飞机信息如下:\n");
    for(int i = 0; i < 20; i++){
        if(strlen(planelist[i].number) == 0)  continue;
        printf("%d::编号:%s, 出发地:%s, 到达地:%s, 出发时间:%s, 到达时间:%s, 当前载客人数:%d, 载客总人数:%d, 单程价格:%.2f元/人\n",
               i,
               planelist[i].number,
               planelist[i].start,
               planelist[i].end,
               planelist[i].starttime,
               planelist[i].endtime,
               planelist[i].peoplenow,
               planelist[i].peopleall,
               planelist[i].price);
    }
}

void UploadPlanelist(){
    FILE *fp = fopen("planelist.txt", "w");//清空原有内容后写入
    if (fp == NULL) {
        printf("文件打开失败！\n");
        exit(1);// 打开文件失败，处理错误
    }

    for (int i = 0; i < planenum; i++) {
        fprintf(fp, "%s %s %s %s %s %d %d %f\n",
                planelist[i].number,
                planelist[i].start,
                planelist[i].end,
                planelist[i].starttime,
                planelist[i].endtime,
                planelist[i].peopleall,
                planelist[i].peoplenow,
                planelist[i].price);
    }
    fclose(fp);
}

void ChangePlaneStarttime(){
    int num;
    char newstarttime[20];
    DownloadPlanelist();
    printf("飞机信息如下\n");
    ShowPlanelist();
    printf("请输入你想修改的飞机编号\n");
    scanf("%d",&num);
    printf("当前飞机出发时间为%s，请输入修改后的出发时间\n",planelist[num].starttime);
    scanf("%s",newstarttime);
    strcpy(planelist[num].starttime, newstarttime);
    printf("修改后%s飞机的出发时间为::%s",planelist[num].number,planelist[num].starttime);
    UploadPlanelist();
}

void ChangePlaneEndtime(){
    int num;
    char newendtime[20];
    DownloadPlanelist();
    printf("飞机信息如下\n");
    ShowPlanelist();
    printf("请输入你想修改的飞机编号\n");
    scanf("%d",&num);
    printf("当前飞机到达时间为%s，请输入修改后的到达时间\n",planelist[num].endtime);
    scanf("%s",newendtime);
    strcpy(planelist[num].endtime, newendtime);
    printf("修改后%s飞机的到达时间为::%s",planelist[num].number,planelist[num].endtime);
    UploadPlanelist();
}

void ChangePlanePrice(){
    int num;
    float newprice;
    DownloadPlanelist();
    printf("飞机信息如下\n");
    ShowPlanelist();
    printf("请输入你想修改的飞机编号\n");
    scanf("%d",&num);
    printf("当前飞机单程价格为%.2f元，请输入修改后的单程价格\n",planelist[num].price);
    scanf("%f",&newprice);
    planelist[num].price = newprice;
    printf("修改后%s飞机的单程价格为::%.2f元",planelist[num].number,planelist[num].price);
    UploadPlanelist();
}

void QueryBySeatAvailble(){
    DownloadPlanelist();
    printf("当前含有剩余座位飞机信息如下:\n");
    for(int i = 0; i < 20; i++){
        if(strlen(planelist[i].number) == 0)
            continue;
        if(planelist[i].peopleall - planelist[i].peoplenow <= 0)
            continue;
        printf("编号:%s, 出发地:%s, 到达地:%s, 出发时间:%s, 到达时间:%s, 当前载客人数:%d, 载客总人数:%d, 单程价格:%.2f元/人\n",

               planelist[i].number,
               planelist[i].start,
               planelist[i].end,
               planelist[i].starttime,
               planelist[i].endtime,
               planelist[i].peoplenow,
               planelist[i].peopleall,
               planelist[i].price);
    }
}//按空余座位查询

void QueryByStart(){
    DownloadPlanelist();
    char start[20];
    printf("请输入您的出发地\n");
    scanf("%s",start);
    int exist = 0;
    for(int i = 0; i < 20; i++){
        if(strlen(planelist[i].number) == 0)
            continue;
        if(strcmp(start,planelist[i].start) == 0) {
            exist = 1;
            printf("编号:%s, 出发地:%s, 到达地:%s, 出发时间:%s, 到达时间:%s, 当前载客人数:%d, 载客总人数:%d, 单程价格:%.2f元/人\n",
                   planelist[i].number,
                   planelist[i].start,
                   planelist[i].end,
                   planelist[i].starttime,
                   planelist[i].endtime,
                   planelist[i].peoplenow,
                   planelist[i].peopleall,
                   planelist[i].price);
        }
    }
    if(!exist){
        printf("无该城市出发的航班!\n");
    }
}//按出发地查询
void QueryByEnd(){
    DownloadPlanelist();
    char end[20];
    printf("请输入您的目的地\n");
    scanf("%s",end);
    int exist = 0;
    for(int i = 0; i < 20; i++){
        if(strlen(planelist[i].number) == 0)
            continue;
        if(strcmp(end,planelist[i].end) == 0) {
            exist = 1;
            printf("编号:%s, 出发地:%s, 到达地:%s, 出发时间:%s, 到达时间:%s, 当前载客人数:%d, 载客总人数:%d, 单程价格:%.2f元/人\n",
                   planelist[i].number,
                   planelist[i].start,
                   planelist[i].end,
                   planelist[i].starttime,
                   planelist[i].endtime,
                   planelist[i].peoplenow,
                   planelist[i].peopleall,
                   planelist[i].price);
        }

    }
    if(!exist){
        printf("无到达该城市的航班!\n");
    }
}//按到达地查询


void swap(plane *a, plane *b) {
    plane temp = *a;
    *a = *b;
    *b = temp;
}

int partition(plane arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].price < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void Quicksort(plane arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        Quicksort(arr, low, pi - 1);
        Quicksort(arr, pi + 1, high);
    }
}

void SortByPrice(){
    DownloadPlanelist();
    for (int i = 0; i < 20; i++) {
        newlist[i] = planelist[i];
    }// 复制planelist到newlist
    // 使用快速排序对newlist进行排序
    Quicksort(newlist, 0, 19);

    printf("按价格排序后的航班信息如下:\n");
    for(int i = 0; i < 20; i++){
        if(strlen(newlist[i].number) == 0)  continue;
        printf("编号:%s, 出发地:%s, 到达地:%s, 出发时间:%s, 到达时间:%s, 当前载客人数:%d, 载客总人数:%d, 单程价格:%.2f元/人\n",
               newlist[i].number,
               newlist[i].start,
               newlist[i].end,
               newlist[i].starttime,
               newlist[i].endtime,
               newlist[i].peoplenow,
               newlist[i].peopleall,
               newlist[i].price);
    }
}//按价格排序