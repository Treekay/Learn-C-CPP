 #include <iostream>
#include <queue>
using namespace std;

typedef struct job{
	int priority;
	int target;
	job(int _priority = 0,int _target = 0){
		priority = _priority;
		target = _target;
	}
}job;
int main(void){
	int test_time;
	cin >> test_time;
	for (int index = 0; index < test_time; index++){
		int n, m;
		int pri;
		cin >> n >> m;
		deque<job> jobs;
		for (int poi = 0; poi < n; poi++){
			cin >> pri;
			if (poi != m) jobs.push_back(job(pri,0));
			else jobs.push_back(job(pri,1));
		}
		int cost_time = 0;
		for (deque<job>::iterator iter = jobs.begin(); iter != jobs.end(); ){
			iter = jobs.begin();
			int find_more_pri = 0;
			for (deque<job>::iterator ins = iter+1; ins != jobs.end(); ins++){
				if ((*ins).priority > (*iter).priority) {
					jobs.push_back(job((*iter).priority, (*iter).target));
					jobs.pop_front();
					find_more_pri = 1;
					break;
				}
			}
			if (find_more_pri == 0){
				cost_time++;
				if ((*iter).target == 1) break;
				else {
					jobs.pop_front();
				}
			}
		}
		cout << cost_time << endl;
	}
	return 0;
}