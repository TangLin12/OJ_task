#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int A[9];int a, b, c;
	for (int i = 0;i < 9;i++) {
		A[i] = i + 1;
	}
	for (int i = 0;i < 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1;i++) {
		if (next_permutation(A, A + 9)) {
			a = A[0] * 100 + A[1] * 10 + A[2];
			b = A[3] * 100 + A[4] * 10 + A[5];
			c = A[6] * 100 + A[7] * 10 + A[8];
			if (a + b == c&&b>a) {
				cout << a << " " << b << " " << c << endl;
			}
		}
	}
}