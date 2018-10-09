 #include "Mediator.hpp"
#include "User.hpp"
#include "Dress.hpp"
#include <list>
#include <iostream>
using namespace std;

Mediator* Mediator::Ins = NULL;
Mediator* getInstance();
void DestroyIns();

void Mediator::RegisterHandler(User * u){
	users.push_back(u);
}
void Mediator::ChatHandler(const int & to, const string & msg){
	for (list<User*>::iterator index = users.begin(); index != users.end(); index++){
		if ((*index)->getId() == to) {
			(*index)->GetMessage(msg);
			return;
		}
	}
	cout << "Are you kidding ? There is no such a guy!" << endl;
}
pair<int,string> Mediator::TradeHandler(const int & to, const int & pay, const string & dressName){
	for (list<User*>::iterator index = users.begin(); index != users.end(); index++){
		if ((*index)->getId() == to) {
			return (*index)->SellBeautifulDress(pay, dressName);
		}
	}
	cout << "There is no Such a guy!" << endl;
}
void Mediator::DressInfoHandler(const int & to){
	for (list<User*>::iterator index = users.begin(); index != users.end(); index++){
		if ((*index)->getId() == to) {
			(*index)->ShowMyCuteDresses();
			return;
		}
	}
}