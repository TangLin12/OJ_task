#include<iostream>
#include<string>
using namespace std;

int main()
{
	string x;long long y, z;
	while (cin >> x >> y >> z) {
		int len = x.length();
		long long power = 0, i = 0;
		while (i < len) {
			while (power < 99999999 && i < len) {
				power = power * 10 + (x[i++] - '0');
			}
			power %= z;
		}
		long long n = 1;
		while (y > 0) {
			if (y & 1)
				n = (n*power) % z;
			power = (power*power) % z;
			y = y >> 1;
		}
		cout << n << endl;
	}
}