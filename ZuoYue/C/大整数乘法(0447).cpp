#include<iostream>
#include<string>
using namespace std;

int str[300];

int main()
{
	int len;cin >> len;
	string s1, s2;cin >> s1 >> s2;
	int k;
	for (int i = len - 1;i >= 0;i--) {
		k = len - 1 - i;
		for (int j = len - 1;j >= 0;j--, k++) {
			str[k] += (s1[i] - '0')*(s2[j] - '0');
			if (str[k] > 9) {
				str[k + 1] += str[k] / 10;
				str[k] %= 10;
			}
		}
		if (str[k] > 9) {
			str[k + 1] += str[k] / 10;
			str[k] %= 10;
		}
	}
	bool flag = false;
	for (int i = k;i >= 0;i--) {
		if (!flag) {
			if (str[i] != 0) {
				cout << str[i];
				flag = true;
			}
		}
		else {
			cout << str[i];
		}
	}
	if (!flag) {
		cout << "0";
	}
	cout << endl;
	return 0;
}