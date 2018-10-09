#include <iostream>
using namespace std;

static int person_count = 0;

typedef struct person { 
	int ID = person_count++;
}person;

class group {
private:
	int group_member[50];
	int friendgroup[50][50];
	int friendnum[50];
	int knoweach;
	int member_num;
public:
	group(int num){
		knoweach = num;
		member_num = 0;
		for (int index = 0; index < 50; index++){
			group_member[index] = 0;
			friendnum[index] = 0;
		}
		for (int index = 0; index < 50; index++){
			for (int poi = 0; poi < 50; poi++){
				friendgroup[index][poi] = 0;
			}
		}
	}
	void displayGroup(){
		for (int index = 0; index < 50; index++){
			if (group_member[index] == 1) {
				cout<< "Person_" << index << ':';
				int count = 0;
				if (friendnum[index] < 0 ||friendnum[index] == 0) {
					cout << " null" << endl;
					continue;
				}
				for (int poi = 0; poi < 50; poi++){
					if (friendgroup[index][poi] == 1 && index != poi) {
						cout << ' '<< poi;
						count++;
						if (count < friendnum[index]) cout << ',';
						else {
							cout << endl;
							break;
						}
					}
				}
			}
		}
	}
	bool addMember(person &p){
		if (group_member[p.ID] == 1) return false;
		group_member[p.ID] = 1;
		member_num++;
		if (knoweach == 1){
			for (int index = 0; index < 50; index++){
				if (group_member[index] == 1) {
					for (int poi = 0; poi < 50; poi++){
						if (group_member[poi] == 1&&poi != index) friendgroup[index][poi] = 1;
					}
				}
				friendnum[index] = member_num-1;
			}
		}
		return true;
	}
	bool deleteMember(person &p){
		if (group_member[p.ID] == 0) return false;
		group_member[p.ID] = 0;
		return true;
	}
	bool makeFriend(person &p1, person &p2){
		if (friendgroup[p1.ID][p2.ID] == 1||friendgroup[p2.ID][p1.ID] == 1) return false;
		friendgroup[p1.ID][p2.ID] = 1;
		friendgroup[p2.ID][p1.ID] = 1;
		friendnum[p1.ID]++;
		friendnum[p2.ID]++;
		return true;
	}
	bool breakRelation(person &p1, person &p2){
		if (friendgroup[p1.ID][p2.ID] == 0||friendgroup[p2.ID][p1.ID] == 0) return false;
		friendgroup[p1.ID][p2.ID] = 0;
		friendgroup[p2.ID][p1.ID] = 0;
		friendnum[p1.ID]--;
		friendnum[p2.ID]--;
		return true;
	}
};