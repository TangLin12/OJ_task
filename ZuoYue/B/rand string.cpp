#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const char a[25] = { "0123456789sgafbvxbxjxvbs" };



int main() {
	while(1) {
		int x = rand() % 100;char s[200];
		int i;
		for (i = 0;i < x;i++) {
			int n = rand() % 24;
			s[i] = a[n];
		}s[i] = '\0';
		cout << s<<endl;

	}
}