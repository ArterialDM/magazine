#include<iostream>
#include"Magazine.h"

class User {

public:
	int number;
	char *username;
	char *password;
	int money;
	int magazineList[100];
	
	User() {
		username = new char[20];
		password = new char[20];
		money = 0;
		for (int i = 0; i < 100; i++){
			magazineList[i] = 0;
		}
	}

	~User(){
		delete username;
		delete password;
	}
};
