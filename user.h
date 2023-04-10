//
// Created by 18012 on 2023/4/8.
//

#ifndef AIRSYSTEM_USER_H
#define AIRSYSTEM_USER_H
#include "touristinfo.h"
#include <string.h>

void UserLogin();//用户登录
void UserRegistration();//用户注册
void PasswordRetrieve();//找回密码
void AdministratorLogin();//管理员登录
void AddToUserlist();//加入用户表
void RefreshUserlist();//刷新用户表
void ShowUserlist();//展示用户表
user* GetUserInfo(user* );//返回一个user结构的结构体用于写入文件
#endif //AIRSYSTEM_USER_H