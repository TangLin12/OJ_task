#include<iostream>

using namespace std;

int main()
{
	long n;
	while (cin >> n) {
		long tmp = 0, sum = 0;
		while (n != 1) {
			if (n % 2 == 0) {		//odd
				tmp = n*(n / 2) / 2;
				sum += tmp;
				n /= 2;
			}
			else {
				tmp = (n + 1)*(n + 1) / 4;
				sum += tmp;
				n = (n - 1) / 2;
			}
		}
		cout << sum + 1 << endl;
	}
}