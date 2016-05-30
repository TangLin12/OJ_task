#include<iostream>
#include<string>
using namespace std;

int main()
{
	string origin;int n;cin >> origin >> n;
	int len1 = origin.length();
	while (n--) {
		string test;cin >> test;int len = test.length();
		for (int i = 0;i < len;i++) {
			int count = 0;
			for (int j = 0;j < len1;j++) {
				if (origin[j] != test[i + j]) {
					count++;
				}
				if (count >= 2) {
					break;
				}
			}
			if (count < 2) {
				cout << "YES" << endl;
				break;
			}
			else if (i == len - 1) {
				cout << "NO" << endl;
			}
		}
	}
}