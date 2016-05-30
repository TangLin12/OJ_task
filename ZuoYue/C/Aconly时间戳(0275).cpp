#include<iostream>

using namespace std;

long a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

void print(long n,char c) {
	if (n / 10 == 0) {
		cout << "0" << n << c;
	}
	else {
		cout << n << c;
	}
}

int main()
{
	long num;
	while (cin >> num) {
		long miao = num % 60;
		num -= miao;
		long day = num / (3600 * 24);
		num -= day * 3600 * 24;
		long hour = num / 3600;
		num -= hour * 3600;
		long min = num / 60;
		day++;
		long tian = day;
		int i = 1, month = 0;
		while (day > 0) {
			tian = day;
			day -= a[i];
			i++;month++;
		}
		cout << "2009-";
		print(month, '-');print(tian, ' ');print(hour, ':');
		print(min, ':');print(miao, '\n');
	}
}