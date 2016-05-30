#include<iostream>

using namespace std;
#define SIZE 10000
int main()
{
	int n, k;cin >> n >> k;
	int left = 0, right = 0, ar[SIZE];
	for (int i = 0;i < n;i++) {
		cin >> ar[i];
		if (right < ar[i]) {
			right = ar[i];
		}
	}
	right++;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		int num = 0;
		for (int i = 0;i < n;i++) {
			if (num >= k) {
				break;
			}
			num += ar[i] / mid;
		}
		if (num >= k) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	cout << left << endl;
}