#include<iostream>

using namespace std;

int ar[100][100];

int main()
{
	int n;cin >> n;int s, e;cin >> s >> e;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> ar[i][j];
		}
	}
	ar[s][e] == 1 ? cout << "yes" : cout << "no";
}