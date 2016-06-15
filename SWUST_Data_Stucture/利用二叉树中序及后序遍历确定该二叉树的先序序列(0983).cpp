#include<iostream>
#include<string.h>
using namespace std;

#define SIZE 1000

void order(const char *prev, const char *mid, int len) {
	if (len <= 0)
		return;
	char ch = prev[len - 1];int i = 0;
	for (;i<len;i++) {
		if (mid[i] == ch)
			break;
	}
	cout << ch;
	order(prev, mid, i);
	order(prev + i, mid + i + 1, len - i - 1);
}

int main()
{
	char a[SIZE], b[SIZE];
	cin >> a >> b;
	order(b, a, strlen(a));
	return 0;
}