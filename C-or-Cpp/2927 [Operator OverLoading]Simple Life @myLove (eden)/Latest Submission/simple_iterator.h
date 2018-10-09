 #include <iostream>
using namespace std;

class simple_iterator{
private:
	char* pointer;
public:
	simple_iterator(){
		pointer = NULL;
	}
	simple_iterator(char* data){
		pointer = data;
	}
	simple_iterator prev(){
		return simple_iterator(pointer-1);
	}
	simple_iterator next(){
		return simple_iterator(pointer+1);
	}
	simple_iterator begin(){
		char* poi = pointer;
		while(*poi != '\0'){
			poi--;
		}
		return simple_iterator(poi+1);
	}
	simple_iterator end(){
		char* poi = pointer;
		while(*poi != '\0'){
			poi++;
		}
		return simple_iterator(poi-1);
	}
	friend char operator*(simple_iterator poi){
		return *(poi.pointer);
	}
	simple_iterator operator++(){
		return simple_iterator(++pointer);
	}
	simple_iterator operator--(){
		return simple_iterator(--pointer);
	}
	simple_iterator operator++(int num){
		return simple_iterator(pointer++);
	}
	simple_iterator operator--(int num){
		return simple_iterator(pointer--);
	}
	bool operator==(simple_iterator other){
		if (*pointer == *(other.pointer)) return true;
		else return false;
	}
	bool operator!=(simple_iterator other){
		if (*pointer != *(other.pointer)) return true;
		else return false;
	}
	bool operator<(simple_iterator other){
		if (*pointer < *(other.pointer)) return true;
		else return false;
	}
	bool operator>(simple_iterator other){
		if (*pointer > *(other.pointer)) return true;
		else return false;
	}
	bool operator<=(simple_iterator other){
		if (*pointer <= *(other.pointer)) return true;
		else return false;
	}
	bool operator>=(simple_iterator other){
		if (*pointer >= *(other.pointer)) return true;
		else return false;
	}
	simple_iterator operator+(int num){
		return simple_iterator(pointer + num);
	}
	simple_iterator operator-(int num){
		return simple_iterator(pointer - num);
	}

};