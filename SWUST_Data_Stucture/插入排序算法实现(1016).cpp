#include<iostream>

using namespace std;
int n;int ar[1000];
/*
初始时，a[0]自成1个有序区，无序区为a[1..n-1]。令i=1

2.      将a[i]并入当前的有序区a[0…i-1]中形成a[0…i]的有序区间。

3.      i++并重复第二步直到i==n-1。排序完成。
*/
void sort_once(int j) {
	for (int i = 0;i<j;i++) {
		if (ar[j]<ar[i]) {
			int t = ar[j];
			for (int k = j;k>i;k--) {
				ar[k] = ar[k - 1];
			}
			ar[i] = t;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0;i<n;i++) {
		cin >> ar[i];
	}
	sort_once(1);
	for (int i = 0;i<n;i++) {
		cout << ar[i] << " ";
	}
}
