#include "zoo.h"
#include "animal.h"
#include <vector>
#include <iostream>

Zoo::Zoo(){

}
void Zoo::addAnimal(Cat *newcat){
	catcontain.push_back(*newcat);
}
void Zoo::addAnimal(Dog *newdog){
	dogcontain.push_back(*newdog);
}
void Zoo::deleteAnimalByName(string name){
	for (vector<Cat>::iterator poi = catcontain.begin();poi != catcontain.end(); ){
		if ((*poi).getName() == name) {
			catcontain.erase(poi);
		}
		else poi++;
	}
	for (vector<Dog>::iterator poi = dogcontain.begin();poi != dogcontain.end(); ){
		if ((*poi).getName() == name) {
			dogcontain.erase(poi);
		}
		else poi++;
	}
}
void Zoo::deleteAnimalByAge(int age){
	for (vector<Cat>::iterator poi = catcontain.begin();poi != catcontain.end(); ){
		if ((*poi).getAge() == age) {
			catcontain.erase(poi);
		}
		else poi++;
	}
	for (vector<Dog>::iterator poi = dogcontain.begin();poi != dogcontain.end(); ){
		if ((*poi).getAge() == age) {
			dogcontain.erase(poi);
		}
		else poi++;
	}
}
int Zoo::getCatCount(){
	int count = 0;
	for (vector<Cat>::iterator poi = catcontain.begin();poi != catcontain.end(); poi++){
		if ((*poi).getType() == 0) count++;
	}
	return count;
}
int Zoo::getDogCount(){
	int count = 0;
	for (vector<Dog>::iterator poi = dogcontain.begin();poi != dogcontain.end(); poi++){
		if ((*poi).getType() == 1) count++;
	}
	return count;
}
void Zoo::print(){
	for (vector<Dog>::iterator poi = dogcontain.begin();poi != dogcontain.end(); poi++){
		(*poi).Shout();
	}
	for (vector<Cat>::iterator poi = catcontain.begin();poi != catcontain.end(); poi++){
		(*poi).Shout();
	}
}
Zoo::~Zoo(){
	catcontain.clear();
	dogcontain.clear();
}