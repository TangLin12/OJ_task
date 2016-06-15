#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 1000

void order(char *prev, char *mid, int len) {
	if (len <= 0)
		return;
	char ch = *prev;int i = 0;
	for (;i<len;i++) {
		if (mid[i] == *prev)
			break;
	}
	order(prev + 1, mid, i);
	order(prev + i + 1, mid + i + 1, len - i - 1);
	cout << ch;
}

int main()
{
	char a[SIZE], b[SIZE];
	cin >> a >> b;
	order(b, a, strlen(a));
	return 0;
}