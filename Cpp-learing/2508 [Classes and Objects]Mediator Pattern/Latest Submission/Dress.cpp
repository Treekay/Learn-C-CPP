#include "Dress.hpp"

Dress::Dress(const string & _name, const int _price){
	name = _name;
	price = _price;
}
Dress::Dress(const Dress & oth){
	name = oth.name;
	price = oth.price;
}
int  Dress::getPrice() const{
	return price;
}
string  Dress::getName() const{
	return name;
}