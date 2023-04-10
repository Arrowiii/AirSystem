#include <stdio.h>

#include "touristinfo.h"
#include "menu.h"
#include "plane.h"
#include "user.h"

int main() {

    printf("Hello, World你好好你好!\n");
//    user *user1 = (user*)malloc(sizeof(user1));
//    scanf("%s",user1->name);
//    ShowMenu1();
    DownloadUserlist();
    UserRegistration();
    ShowUserlist();
    return 0;
}
