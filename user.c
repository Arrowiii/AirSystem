#include "user.h"

user userlist[20];
int usernum;

void GetUserInfo(char* name){
    DownloadUserlist();
    user* usernow = (user*)malloc(sizeof(user));
    int exist = 0;
    for(int i = 0; i < 20; i++) {
        if (strcmp(name, userlist[i].name) == 0 ) {
            exist = 1;
            break;
        }
    }
    if(!exist){
        strcpy(userlist[usernum].name,name);
        printf("请输入账号");scanf("%s",userlist[usernum].idnumber);
        printf("请输入电话号码");scanf("%s",userlist[usernum].phonenumber);
        printf("请输入密码");scanf("%s",userlist[usernum].password);
        printf("请输入密保问题");scanf("%s",userlist[usernum].question);
        printf("请输入密保答案");scanf("%s",userlist[usernum].answer);
        userlist[usernum].notAd = 1;
        usernum++;
    }
    else {
        printf("Error !name already existed");
    }
}//输入一个用户信息，存入usernow中并返回

void AddToUserlist (char *name){

    GetUserInfo(name);
//    for(int i = 0; i < 20; i++){
//        if(strlen(userlist[i].name) == 0){
//            memcpy(&userlist[i], &userAlice, sizeof(user));
//        }
//    }
//    usernum++;
    UploadUserlist();
}
void UploadUserlist(){
    FILE *fp = fopen("userlist.txt", "w");//清空原有内容后写入
    if (fp == NULL) {
        printf("文件打开失败！\n");
        exit(1);// 打开文件失败，处理错误
    }

    for (int i = 0; i < usernum; i++) {
        fprintf(fp, "%s %s %s %s %s %s %d\n",
                userlist[i].name,
                userlist[i].idnumber,
                userlist[i].phonenumber,
                userlist[i].password,
                userlist[i].question,
                userlist[i].answer,
                userlist[i].notAd);
    }
    fclose(fp);
}

void DownloadUserlist(){

    FILE *fp;
    fp = fopen("userlist.txt", "r");
    if(fp == NULL){
        printf("文件打开失败！\n");
        exit(1);
    };
//    for (int i = 0; i < 20; i++) {
//        memset(&userlist[i], 1, sizeof(user));
//    }//下载前初始化数组
    int i = 0;
    usernum = 0;
    while(fscanf(fp,"%s %s %s %s %s %s %d\n",
                 userlist[i].name,
                 userlist[i].idnumber,
                 userlist[i].phonenumber,
                 userlist[i].password,
                 userlist[i].question,
                 userlist[i].answer,
                 &userlist[i].notAd) != EOF && i < 20){
        i++;
        usernum++;
    }
//    for(int i = 0; i < 20; i++){
//        fscanf(fp,"%s %s %s %s %s %s %d\n",
//                userlist[i].name,
//                userlist[i].idnumber,
//                userlist[i].phonenumber,
//                userlist[i].password,
//                userlist[i].question,
//                userlist[i].answer,
//                &userlist[i].notAd);
//    }
    fclose(fp);
}
void ShowUserlist(){
    DownloadUserlist();
    printf("当前所有用户信息如下:\n");
    for(int i = 0; i < 20; i++){
        if(strlen(userlist[i].name) == 0)  continue;
        printf("%s %s %s %s %s %s\n",
               userlist[i].name,
               userlist[i].idnumber,
               userlist[i].phonenumber,
               userlist[i].password,
               userlist[i].question,
               userlist[i].answer);
        if(!userlist[i].notAd)
            printf("上面的用户是管理\n");
    }
}
void UserRegistration(){
    DownloadUserlist();
    char newname[20];
    int exist = 0;
    printf("请输入您要注册的姓名:\n");
    scanf("%s",newname);
    for (int i = 0; i < 20; i++) {
        if (strcmp(newname, userlist[i].name) == 0) {
            printf("输入的姓名已存在于 %d 处\n", i);
            exist = 1;
            break;
        }
    }
    if(!exist){
        AddToUserlist(newname);
        UploadUserlist();
    }
    else return;
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