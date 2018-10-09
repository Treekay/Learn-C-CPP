#include "userController.hpp"
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int Alipay::userController::getUserIndex(const char* _username) const{
	int index;
	for (index = 0; index < usercount; index++){
		if (strcmp(users[index]->getUsername(),_username) == 0) return index;
	}
}
Alipay::userController::userController(double interest){
	interest_rate = interest;
	usercount = 0;
}
Alipay::userController::~userController(){
	for (int index = 0;index < usercount; index++) delete users[index];
}
bool Alipay::userController::createUser(const char* _username, const char* _password){
	int len1= strlen(_username);
	if (len1< 6||len1> 20) return false;
	int index1;
	for (index1 = 0; index1 < len1; index1++) {
		if (!isalnum(_username[index1])) return false;
	}
	int len2= strlen(_password);
	if (len2< 8||len2> 20) return false;
	int index2;
	for (index2 = 0; index2 < len2; index2++) {
		if (!isalnum(_password[index2])) return false;
	}
	users[usercount] = new Alipay::user(_username,_password);
	usercount++;
	return true;
}
bool Alipay::userController::deposite(const char* _username, double amount){
	int index = getUserIndex(_username);
	return users[index]->deposite(amount);
}
bool Alipay::userController::withdraw(const char* _username, double amount){
	int index = getUserIndex(_username);
	return users[index]->withdraw(amount);
}
std::string Alipay::userController::getUserInfoByName(const char* _username) const{
	int index = getUserIndex(_username);
	string info;
	info += "username:";
	info += users[index]->getUsername();
	info += "\n";
	info += "password:*********";
	info += "\n";
	info += "balance:";
	string bal;
	stringstream ss;
	ss<< users[index]->getBalance();
	ss >> bal;
	info += bal;
	info += "\0";
	return info;
}
int Alipay::userController::getUserCount(void) const{
	return usercount;
}
bool Alipay::userController::removeUserByUsername(const char* _username){
	int index = getUserIndex(_username);
	delete users[index];
	for (int poi = index; poi < usercount-1; poi++){
		users[poi] = users[poi+1];
	}
	usercount--;
}
bool Alipay::userController::setInterest(double interest){
	if (interest >= 0) {
		interest_rate = interest;
		return true;
	}
	else return false;
}
void Alipay::userController::payInterest(void){
	int index;
	for (index = 0; index < usercount; index++) {
		users[index]->deposite(users[index]->getBalance()* interest_rate);
	}
}
