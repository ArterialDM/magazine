#include<iostream>

class Root {

public:
	char *username;
	char *password;

	Root() {
		username = new char[20];
		password = new char[20];
	}

	~Root() {
		delete username;
		delete password;
	}
};
