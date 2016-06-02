#include<iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		long long count = 0;
		while (n > 2 * count) {				//算位数
			count = count * 10 + 9;
		}
		if (n > count + count / 10) {		//位数为偶
			n -= count;						//得到第几位数
			cout << n;
			while (n > 0) {
				cout << n % 10;
				n /= 10;
			}
		}
		else {								//位数为奇数
			n -= count / 10;				//去掉多加的部分
			cout << n;
			n /= 10;
			while (n > 0) {
				cout << n % 10;
				n /= 10;
			}
		}
		cout << endl;
	}
}

