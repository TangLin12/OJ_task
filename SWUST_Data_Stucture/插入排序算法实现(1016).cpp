#include<iostream>

using namespace std;
int n;int ar[1000];
/*
��ʼʱ��a[0]�Գ�1����������������Ϊa[1..n-1]����i=1

2.      ��a[i]���뵱ǰ��������a[0��i-1]���γ�a[0��i]���������䡣

3.      i++���ظ��ڶ���ֱ��i==n-1��������ɡ�
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
