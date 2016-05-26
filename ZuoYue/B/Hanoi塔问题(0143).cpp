#include<iostream>

using namespace std;
int cou = 0;
void move(char a, char b, char c, int n) {
	if (n == 0) {
		return;
	}
	move(a, c, b, n - 1);
	cout << a << "-->" << c<<"   ";
	cou++;
	if (cou == 5) {
		cout << endl;
		cou= 0;
	}
	move(b, a, c, n - 1);
}

int main()
{
	int n;
	while (cin >> n) {
		if (n == 0)
			break;
		cou = 0;
		move('A', 'B', 'C', n);
		cout << endl;
	}
}