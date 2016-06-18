#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n, head, tail;int map[100][100];
int vis[100];
int ans[100];

void print(int n) {
	for (int i = 0;i < n;i++) {
		cout << ans[i];
	}
	cout << endl;
}

void dfs(int step, int now) {
	if (now == tail) {
		print(step);
	}
	vis[now] = 1;
	for (int i = 0;i < n;i++) {
		if (vis[i] == 1 || map[now][i] == 0) {
			continue;
		}
		ans[step] = i;
		dfs(step + 1, i);
	}
	vis[now] = 0;								//清零当前点记录，让其他路径可走此点
}

int main()
{
	cin >> n >> head >> tail;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	ans[0] = head;
	dfs(1, head);
}
