#include<iostream>
#include<stdlib.h>
using namespace std;

int num[20000];

int cmp(const void* a, const void* b) {
	return *((int*)a) - *((int *)b);
}

int main()
{
	int n;
	while (cin >> n) {
		int sum = 0;
		for (int i = 0;i < n;i++) {
			cin >> num[i];
		}
		qsort(num, n, sizeof(int), cmp);
		for (int i = 1;i < n;i++) {
			sum += (num[i] - num[i - 1])*i*(n - i);
		}
		cout << sum << endl;
	}
}