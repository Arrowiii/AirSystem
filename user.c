#include "user.h"

user userlist[20];
user *GetUserInfo(user* usernow){
    printf("请输入姓名");
    int exist = 0;
    int numbernow;
    scanf("%s",usernow->name);
    for(int i = 0; i < 20; i++) {
        if (usernow->name == userlist[i].name) {
            exist = 1;
            break;
        }
    }
    if(!exist){
        strcpy(userlist[1].name,usernow->name);
        printf("请输入账号");scanf("%s",usernow->idnumber);
        printf("请输入电话号码");scanf("%s",usernow->phonenumber);
        printf("请输入密码");scanf("%s",usernow->password);
        printf("请输入密保问题");scanf("%s",usernow->question);
        printf("请输入密保答案");scanf("%s",usernow->answer);
    }
    else printf("Error !name already existed");
    return usernow;
}//输入一个用户信息，存入usernow中并返回

void AddToUserlist(){
    FILE *fp;
    char *name;
    user *userAlice = (user*)malloc(sizeof(userAlice)) ;
    userAlice = GetUserInfo(userAlice);

    int exist = 0;
    fp = fopen("userlist.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    }

//    printf("请输入姓名");scanf("%s",name);
//    for(int i = 0; i < 20; i++){
//        if(userlist[i].name == userAlice->name){
//            printf("Error !name already existed");
//            exist = 1;
//        }
//    }
    if(!exist){//如果姓名不存在
        fprintf(fp,"%s %s %s %s %s %s %d\n",
                userAlice->name,userAlice->idnumber,userAlice->phonenumber,
                userAlice->password,userAlice->question,userAlice->answer,userAlice->notAd);
//        strcpy(userlist[1].name,name);
//        printf("请输入账号");scanf("%s",userlist[1].idnumber);
//        printf("请输入电话号码");scanf("%s",userlist[1].phonenumber);
//        printf("请输入密码");scanf("%s",userlist[1].password);
//        printf("请输入密保问题");scanf("%s",userlist[1].question);
//        printf("请输入密保答案");scanf("%s",userlist[1].answer);


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
    fclose(fp);
}
void ShowUserlist(){
    FILE *fp;
    fp = fopen("userlist.txt", "a+");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    };
    for(int i = 0; i < 20; i++){
        if(userlist[i].name == "")  break;
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