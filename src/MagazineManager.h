#include"Magazine.h"
class MagazineManager {
public:
	Magazine *magazineList[100];
	int number;
	MagazineManager();
	~MagazineManager();
	bool addMagazine();
	bool getMagazine(int thisNumber);
	void showAllMagazine();
	void cleanZero();
	void search(char key);
private:

};
