#include<iostream>

using namespace std;
const int maxsize = 50000;

int a[50][50];
int m, n;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 } ,{ 0,-1 } };

void dfs(int x, int y) {
	a[x][y] = 0;
	for (int i = 0;i < 4;i++) {
		int dx = x + dir[i][0];int dy = y + dir[i][1];
		if (0 <= dx&&dx < n && 0 <= dy&&dy < m&&a[dx][dy] != 0) {
			dfs(dx, dy);
		}
	}
}


int count()
{
	int sum = 0;
	cin >> m >> n;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> a[j][i];
		}
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (a[j][i] != 0) {
				dfs(j, i);
				sum++;
			}
		}
	}
	return sum;
}


int main()
{
	cout << count();
	return 0;
}