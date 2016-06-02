#include<iostream>
#include<string>
using namespace std;

string str;

int main()
{
	int k;cin >> str >> k;
	int len = str.length();
	for (int i = 0;i < k;++i,--len) {
		for (int j = 0;j < len - 1;j++) {
			if (str[j] > str[j + 1]) {
				for (int c = j;c < len - 1;c++) {
					str[c] = str[c + 1];
				}
				break;
			}
		}
	}
	bool flag = false;
	for (int i = 0;i < len;++i) {
		if (!flag&&str[i] != '0') {
			cout << str[i];
			flag = true;
		}
		else if (flag) {
			cout << str[i];
		}
	}
	if (!flag) {
		cout << "0";
	}
	cout << endl;
}