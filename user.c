//
// Created by 18012 on 2023/4/8.
//

#include "user.h"
user userlist[20];
void AddToUserlist(char *name,user* Userlist){
    ;
}
void RefreshUserlist(){
    ;
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