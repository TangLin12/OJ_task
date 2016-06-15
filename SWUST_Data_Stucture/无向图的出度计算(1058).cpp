#include<iostream>

using namespace std;

int ar[100];

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		int ans = 0;
		for (int j = 0;j < n;j++) {
			int tmp;cin >> tmp;
			tmp == 1 ? ans++ : 1;
		}
		cout << ans << endl;
	}
}