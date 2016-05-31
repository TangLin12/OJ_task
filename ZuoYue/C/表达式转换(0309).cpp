#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
	int n;cin >> n;
	while (n--) {
		string s;cin >> s;int len = s.length();
		stack<char> tmp;
		for (int i = 0;i < len;i++) {
			if (s[i] == '(') {
				tmp.push(s[i]);
			}
			else if (s[i] >= 'a'&&s[i] <= 'z') {
				cout << s[i];
			}
			else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^') {
				tmp.push(s[i]);
			}
			else if (s[i] == ')') {
				while (tmp.top() != '(') {
					cout << tmp.top();tmp.pop();
				}
				tmp.pop();
			}
		}
		cout << endl;
	}
}