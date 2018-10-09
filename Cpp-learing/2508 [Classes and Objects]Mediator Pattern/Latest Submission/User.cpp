#include "User.hpp"
#include "Mediator.hpp"
#include "Dress.hpp"
#include <iostream>
#include <vector>
using namespace std;

int User::Count = 0;
User::User(const string & _name, const int & _money, const vector<pair<string, int> > & _dresses){
	name = _name;
	money = _money;
	id = Count++;
	for (int index = 0; index < _dresses.size(); index++){
		Dress poi(_dresses[index].first, _dresses[index].second);
		dresses.push_back(poi);
	}
}
void User::BuyBeautifulDress(const int & _id, const int & pay, const string & _name){
	if (pay > money) {
		cout << this->name << " : " << "Forget to Check Wallet!" << endl;
		return;
	}
	else {
		pair<int, string> poi = Mediator::getInstance()->TradeHandler(_id, pay, _name);
		if (poi.first != 0) {
			int _price = poi.first;
			Dress poi(_name, _price);
			dresses.push_back(poi);
			money -= pay;
		}
		if (poi.second == "S") {
			cout << this->name << " : " << "So happy to get new Dress!" << endl;
		}
		else if (poi.second == "F") {
			cout << this->name << " : " << "I'm so sorry maybe just because I love it so much." << endl;
		}
		else if (poi.second == "L") {
			cout << this->name << " : " <<  "OMG! Why it is so Expensive!" << endl;
		}
	}
}
void User::GetDressInfo(const int & _id){
	cout << this->name << " : " << "I wanna see your beautiful suits!" << endl;
	Mediator::getInstance()->DressInfoHandler(_id);
}
pair<int, string> User::SellBeautifulDress(const int & pay, const string & dname) {// how to use to pair to represent diffierent information?
	for (vector<Dress>::iterator index = dresses.begin(); index != dresses.end(); index++){
		if ((*index).getName() == dname) {
			if (pay >= (*index).getPrice()) {
				cout << this->name << " : " << "What a good taste you have !" << endl;
				pair<int, string> poi;
				poi.first = (*index).getPrice();
				poi.second = "S";
				dresses.erase(index);
				money += pay;
				return poi;
			}
			else if (pay < (*index).getPrice()) {
				cout << this->name << " : " <<  "No monry then no talking" << endl;
				pair<int, string> poi;
				poi.first = 0;
				poi.second = "L";
				return poi;
			}
		}
	}
	cout << this->name <<" : " << "I never have this Dress stupid!" << endl;
	pair<int, string> poi;
	poi.first = 0;
	poi.second = "F";
	return poi;
}
void User::SendMessage(const int & to, const string & msg){
	Mediator::getInstance()->ChatHandler(to, msg);
}
void User::GetMessage(const string & msg){
	cout << this->name <<" : I got a Msg - " << msg << endl;
}
void User::ShowMyCuteDresses(){
	cout << this->name << " : ok,these are all I have : "<<endl;
	for (int index = 0; index < dresses.size(); index++){
		cout << dresses[index].getName() << "-" << dresses[index].getPrice() << endl;
	}
}