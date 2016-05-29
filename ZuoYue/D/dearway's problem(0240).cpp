#include<iostream>

using namespace std;

#define MOD 100000

int main() {
	int n, k;
	while (cin >> n >> k) {
		int  ans = 1;
		if (n > 10001)
			break;
		for (int i = n;i > 1;i--) {
			ans *= i;
			while (ans % 10 == 0) {
				ans /= 10;
			}
			if (ans >= MOD) {
				ans %= MOD;
			}
		}
		for (int i = 1;i < k;i++) {
			ans /= 10;
		}
		ans %= 10;
		cout << ans << endl;
	}
}