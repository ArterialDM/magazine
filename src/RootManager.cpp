#include "Root.h"
#include <iostream>
#include <string.h>
#include <cstring>

class RootManager {

public:
	Root root;

	RootManager() {
		strcpy_s(root.username,5, "Wang");
		strcpy_s(root.password,5, "1999");
	}

	bool isRootCorrect(char *tryUsername,char *tryPassword) {
		if (strcmp(tryUsername, root.username) == 0) {
			if (strcmp(tryPassword,root.password)==0) {
				return true;
			}
		}
		return false;
	}
};
