#include "User.h"
#include"MagazineManager.h"

class UserManager{

public:
	int userNumber;
	User * userList[100];

	UserManager();

	bool addUser();

	User *newUser = new User();

	int isHaveSame(char *newUsername);

	int isHaveAccount(char *thisUsername, char *thisPassword);

	bool userAddMagazine(int userNumber, int magazineNumber, MagazineManager *thisMagazineManager);
	
	void readMagazine(int userNumber, int magazineNumber);
  
	bool addMoney(int userNumber);

	void showUserBuy(int userNumber, MagazineManager *thisMagazineManager);
};

