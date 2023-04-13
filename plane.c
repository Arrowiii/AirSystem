//
// Created by 18012 on 2023/4/13.
//

#include "plane.h"
plane planelist[10];
int planenum;

void DownloadPlanelist(){

    FILE *fp;
    fp = fopen("planelist1.txt", "r");
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
                 &planelist[i].price) != EOF && i < 10){
        i++;
        planenum++;
    }
    fclose(fp);
}

void ShowPlanelist(){
    DownloadPlanelist();
    printf("当前所有飞机信息如下:\n");
    for(int i = 0; i < 10; i++){
        if(strlen(planelist[i].number) == 0)  continue;
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
