class Magazine {

public:
	char *title;
	int number;
	int price;
	int quantity;
	bool flag;
	Magazine();
	~Magazine();
	void addMagazine(int newNumber);
	void showInformation();
};
