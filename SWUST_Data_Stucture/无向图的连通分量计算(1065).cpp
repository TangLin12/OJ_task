#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n;int map[100][100];
int vis[100];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	queue<int> q;
	int ans = 0;
	for (int i = 0;i < n;i++) {
		if (vis[i] == 1)
			continue;
		vis[i] = 1;
		q.push(i);
		ans++;
		while (!q.empty()) {
			int tmp = q.front();q.pop();
			for (int j = 0;j < n;j++) {
				if (vis[j] == 1 || map[tmp][j] == 0) {
					continue;
				}
				vis[j] = 1;
				q.push(j);
			}
		}
	}
	cout << ans;
}
