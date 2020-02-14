#include<iostream>
#include<stdio.h>

class Magazine {

public:
	char *title;
	int number;
	int price;
	int quantity;
	bool flag;
  
	Magazine() {
		title = new char[20];
	}
  
	~Magazine() {
		delete title;
	}
  
	void addMagazine(int newNumber) {
		number = newNumber;
		std::cout << "请输入书名\n";
		std::cin.getline(title, 20);
		std::cout << "请输入价格\n";
		std::cin >> price;
		std::cout << "请输入库存\n";
		std::cin >> quantity;
		flag = true;
	}

	void showInformation() {
		printf("书名:%s\n", title);
		printf("编号:%d\n", number);
		printf("价格:%d\n", price);
		printf("库存:%d\n", quantity);
	}
};
