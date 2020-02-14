#include "Root.h"
#include <iostream>
#include <string.h>
#include <cstring>
class RootManager {

public:

	Root root;

	RootManager();
  
	bool isRootCorrect(char *tryUsername, char *tryPassword);
};
