#include<iostream>
#include <algorithm>
using namespace std;
#define SIZE 1005
typedef struct Task{
	int lim;
	int pun;
}Task;

bool cmp(Task a, Task b) {
	if (a.pun != b.pun) {
		return a.pun > b.pun;
	}
	else {
		return a.lim < b.lim;
	}
}
int timeline[SIZE];Task task[SIZE];int sum_of_pun = 0;

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> task[i].lim;
	}
	for (int i = 0;i < n;i++) {
		cin >> task[i].pun;
	}
	sort(task, task + n, cmp);
	for (int i = 0;i < n;i++) {
		if (timeline[task[i].lim] == 0) {
			timeline[task[i].lim] = 1;
		}
		else {
			int pre_time=task[i].lim;
			while (timeline[pre_time] != 0 && pre_time != 0) {
				--pre_time;
			}
			if (pre_time == 0) {
				sum_of_pun += task[i].pun;
			}
			else {
				timeline[pre_time] = 1;
			}
		}
	}
	cout << sum_of_pun << endl;
}