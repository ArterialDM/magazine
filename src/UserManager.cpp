#include "User.cpp"
#include <iostream>
#include <string.h>
#include"MagazineManager.h"

class UserManager{

public:

	int userNumber;
	User * userList[100];

	UserManager() {
		userNumber = 0;
	}

	bool addUser() {
		if (userNumber == 100) {
			return false;
		}
		User *newUser =new User();
		std::cout << "Enter your username : \n";
		std::cin >> newUser->username;
		while (isHaveSame(newUser->username)){
			std::cout << "There is a same name,enter your username again: \n";
			std::cin >> newUser->username;
		}
		std::cout << "Enter your password : \n";
		std::cin >> newUser->password;
		userList[userNumber] = newUser;
		userNumber = userNumber + 1;
		newUser->number = userNumber;
		std::cout << "账户注册成功\n";
		return true;
	}

	int isHaveSame(char *newUsername) {
		if (userNumber == 0) {
			return 0;
		}
		for (int i = 0; i < userNumber; i++) {
			if (strcmp(newUsername, userList[i]->username) == 0) {
				return 1;
			}
		}
		return 0;
	}

	int isHaveAccount(char *thisUsername, char *thisPassword) {
		if (userNumber == 0) {
			return 0;
		}
		for (int i = 0; i < userNumber; i++) {
			if (strcmp(thisUsername, userList[i]->username) == 0) {
				if (strcmp(thisPassword, userList[i]->password) == 0) {
					return userList[i]->number;
				}
			}
		}
		return 0;
	}

	bool userAddMagazine(int userNumber,int magazineNumber, MagazineManager *thisMagazineManager) {
		if (userList[userNumber - 1]->money > thisMagazineManager->magazineList[magazineNumber - 1]->price) {
			userList[userNumber - 1]->money = userList[userNumber - 1]->money - thisMagazineManager->magazineList[magazineNumber - 1]->price;
		}
		else {
			std::cout << "购买失败，余额不足\n";
			return false;
		}
		if (userList[userNumber - 1]->magazineList[magazineNumber - 1] = 0) {
			userList[userNumber - 1]->magazineList[magazineNumber - 1] = 1;
			std::cout << "购买成功\n";
		}
		else {
			std::cout << "购买失败，你已经订阅过了\n";
			return false;
		}
		if (thisMagazineManager->getMagazine(magazineNumber) == false) {
			return false;
		}
		return true;
	}

	void readMagazine(int userNumber, int magazineNumber) {
		if(userList[userNumber - 1]->magazineList[magazineNumber - 1] = 1 ){
		}
	}

	bool addMoney(int userNumber) {
		int money;
		std::cout << "请输入要充的金额\n";
		std::cin >> money;
		userList[userNumber - 1]->money = userList[userNumber - 1]->money + money;
		std::cout << "充钱成功\n";
	}

	void showUserBuy(int userNumber,MagazineManager *thisMagazineManager) {
		bool flag = false;
		for (int i = 0; i < 100; i++) {
			if (userList[userNumber - 1]->magazineList[i] == 1) {
				thisMagazineManager->magazineList[i]->showInformation();
			}
		}
	}	
};

