#include<iostream>

using namespace std;
#define SIZE 2000
int dis[SIZE], oil[SIZE];


int main()
{
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		dis[0] = 500;oil[0] = 500;
		int i, k = 0;
		for (i = 1;dis[i - 1] <= n;i++,k++) {
			oil[i] = oil[0] + i * 500;
			dis[i] = dis[i - 1] + 500 / (2 * (i + 1) - 1);
		}
		for (int j = 1, i = k - 1;i >= 0;i--, j++) {
			cout << j << "  " << n - dis[i] << "  " << oil[i] << endl;
		}
	}
}