#include<iostream>

using namespace std;
int rec[100];
int main()
{
	int n;cin >> n;int count = 0;int k;cin >> k;
	for (int i = 0;i < n;i++) {
		int ans = 0;
		for (int j = 0;j < n;j++) {
			int tmp;cin >> tmp;
			tmp == 1 ? ++ans : 1;
		}
		if (ans == k) {
			rec[count++] = i;
		}
	}
	cout << count << endl;
	for (int i = 0;i < count;i++) {
		cout << rec[i];
	}
}