#include "user.hpp"
#include <cstring>

Alipay::user::user(const char* _username, const char* _password){
	strcpy(username, _username);
	strcpy(password, _password);
  balance = 0;
}
Alipay::user::~user(){

}
const char* Alipay::user::getUsername() const{
	return username;
}
const char* Alipay::user::getPassword() const{
	return password;
}
const void Alipay::user::setUsername(const char* _username){
	strcpy(username, _username);
}
const void Alipay::user::setPassword(const char* _password){
	strcpy(password, _password);
}

double Alipay::user::getBalance(){
	return balance;
}
bool Alipay::user::withdraw(double amount){
	if (amount > 0) {
		if (amount < balance) {
			balance -= amount;
			return true;
		}
		else return false;
	}
	else return false;
}
bool Alipay::user::deposite(double amount){
	if (amount > 0) {
		balance += amount;
		return true;
	}
	else return false;
}