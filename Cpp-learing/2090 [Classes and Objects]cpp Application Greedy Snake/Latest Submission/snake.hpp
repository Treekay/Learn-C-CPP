#ifndef SNAKE_H_
#define SNAKE_H_
#include "global.hpp"

class snake{
public:
	snake(){
		length = 1;
	}
	snake& sethead(const point &_head){
		body[0] = _head;
		return *this;
	}
	int getlength(){
		return length;
	}
	void getlonger(){
		body[length] = body[length-1];
		length++;
	}
	point getbody(int index){
		return body[index];
	}
	void movement(direction operation){
		for (int index = length-1; index > 0; index--){
			body[index] = body[index-1];
		}
		body[0].move(operation);
	}
	point gethead(){
		return body[0];
	}
	~snake(){}
private:
	int length;
	point body[225];
};
#endif