#include<iostream>
#include"Magazine.h"

class MagazineManager {
public:
	     Magazine *magazineList[100];
	     int number;
	     MagazineManager() {
		       number = 0;
	     }
	     ~MagazineManager(){
	     }
	     bool addMagazine() {
		       if (number == 100) {
			         std::cout << "超过100本书，增加失败\n";
			         return false;
		       }
		       number = number + 1;
		       Magazine *newMagazine = new Magazine();
		       newMagazine->addMagazine(number);
		       magazineList[number-1] = newMagazine;
	         std::cout << "增加成功\n";
		       return true;
      	}
        
	      bool getMagazine(int thisNumber) {
		        if (magazineList[thisNumber - 1]->quantity == 0) {
		            std::cout << "这本书已经没有库存了\n";
			          return false;
		        }
		        magazineList[thisNumber - 1]->quantity = magazineList[thisNumber - 1]->quantity - 1;
	    	    std::cout << "订阅成功\n";
		        return true;
	      }

	      void showAllMagazine() {
		        for (int i = 0; i < number; i++) {
		            if (magazineList[i]->flag == true) {
				            magazineList[i]->showInformation();
			          }
		         }
	      }

	      void cleanZero() {
		        bool flag = false;
		        for (int i = 0; i < number; i++){
			          if (magazineList[i]->quantity == 0) {
				            magazineList[i]->flag = false;
				            flag = true;
			          }
		        }
		        if (flag==true){
			          std::cout << "清理成功\n";
		        }else{
			          std::cout << "没有库存为0的书\n";
		         }
	      }

	      void search(char key) {
		        for (int i = 0; i < number; i++) {
			          if (*(magazineList[i]->title) == key) {
				            magazineList[i]->showInformation();
			          }
		        }
	      }
        
private:

};
