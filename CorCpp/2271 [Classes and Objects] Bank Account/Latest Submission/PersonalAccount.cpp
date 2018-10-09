 #include "PersonalAccount.h"
#include <cstdio>
#include <iostream>
using namespace std;

int PersonalAccount::_total_per_account = 0;
int PersonalAccount::_acc_id_ptr = 12010001;
PersonalAccount::PersonalAccount() : Account::Account(){
	_id = _acc_id_ptr + Account::get_total_account();
	_balance = 10;
	_valid = true;
	PersonalAccount::_total_per_account++;
}
PersonalAccount::~PersonalAccount(){
	_total_per_account = 0;
	_balance = 10;
}
// override
std::string PersonalAccount::profile() const{
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

	str += "VALID:Y";
	str += "\n";

	str += "TYPE:PERSONAL";
	str += "\n";

	return str;
}
void PersonalAccount::reset(){
	PersonalAccount::_total_per_account = 0;
	_balance = 10;
}
// static
int PersonalAccount::get_total_per_account(){
	return PersonalAccount::_total_per_account;
}