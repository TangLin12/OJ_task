#include<iostream>

using namespace std;

typedef struct Node {
	int x;
	int y;
}Node;

Node node[700];

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> node[i].x >> node[i].y;
	}
	int ans = 0;
	for (int i = 0;i < n;i++) {
		for (int j = i + 1;j < n;j++) {
			int tmp = 2;
			int xab = node[j].x - node[i].x;
			int	yab = node[j].y - node[i].y;
			for (int k = j + 1;k < n;k++) {
				int xac = node[k].x - node[i].x;
				int yac = node[k].y - node[i].y;
				if (yab*xac == yac*xab) {
					++tmp;
				}
				tmp > ans ? ans = tmp : 1;
			}
		}
	}
	cout << ans << endl;
}