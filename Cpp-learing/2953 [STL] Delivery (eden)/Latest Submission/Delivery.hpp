#ifndef _DELIVERY_H
#define _DELIVERY_H
#include <map>
#include <vector>
#include <string>
using namespace std;

vector<string> getInfoSort(vector<string> _info){
	map<string, string> info;
	for (int index = 0; index < _info.size(); index++){
		int find(0);
		string date = _info[index].substr(0,19);
		string message = _info[index].substr(20,_info[index].length()-20);
		for (map<string, string>::iterator iter = info.begin(); iter != info.end(); iter++){
			if (iter->second == message) {
				find = 1;
				if (date < iter->first){
					info.erase(iter);
					info[date] = message;
					break;
				}
			}
		}
		if (find == 0) info[date] = message;
	}
	vector<string> info_after_sort;
	for (auto iter:info){
		string str; 
		str += iter.first + " : " + iter.second;
		info_after_sort.push_back(str);
	}
	return info_after_sort;
}

#endif
