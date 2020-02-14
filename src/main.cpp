#include <iostream>
#include <string.h>
#include "UserManager.h"
#include "RootManager.h"
#include "MagazineManager.h"

void userLogin(UserManager *thisManager);
void userRegister(UserManager *thisManager);
void rootLogin(RootManager *thisManager);

int main()
{
  std::cout << "Hello World!\n"; 
	std::cout << "欢迎来到杂志订阅管理系统\n";
	int a = 0;
	UserManager myManager = UserManager();
	RootManager myRoot = RootManager();
	MagazineManager myMagazine = MagazineManager();
	while (true){                                      //主界面循环
		std::cout << "1用户登陆\n";
		std::cout << "2用户注册\n";
		std::cout << "3游客登陆\n";
		std::cout << "4管理员登陆\n";
		std::cin >> a;
		if (a==1){
			userLogin(&myManager);
		}
		if (a == 2) {
			userRegister(&myManager);
		}
		if (a == 3) {
		}
		if (a == 4) {
			rootLogin(&myRoot);
		}
	}
	return 0;
}

void userLogin(UserManager *thisManager,MagazineManager *thisMagazineManager) {
	char *thisUsername = new char[20];
	char *thisPassword = new char[20];
	std::cout << "Enter your username\n";
	std::cin >> thisUsername;
	std::cout << "Enter your password\n";
	std::cin >> thisPassword;
	int userNumber = thisManager->isHaveAccount(thisUsername, thisPassword);
	if (userNumber > 0) {  //普通用户登陆成功
		int a;
		std::cout << "登陆成功\n";
		std::cout << "账户余额：";
		std::cout << thisManager->userList[userNumber - 1]->money;
		std::cout << "\n";
		std::cout << "1充钱\n";
		std::cout << "2买书\n";
		std::cout << "3已购\n";
		std::cin >> a;
		if (a==1){
			thisManager->addMoney(userNumber);
		}
		if (a==2){
			thisMagazineManager->showAllMagazine();
			std::cout << "请输入要购买书的编号\n";
			int c;
			std::cin >> c;
			thisManager->userAddMagazine(userNumber, c,thisMagazineManager);
		}
		if (a == 3) {
			thisManager->showUserBuy(userNumber, thisMagazineManager);
		}
	}
	else{
		std::cout << "密码错误或不存在此账号\n";
	}
}

void userRegister(UserManager *thisManager) {
	if (thisManager->addUser() == false) {
		std::cout << "注册失败，超过最大用户数\n";
	}
}

void rootLogin(RootManager *thisManager) {
	char *thisUsername = new char[20];
	char *thisPassword = new char[20];
	std::cout << "Enter your rootname\n";
	std::cin >> thisUsername;
	std::cout << "Enter your password\n";
	std::cin >> thisPassword;
	if (thisManager->isRootCorrect(thisUsername, thisPassword) == true) {
		std::cout << "登陆成功\n";
	}
	else {
		std::cout << "管理员账号错误\n";
	}
}

