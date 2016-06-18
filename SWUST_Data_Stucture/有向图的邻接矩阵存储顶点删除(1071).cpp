#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n, delete_p;int map[100][100];
int vis[100];
int ans[100];

int main()
{
	cin >> n >> delete_p;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	cout << n - 1 << endl;
	for (int i = 0;i < n;i++) {
		if (i == delete_p) {
			continue;
		}
		cout << i;
	}
	cout << endl;
	for (int i = 0;i < n;i++) {
		if (i == delete_p) {
			continue;
		}
		for (int j = 0;j < n;j++) {
			if (j == delete_p)
				continue;
			cout << map[i][j];
		}
		cout << endl;
	}
}
