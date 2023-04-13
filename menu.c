//
// Created by 18012 on 2023/4/1.
//
#include <stdlib.h>
#include "menu.h"
#include "user.h"

void ShowMenu1() {//main menu

    printf("\n\n==+==欢迎来到航班预定系统==+==\n");
    printf("==+==本程序由Arrowiii编写完成==+==\n");
    while(1)
    {
        printf("欢迎来到航班预定管理系统\n");
        printf("1.用户注册/登录\n2.管理员登录\n3.查看帮助\n4.退出程序\n");
        printf("请选择你要执行的操作\n");
        int choice = GetChoice();

        switch(choice)
        {
            case 1:
                ShowMenu2();
                break;
            case 2:
                ShowMenu3();
                break;
            case 3:
                break;
            case 4:
                return;
            default:
                printf("错误，请在给定的序号中选择\n");
        }
    }
}
void ShowMenu2(){//user login menu

    printf("\n\n欢迎来到用户注册与登录界面\n");
    printf("请选择你要执行的操作\n");
    printf("1.账号登录\n2.账号注册\n3.找回密码\n4.返回上页\n");
    int choice = GetChoice();
    switch(choice)
    {
        case 1:
            if(UserLogin()){
                ShowMenu4();
            }
            break;
        case 2:
            UserRegistration();
            break;
        case 3:
            PasswordRetrieve();
            break;
        case 4:
            return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
}

void ShowMenu3(){//administrator login menu

    printf("\n\n欢迎来到管理员界面\n");
    printf("请选择你要执行的操作\n");
    printf("1.账号登录\n2.返回上页\n");
    int choice = GetChoice();
    switch(choice)
    {
        case 1:
            if(AdministratorLogin()){
                ShowMenu5();
            }
            break;
        case 2:
            return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
}




void ShowMenu4(){ //user menu
    printf("\n\n欢迎来到用户功能界面\n");
    printf("请选择你要执行的操作\n");
    printf("1.预定航班\n2.查询航班\n3.用户统计\n4.返回上页\n");
    int choice = GetChoice();
    switch(choice)
    {
        case 1:;break;
        case 2:;break;
        case 3:;break;
        case 4:;return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
}



void ShowMenu5(){//administrator menu
    printf("\n\n欢迎来到管理员功能界面\n");
    printf("请选择你要执行的操作\n");
    printf("1.查看预定情况\n2.修改用户手机号\n3.初始化用户密码\n4.修改航班信息\n5.返回上页\n");
    int choice = GetChoice();
    switch(choice)
    {
        case 1:;break;
        case 2:
            ChangeUserPhonenumber();
            break;
        case 3:
            InitializeUserPassword();
            break;
        case 4:break;
        case 5:;return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
};

int GetChoice(){
    char input[20];
    scanf("%s",input);
    char *end;
    int result = (int)strtol(input, &end, 10);
    if (end == input || *end != '\0') {
        result = 0;
    }
    return result;
}

