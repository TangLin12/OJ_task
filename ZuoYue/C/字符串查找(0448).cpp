#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

char a[120], b[4500];

void input(char *x) {
	char tmp;int i = 0;
	while (tmp = getchar()) {
		if (tmp != '\n') {
			x[i++] = tmp;
		}
		else {
			x[i] = '\0';return;
		}
	}
}

int main()
{
	char *m;
	input(a);input(b);
	m = strstr(b, a);
	cout << m - b + 1 << endl;
}