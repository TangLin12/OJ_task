#include<iostream>

using namespace std;

int main()
{
	int l, h, x;
	while (cin >> l >> h >> x) {
		if (l == 0 && h == 0 && x == 0) {
			break;
		}
		int dis = l - h;
		if (dis < 0) {
			dis = 0;
		}
		int times = dis / (h - x);
		if (dis % (h - x) != 0) {
			times++;
		}
		cout << times + 1 << endl;
	}
}