#include<iostream>

using namespace std;
#define SIZE 10000
int cur[SIZE], pre[SIZE];

int main()
{
	int row, col;cin >> row >> col;
	int n;cin >> n;
	for (int i = 0;i < row*col;i++) {
		cin >> pre[i];
	}
	int sum = 0;bool flag = false;
	for (int i = 0;i < n - 1;i++) {
		int count = 0;
		if (!flag) {							//轮流读入两张图
			for (int j = 0;j < col*row;j++) {
				cin >> cur[j];
			}
			flag = true;
		}
		else {
			for (int j = 0;j < col*row;j++) {
				cin >> pre[j];
			}
			flag = false;
		}
		for (int j = 0;j < row*col;j++) {		//	统计差异
			if (pre[j] != cur[j]) {
				count++;
			}
		}
		if (count > sum) {
			sum = count;
		}
	}
	cout << sum << endl;
}