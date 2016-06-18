#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n;int map[100][100];
int vis[100];
char str[100];
void dfs(int now) {
	vis[now] = 1;
	cout << str[now];
	for (int i = 0;i < n;i++) {
		if (vis[i] == 1 || map[now][i] == 0) {
			continue;
		}
		dfs(i);
	}
}

int main()
{
	cin >> n;cin >> str;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	char ch;cin >> ch;
	for (int i = 0;i < n;i++) {
		if (ch == str[i]) {
			dfs(i);
			break;
		}
	}
}
