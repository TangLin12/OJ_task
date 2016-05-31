#include<iostream>

using namespace std;

long long gcd(long long x, long long y) {
	if (y == 0) {
		return x;
	}
	return gcd(y, x%y);
}

void exgcd(long long a, long long b, long long &x, long long &y) {
	if (b == 0) {
		x = 1;y = 0;return;
	}
	exgcd(b, a%b, x, y);
	long long t = x;
	x = y;
	y = t - (a / b)*y;
	return;
}

int main()
{
	long long x, y, m, n, l;
	while (cin >> x >> y >> m >> n >> l) {
		long long a = n - m, b = l, c = x - y;
		long long p, q;
		long long d = gcd(a, b);
		if (c%d) {
			cout << "Impossible" << endl;
			continue;
		}
		a /= d, b /= d, c /= d;
		exgcd(a, b, p, q);
		p *= c;long long tmp = p%b;
		while (tmp < 0) {
			tmp += b;
		}
		cout << tmp << endl;
	}

}