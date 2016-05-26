#include<iostream>
#include<string>
using namespace std;

bool judge(int n) {
	int a = 1, b = 1000;
	for (int i = 0;i < n;i++) {
		int k;cin >> k;string s;cin >> s;
		if (s == "small") {
			a = k;
		}
		else if (s == "big") {
			b = k;
		}
		else {
			return (k >= a&&k <= b);
		}
	}
}

int main() {
	int n;
	while (cin >> n) {
		bool ans, pre = judge(n);string s;cin >> s;
		if (s == "true")
			ans = true;
		else
			ans = false;
		if (pre == ans) {
			cout << "22" << endl;
		}
		else {
			cout << "11" << endl;
		}

	}
}