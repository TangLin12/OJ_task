#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
string rec[202];

string Open = "sin(";
string Opens = "(";
string Close = ")";
string get_n(int n) {
	string ch = "";
	vector<char> tmp;
	while (n) {
		char a = '0' + n % 10;
		tmp.push_back(a);
		n /= 10;
	}
	for (int i = tmp.size() - 1;i >= 0;i--) {
		ch.push_back(tmp[i]);
	}
	return ch;
}

string f(int i,int limit) {
	if (i == limit) {
		return Open + get_n(i) + Close;
	}
	return Open + get_n(i)+"+"+ f(i+1,limit)+ Close;
}

string g(int i,int limit) {
	if (i == 1) {
		return rec[i] + "+" + get_n(limit);
	}
	return Opens + g(i - 1, limit) + Close + rec[i] + "+"+get_n(limit-i+1);
}

int main() {
	int n ;cin>>n;
	for (int i = 1;i <= n;i++) {
		rec[i] = f(1, i);
	}

	cout << g(n, n);
}
