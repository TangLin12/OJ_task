#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string Find[500];


int main()
{
	int n;cin >> n;
	string exa;cin >> exa;int len = exa.length();
	char *op = &exa[0];
	sort(op, op + len);
	int count = 0;
	for (int i = 0;i < n;i++) {
		string tmp1, tmp2;cin >> tmp1;
		tmp2 = tmp1;
		char *op = &tmp2[0];int len1 = tmp2.length();
		sort(op, op + len1);
		if (exa == tmp2) {
			Find[count++] = tmp1;
		}
	}
	string *op1 = &Find[0];
	sort(op1, op1 + count);
	for (int i = 0;i < count;i++) {
		cout << Find[i] << endl;
	}
	cout << count << endl;
}