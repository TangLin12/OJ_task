#include<iostream>

using namespace std;

int ar[100];

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> ar[i];
	}
	for (int i = 0;i < n - 1;i++) {
		if (ar[i] > ar[i + 1])
			swap(ar[i], ar[i + 1]);
	}
	for (int i = 0;i < n;i++) {
		cout << ar[i] << " ";
	}
}