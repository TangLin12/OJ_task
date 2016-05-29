#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool pre(char top, char now) {
	if (top == '\0') {
		return true;
	}
	if (top == '{') {
		return true;
	}
	else {
		if (top == '[') {
			if (now != '{')
				return true;
			else
				return false;
		}
		else if (top == '(') {
			if (now == '(' || now == '<')
				return true;
			else
				return false;
		}
		else {
			if (now == '<')
				return true;
			else
				return false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		string s;cin >> s;int len = s.length();
		stack<char> l;l.push('\0');bool judge = true;
		for (int j = 0;j < len;j++) {
			if (s[j] == '<' || s[j] == '(' || s[j] == '[' || s[j] == '{') {
				if (pre(l.top(), s[j])) {
					l.push(s[j]);
				}
				else {
					judge = false;break;
				}
			}
			else {
				switch (s[j]) {
				case '>':s[j] = '<';break;
				case '}':s[j] = '{';break;
				case ']':s[j] = '[';break;
				case ')':s[j] = '(';break;
				}
				if (s[j] == l.top()) {
					l.pop();
				}
				else {
					judge = false;break;
				}
			}
		}
		if (l.top() != '\0')
			judge = false;
		if (judge)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
}