#include<iostream>
#include<queue>
using namespace std;
#define MAX 99999
int n;int map[100][100];
typedef struct pos{
	int x;int y;
}pos;

int main()
{
	cin >> n;
	int max = -MAX, min = MAX;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
			if (i == j) {
				continue;
			}
			if (map[i][j]>max) {
				max = map[i][j];
			}
			if (map[i][j] != -1 && min>map[i][j]) {
				min = map[i][j];
			}
		}
	}
	queue<pos> Max, Min;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (map[i][j] == max) {
				pos tmp;tmp.x = i;tmp.y = j;
				Max.push(tmp);
			}
			if (map[i][j] == min) {
				pos tmp;tmp.x = i;tmp.y = j;
				Min.push(tmp);
			}
		}
	}
	cout << max << endl;
	while (!Max.empty()) {
		cout << "<" << Max.front().x << " " << Max.front().y << ">";
		Max.pop();
	}
	cout << endl << min << endl;
	while (!Min.empty()) {
		cout << "<" << Min.front().x << " " << Min.front().y << ">";
		Min.pop();
	}
}
