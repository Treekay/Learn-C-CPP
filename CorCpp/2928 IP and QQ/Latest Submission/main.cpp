 #include <iostream>
#include <map>
#include <set>
using namespace std;

int main(void){
	int n;
	cin >> n;
	multimap <string, string> info;	
	string input_qq;
	string input_ip;
	for (int index = 0; index < n; index++ ){
		cin >> input_qq >> input_ip;
		info.insert(pair<string, string>(input_qq, input_ip));
	}
	string find_qq, find_ip;
	cin >> find_ip >> find_qq;	
	set<string> qq_set;
	set<string> ip_set;	
	for (multimap<string, string>::iterator iter = info.begin(); iter != info.end(); iter++){
		if ((*iter).second == find_ip) {
			qq_set.insert((*iter).first);
		}
		if ((*iter).first == find_qq) {
			ip_set.insert((*iter).second);
		}
	} 	
	if (qq_set.size() == 0) cout << "no qq" << endl;
	else {
		cout << find_ip << " ==> [ ";
		for (set<string>::iterator iter = qq_set.begin(); iter != qq_set.end(); iter++ ){
			cout << *iter << ' ';
		}
		cout << "]" << endl;
	}	
	if (ip_set.size() == 0) cout << "no ip" << endl;
	else {
		cout << find_qq << " ==> [ ";
		for (set<string>::iterator iter = ip_set.begin(); iter != ip_set.end(); iter++ ){
			cout << *iter << ' ';
		}
		cout << "]" << endl;
	}
	return 0;
}