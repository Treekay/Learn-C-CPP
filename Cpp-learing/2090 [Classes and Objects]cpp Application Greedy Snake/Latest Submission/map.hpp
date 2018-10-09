#ifndef MAP_H_
#define MAP_H_
#include "snake.hpp"
#include "global.hpp"
#include <list>
#include <algorithm>
#include <iostream>
#define MAX_SIZE 15
using std::cout;
using std::endl;
class map{
public:
	map(point &_size, point &_head,std::list<point> &_foods) {
		size = _size;
		ss.sethead(_head);
		foods = _foods;
		resertmap();
		save = 0;
	}
	void print(){
		if (!isGameOver()) resertmap();
		for (int row = 0; row < size.x; row++){
			for (int col = 0; col < size.y; col++){
				cout << gamemap [row][col];
			}
			cout << endl;
		}
		cout << endl;
	}
	map& resertmap(){
		for (int row = 0; row < size.x; row++){
			for (int col = 0; col <size.y; col++){
				gamemap[row][col] = EMPTY;
			}
		}
		auto poi = foods.begin();
		while (poi != foods.end()){
			gamemap[poi->x][poi->y] = FOOD;
			poi++;
		}
		int len = ss.getlength();
		if (gamemap[ss.gethead().x][ss.gethead().y] != BODY) gamemap[ss.gethead().x][ss.gethead().y] = HEAD;
		for (int index = 1; index < len; index++) {
			gamemap[ss.getbody(index).x][ss.getbody(index).y] = BODY;
		}
		return *this;
	}
	map& move(direction operation){
		point poi = ss.gethead();
		poi.move(operation);
		if (gamemap[poi.x][poi.y] == FOOD) {
			ss.getlonger();
			foods.erase(std::find(foods.begin(), foods.end(), poi));
		}
		ss.movement(operation);
		return *this;
	}
	bool isGameOver(){
		if (ss.gethead().x == size.x || ss.gethead().x < 0||
			ss.gethead().y == size.y || ss.gethead().y < 0) {
			return true;
		}
		for (int index = 1; index < ss.getlength(); index++){
			if (ss.gethead() == ss.getbody(index)) return true; 
		}
		return false;
	}
	~map(){}
private:
	point size;
	snake ss;
	std::list<point> foods;
	int save;
	char gamemap[MAX_SIZE][MAX_SIZE];
};
#endif