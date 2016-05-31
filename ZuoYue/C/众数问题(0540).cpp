#include<iostream>
#include<algorithm>
using namespace std;
#define SIZE 10000000
int ar[SIZE];
int find_most(int *a, int n, int &rec) {
	int count = 1, most = 1;int elem;
	for (int i = 0;i < n - 1;i++, count = 1) {
		while (a[i] == a[i + 1]) {
			count++;i++;
		}
		if (count > most) {
			most = count;elem = a[i];
		}
	}
	rec = most;
	return elem;
}

int main() {
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> ar[i];
	}
	sort(ar, ar + n);
	int rec = 1;
	int most = find_most(ar, n, rec);
	cout << most << endl << rec << endl;
}