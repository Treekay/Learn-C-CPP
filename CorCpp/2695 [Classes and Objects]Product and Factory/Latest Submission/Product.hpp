  #ifndef PRODUCT_H_
#define PRODUCT_H_
#include <iostream>
using namespace std;
class Laptop {
private:
	int factory_num;
public:
	Laptop(int num){
		factory_num = num;
	}
	int get_num(){
		return factory_num;
	}
	void compileCppProgram(){
		if (get_num() == 0){
			cout << "Apple Laptop compiles a cpp program." 
			<< endl;
		}
		else if (get_num() == 1){
			cout << "Xiaomi Laptop compiles a cpp program."
			<< endl;
		}
	}
};

class MobilePhone {
private:
	int factory_num;
public:
	MobilePhone(int num){
		factory_num = num;
	}
	int get_num(){
		return factory_num;
	}
	void sendShortMessage(){
		if (get_num() == 0){
			cout << "Apple MobilePhone sends a short message." 
			<< endl;
		}
		else if (get_num() == 1){
			cout << "Xiaomi MobilePhone sends a short message."
			<< endl;
		}
	}
};

#endif