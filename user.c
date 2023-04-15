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
        printf("%d::%s %s %s %s %s %s\n",
               i,
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
    printf("请输入您要注册的用户名:\n");
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
int UserLogin(){
    int OK = 0;
    DownloadUserlist();
    char inputName[20], inputPassword[20];
    printf("请输入您的用户名：");
    scanf("%s", inputName);

    int i;
    for (i = 0; i < usernum; i++) {
        if (strcmp(userlist[i].name, inputName) == 0) {
            printf("欢迎回来，%s！\n", inputName);

            printf("请输入您的密码：");
            scanf("%s", inputPassword);

            if (strcmp(userlist[i].password, inputPassword) == 0) {
                printf("登录成功！\n");
                OK = 1;
            } else {
                printf("密码错误！\n");
            }

            break;
        }
    }

    if (i == usernum) {
        printf("该用户不存在！\n");
    }
    return OK;
}

void PasswordRetrieve() {
    DownloadUserlist();
    char inputName[20], inputID[20], newPassword1[20], newPassword2[20];
    printf("请输入您的姓名：");
    scanf("%s", inputName);
    int i;
    for (i = 0; i < usernum; i++) {
        if (strcmp(userlist[i].name, inputName) == 0) {
            printf("欢迎回来，%s！\n", inputName);
            printf("请输入你的身份证号");
            scanf("%s",inputID);
            if(strcmp(userlist[i].idnumber, inputID) == 0) {
                printf("身份证号正确,请输入要更改的密码\n");
                scanf("%s", newPassword1);
                printf("请再次输入一遍\n");
                scanf("%s", newPassword2);
                if (strcmp(newPassword1, newPassword2) == 0) {
                    strcpy(userlist[i].password, newPassword1);
                    printf("密码已修改!");
                } else {
                    printf("错误!请输入相同密码\n");
                    PasswordRetrieve();
                }
                break;
            }
            else{
                printf("身份证号错误，不予修改\n");
                break;
            }
        }
        else{
            printf("查无此人哦!");
            break;
        }
    }
    UploadUserlist();
    return;
}
int AdministratorLogin(){
    int OK = 0;
    DownloadUserlist();
    char inputName[20], inputPassword[20];
    printf("请输入您的用户名：");
    scanf("%s", inputName);

    int i;
    for (i = 0; i < usernum; i++) {
        if (strcmp(userlist[i].name, inputName) == 0 && userlist->notAd == 0) {
            printf("欢迎回来，%s！\n", inputName);

            printf("请输入您的密码：");
            scanf("%s", inputPassword);

            if (strcmp(userlist[i].password, inputPassword) == 0) {
                printf("登录成功！\n");
                OK = 1;
            } else {
                printf("密码错误！\n");
            }

            break;
        }
        else {
            printf("错误！您不是管理或您不是人\n");
            break;
        }
    }

    if (i == usernum) {
        printf("该用户不存在！\n");
    }
    return OK;
}
void ChangeUserPhonenumber(){
    int num;
    char newphonenumber[20];
    DownloadUserlist();
    printf("用户信息如下\n");
    ShowUserlist();
    printf("请输入你想修改的用户编号\n");
    scanf("%d",&num);
    printf("当前用户手机号为%s，请输入修改后的手机号\n",userlist[num].phonenumber);
    scanf("%s",newphonenumber);
    strcpy(userlist[num].phonenumber, newphonenumber);
    printf("修改后%s用户的手机号为::%s",userlist[num].name,userlist[num].phonenumber);
    UploadUserlist();
}
void InitializeUserPassword(){
    int num;
    char* originpassword = "000000";
    DownloadUserlist();
    printf("用户信息如下\n");
    ShowUserlist();
    printf("请输入你想应用初始化的用户编号\n");
    scanf("%d",&num);
    strcpy(userlist[num].password, originpassword);
    printf("用户%s的密码已经成功初始化!\n",userlist[num].name);
    UploadUserlist();
}