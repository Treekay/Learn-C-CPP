#include "dns.h"

dns::dns(string ip){
	_ip = ip;
}
vector<string>& dns::operator[](const string& domain){
	return _map[domain];
} 
void dns::nslookup(const string& domain){
	for (auto &iter:_map){
		if (iter.first == domain && iter.second.size() != 0){
			cout << "Server: " << _ip << endl;
			for (int poi = 0; poi < iter.second.size(); poi++){
				cout << "Name: " << domain << endl;
				cout << "Address: " << iter.second[poi] << endl;
			}
			return;
		}
	}
	cout << "Server: " << _ip << endl;
	cout << "Server can't find " << domain << endl;
}