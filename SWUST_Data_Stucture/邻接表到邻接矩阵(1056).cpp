#include<iostream>

using namespace std;
#define SIZE 100
int ar[SIZE][SIZE];
int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		int tmp;
		while (cin >> tmp) {
			ar[i][tmp] = 1;
			if (cin.get() == '\n')
				break;
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << ar[i][j];
		}
		cout << endl;
	}
}