#include<iostream>

using namespace std;
#define SIZE 100
int main()
{
	int n;cin >> n;int ar[SIZE][SIZE];
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> ar[i][j];
		}
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (ar[i][j] == 1) {
				cout << j;
			}
		}
		cout << endl;
	}
}