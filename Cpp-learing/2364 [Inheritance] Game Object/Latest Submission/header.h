#include <iostream> 
using namespace std;
class gameobject{
protected:
	int x, y;
	int hp;
	int speed;
public:
	virtual void select() = 0;
	virtual void move() = 0;
	void flood(){
		hp--;
	}
	void getfull(){
		hp = 10;
	}
	int get_hp(){
		return hp;
	}
};

class tower: public gameobject{
public:
	tower (int _x, int _y){
		x = _x;
		y = _y;
		hp = 10;
		speed = 0;
	}
	void select(){
		cout <<  "~" << endl;
	}
	void move(){
		cout << "Tower cannot move." << endl;
	}
	void attack(gameobject* poi){
		poi->flood();
	}
};

class zealot: public gameobject{
public:
	zealot (int _x, int _y){
		x = _x;
		y = _y;
		hp = 10;
		speed = 2;
	}
	void select(){
		cout <<  "My life for Aiur!" << endl;
	}
	void move(){
		x += 2;
		y += 2;
		cout << "Zealot moves to (" << x << ", "<< y << ')' << endl; 
	}
	void attack(gameobject* poi){
		poi->flood();
	}
};

class worker: public gameobject{
public:
	worker (int _x, int _y){
		x = _x;
		y = _y;
		hp = 10;
		speed = 1;
	}
	void select(){
		cout <<  "Scv good to go, sir!" << endl;
	}
	void move(){
		x += 1;
		y += 1;
		cout << "Worker moves to (" << x << ", "<< y << ')' << endl; 
	}
	void repair(gameobject* poi){
		poi->getfull();
	}
	void build(int height){
		for (int index  = 0; index < height; index++){
			for (int index1 = 0; index1 < height-1-index; index1++) cout << ' ';
			for (int index2 = 0; index2 < 2*(index+1)-1; index2++) cout <<'*';
				cout << endl;
		}
	}
};