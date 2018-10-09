 #include "VIPAccount.h"
#include <cstdio>
#include <iostream>
using namespace std;

int VIPAccount::_total_vip_account = 0;
int VIPAccount::_acc_id_ptr = 12050000;
VIPAccount::VIPAccount(): Account::Account(){
	_id = _acc_id_ptr + _total_vip_account;
	_balance = 10;
	_valid = true;
	 VIPAccount::_total_vip_account++;

	_loan = 0;
	_loan_limit = 1000;
}
VIPAccount::~VIPAccount(){
	 _balance = 10;
	 _loan = 0;
	 _loan_limit = 1000;
}
bool VIPAccount::loan(const double &num){
	if (_loan + num <= _loan_limit ) {
		_loan += num;
		deposit(num);
		return true;
	}
	else return false;
}
bool VIPAccount::repay(const double &num){
	if (num > 0 && _loan - num >= 0 && _balance - num >= 0.01){
		_loan -= num;
		draw(num);
		return true;
	}
	else return false;
}
// override
std::string VIPAccount::profile() const{
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

	str += "TYPE:VIP";
	str += "\n";

	str += "LOAN:";
	sprintf(input,"%.6lf",_loan);
	str += input;
	str += ",";

	str += "LIMIT:";
	sprintf(input,"%.6lf",_loan_limit);
	str += input;
	str += "\n";

	return str;
}
void VIPAccount::reset(){
	 VIPAccount::_total_vip_account = 0;
	 _balance = 10;
	 _loan = 0;
	 _loan_limit = 1000;
}
// static
int VIPAccount::get_total_vip_account(){
	return  VIPAccount::_total_vip_account;
}