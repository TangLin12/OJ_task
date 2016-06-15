#include<iostream>

using namespace std;
int rec[100];
int main()
{
	int n;cin >> n;int count = 0;int max = 0;
	for (int i = 0;i < n;i++) {
		int ans = 0;
		for (int j = 0;j < n;j++) {
			int tmp;cin >> tmp;
			tmp == 1 ? ++ans : 1;
		}
		if (ans > max) {
			max = ans;count = 0;rec[count++] = i;
		}
		else if (ans == max) {
			rec[count++] = i;
		}
	}
	cout << max << endl;
	for (int i = 0;i < count;i++) {
		cout << rec[i];
	}
}