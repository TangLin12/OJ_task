#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n;int map[100][100];
int vis[100];
char str[100];
void bfs(int now) {
	queue<int> q;
	q.push(now);
	vis[now] = 1;
	while (!q.empty()) {
		int tmp = q.front();q.pop();
		cout << str[tmp];
		for (int i = 0;i < n;i++) {
			if (vis[i] || map[tmp][i] == 0) {
				continue;
			}
			q.push(i);
			vis[i] = 1;
		}
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
			bfs(i);
			break;
		}
	}
}
