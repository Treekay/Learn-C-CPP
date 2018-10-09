#include <string>
#include <cctype>
#include <iostream>
#include "user.hpp"

inline bool alipay::User::verifyPasswordFormat(const std::string &password){
	int len = password.length();
	if (len < 8||len > 20) return false;
	int index;
	for (index = 0; index < len; index++) {
		if (!isalnum(password[index])) return false;
	}
	return true;
}
inline bool alipay::User::verifyUsernameFormat(const std::string &username){
	int len = username.length();
	if (len < 6||len > 20) return false;
	int index;
	for (index = 0; index < len; index++) {
		if (!isalnum(username[index])) return false;
	}
	return true;
}
inline bool alipay::User::verifyPhoneFormat(const std::string &phone){
	int len = phone.length();
	if (len != 13) return false;
	int index;
	for (index = 0; index < len; index++) {
		if (!isdigit(phone[index])) return false;
	}
	return true;
}
bool alipay::User::setUsername(const char *username) {
	if (User::verifyUsernameFormat(username)) {
   alipay::User::username = username;
		return true;
	}
	else return false;
}
bool alipay::User::setPassword(const char *new_password, const char *old_password){
	if (User::verifyPasswordFormat(new_password)) {
 alipay::User::password = new_password;
		return true;
	}
	else return false; 
}
bool alipay::User::setPhone(const char *new_phone){
	if (User::verifyPhoneFormat(new_phone)) {
 alipay::User::phone = new_phone;
		return true;
	}
	return false;
}
bool alipay::User::setGender(Gender::Gender gender){
	if (gender == 0|| gender == 1) {
		alipay::User::gender = gender;
		return true;
	}
	else return false;
}
std::string alipay::User::getUsername(void){
	return alipay::User::username;
}
std::string alipay::User::getPhone(void){
	return alipay::User::phone;
}
alipay::Gender::Gender alipay::User::getGender(void){
	return alipay::User::gender;
}

long long int alipay::User::getMoneyAmount(const char *password){
	if (password == alipay::User::password) return alipay::User::balance;
	else return 0;
}
bool alipay::User::deposit(long long int amount){
	if (amount > 0) {
		alipay::User::balance = amount;
		return true;
	}
	else return false;
}
bool alipay::User::withdraw(long long int amount, const char *password){
	if (amount > 0) {
		if (alipay::User::getMoneyAmount(password)&&
			amount <= alipay::User::balance)
		return true;
		else return false;
	}
	else return false;
}