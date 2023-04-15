//
// Created by 18012 on 2023/4/1.
//
#include <stdlib.h>
#include "menu.h"
#include "user.h"
#include "plane.h"
#include "query.h"
#include "order.h"

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
                Help();break;
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
        case 1:BookOneTicket();break;
        case 2:ShowMenu6();break;
        case 3:CountNumber();break;
        case 4:;return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
}



void ShowMenu5(){//administrator menu
    printf("\n\n欢迎来到管理员功能界面\n");
    printf("请选择你要执行的操作\n");
    printf("1.查看预定情况\n2.修改用户手机号\n3.初始化用户密码\n4.修改航班出发时间\n"
           "5.修改航班到达时间\n6.修改航班价格\n7.查看用户列表\n8.查看航班列表\n9.返回上页\n");
    int choice = GetChoice();
    switch(choice)
    {
        case 1:
            ShowOrderlist();
            break;
        case 2:
            ChangeUserPhonenumber();
            break;
        case 3:
            InitializeUserPassword();
            break;
        case 4:
            ChangePlaneStarttime();
            break;
        case 5:
            ChangePlaneEndtime();
            break;
        case 6:
            ChangePlanePrice();
            break;
        case 7:
            ShowUserlist();
            break;
        case 8:
            ShowPlanelist();
            break;
        case 9:return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
}

void ShowMenu6(){
    printf("\n\n欢迎来到查询功能界面\n");
    printf("请选择你要执行的操作\n");
    printf("1.查看所有航班\n2.按用户名查询\n3.按空余座位查询\n"
           "4.按航班日期查询\n5.按出发地查询\n6.按到达地查询\n"
           "7.按出发时间排序\n8.按价格排序\n9.按订单编号查询\n"
           "10.返回上页");
    int choice = GetChoice();
    switch(choice)
    {
        case 1:
            ShowPlanelist();
        case 2:
            QueryByName();break;
        case 3:
            QueryBySeatAvailble();break;
        case 4:
            QueryByDate();break;
        case 5:
            QueryByStart();break;
        case 6:
            QueryByEnd();break;
        case 7:
            SortByStart();break;
        case 8:
            SortByPrice();break;
        case 9:
            QueryByOrderid();break;
        case 10:return;
        default:
            printf("错误，请在给定的序号中选择\n");
    }
}
void Help(){
    printf("# 航班管理系统-by Arrowiii\n"
           "\n"
           "## 简介\n"
           "\n"
           "这是一个用于管理航班信息的系统。\n"
           "\n"
           "## 基本功能\n"
           "- 待定\n"
           "- 先占个坑\n"
           "## 开发语言\n"
           "- C\n"
           "- CMake\n"
           "\n"
           "## 开发环境\n"
           "- clion2022.3\n"
           "- wsl2(Ubuntu22.04 LTS)\n"
           "\n"
           "\n"
           "## 注意事项\n"
           "\n"
           "- 请确保输入的信息准确无误。\n"
           "- 如有问题，请联系我们。\n"
           "- 如果发现程序运行出现问题，请立即关闭程序\n"
           "- 少女祈祷中......\n\n\n");
}
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

