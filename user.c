//
// Created by 18012 on 2023/4/8.
//

#include "user.h"
user userlist[20];

void AddToUserlist(){
    FILE *fp;
    char *name;
    int exist = 0;
    fp = fopen("userlist.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    }

    printf("请输入姓名");scanf("%s",name);
    for(int i = 0; i < 20; i++){
        if(userlist[i].name == name){
            printf("error !name already existed");
            exist = 1;
        }
    }
    if(!exist){//如果姓名不存在
        strcpy(userlist[1].name,name);
        printf("请输入账号");scanf("%s",userlist[1].idnumber);
        printf("请输入电话号码");scanf("%s",userlist[1].phonenumber);
        printf("请输入密码");scanf("%s",userlist[1].password);
        printf("请输入密保问题");scanf("%s",userlist[1].question);
        printf("请输入密保答案");scanf("%s",userlist[1].answer);
        userlist[1].notAd = 1;

        fprintf(fp,"%s %s %s %s %s %s %d\n",
                userlist[1].name,userlist[1].idnumber,userlist[1].phonenumber,
                userlist[1].password,userlist[1].question,userlist[1].answer,userlist[1].notAd);
    }

//    for(int i = 0; i < 20 ;i++){
//
//    }
    fclose(fp);
}
void RefreshUserlist(){
    FILE *fp;
    fp = fopen("userlist.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    };
    for(int i = 0; i < 20; i++){
        fscanf(fp,"%s %s %s %s %s %s %d\n",
                userlist[i].name,userlist[i].idnumber,userlist[i].phonenumber,
                userlist[i].password,userlist[i].question,userlist[i].answer,&userlist[i].notAd);
    }
}
void ShowUserlist(){
    FILE *fp;
    fp = fopen("userlist.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    };
    for(int i = 0; i < 20; i++){
        printf("%s %s %s %s %s %s\n",
               userlist[i].name,userlist[i].idnumber,userlist[i].phonenumber,
               userlist[i].password,userlist[i].question,userlist[i].answer);
    }
}
void UserRegistration(){
    user u;
    printf("请输入姓名：");
    scanf("%s", u.name);
    printf("请输入身份证号：");
    scanf("%s", u.idnumber);
    printf("请输入手机号：");
    scanf("%s", u.phonenumber);
    printf("请输入密码：");
    scanf("%s", u.password);
    printf("请输入密保验证问题：");
    scanf("%s", u.question);
    printf("请输入密保答案：");
    scanf("%s", u.answer);

    FILE *fp;
    fp = fopen("user.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    }

    fprintf(fp, "%s %s %s %s %s %s\n", u.name, u.idnumber, u.phonenumber, u.password, u.question, u.answer);

    fclose(fp);
}
void UserLogin(){
    ;
}


void PasswordRetrieve(){
    ;
}
void AdministratorLogin(){
    ;
}