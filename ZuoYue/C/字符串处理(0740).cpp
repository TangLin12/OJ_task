#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main() {
	char s[200];
	int a[50];
	while (cin >> s) {
		int k = 0;
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
/*
����һ�����溬�������ַ����ַ���������С��200�������ڽ������������ַ���ɵ�����ת��Ϊ16���������
Sample Input
a123v456U17960?302tab5876


7B
1C8
4628
12E
16F4
*/