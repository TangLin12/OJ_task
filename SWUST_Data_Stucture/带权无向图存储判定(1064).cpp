#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n;int map[100][100];

int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	bool flag = true;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (map[i][j] != map[j][i]) {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << "yes";
	}
	else {
		cout << "no";
	}
}
