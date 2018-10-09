#include "Account.h"
#include <iostream>
#include <cstdio>
using namespace std;

int Account::_total_account = 0;
Account::Account(){
	_id = 0;
	_balance = 0;
	_valid = false;
	Account::_total_account++;
}
Account::~Account(){
	_total_account = 0;
	_balance = 0;
}
int Account::id() const{
	return _id;
}
double Account::balance() const{
	return _balance;
}
bool Account::valid() const{
	return _valid;
}
string Account::profile() const{
	string str;
	str += "ID:";
	char input[10];
	sprintf(input,"%d",_id);
	str += input;
	str += "\n";

	str += "BALANCE:";
	sprintf(input,"%.6lf",_balance);
	str += input;
	str += "\n";

	str += "VALID:N";
	str += "\n";

	return str;
}
void Account::reset(){
	Account::_total_account = 0;
	_balance = 0;
}
bool Account::deposit(const double &num){
	if (num > 0) {
		_balance += num;
		return true;
	}
	else return false;
}
bool Account::draw(const double &num){
	if (num > 0) {
		if (_balance - num >= 0.01) {
			_balance -= num;
			return true;
		}
		else return false;
	}
	else return false;
}
int Account::get_total_account(){
	return Account::_total_account;
}