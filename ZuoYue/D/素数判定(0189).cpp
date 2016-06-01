#include<iostream>

using namespace std;

bool is_prime(int n) {
	for (int i = 2;i < n;i++) {
		if ((n%i) == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int a, b;
	while (cin >> a >> b) {
		if (a > b) {
			swap(a, b);
		}
		int count;
		for (count = 0;a < b;a++) {
			if (is_prime(a)) {
				count++;
			}
		}
		cout << count << endl;
	}
}