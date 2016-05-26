#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main() {
	char s[200];
	int a[50];
	while (cin >> s) {
		int k=0;
		for (int i = 0;s[i] != '\0';i++) {
			if (s[i] >= '0'&&s[i] <= '9') {
				a[k] = s[i++] - '0';
				while (s[i] >= '0'&&s[i] <= '9') {
					a[k] = a[k] * 10 + (s[i++] - '0');
				}printf("%X\n", a[k]);;
			}
		}

		memset(s, '\0', sizeof(s));
	}
}