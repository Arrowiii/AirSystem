//
// Created by 18012 on 2023/4/8.
//

#ifndef AIRSYSTEM_USER_H
#define AIRSYSTEM_USER_H
#include "touristinfo.h"
#include <string.h>

int UserLogin();//用户登录
void UserRegistration();//用户注册
void PasswordRetrieve();//找回密码
int AdministratorLogin();//管理员登录
void AddToUserlist(char*);//加入用户表
void DownloadUserlist();//使当前数组存入txt文件中的用户名单
void ShowUserlist();//展示用户表
void GetUserInfo(char* name);//获取用户信息
void UploadUserlist();//更新txt文件使其存储最新的用户名单
void ChangeUserPhonenumber();//修改用户手机号
void InitializeUserPassword();//初始化用户密码

#endif //AIRSYSTEM_USER_H