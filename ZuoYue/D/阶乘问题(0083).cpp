#include<iostream>

using namespace std;

int main()
{
	int n;int r[] = { 6,2,4,8 };
	cin >> n;int tmp = n;
	int rec;
	for (rec = 0;tmp;tmp /= 5) {
		rec += (tmp % 5 == 2) + (tmp % 5 == 4) * 2 + tmp / 5;//tmp%5==2||4�Ǽ���%10=%5%2��Ϊ2������
	}
	cout << ((n > 1) ? r[rec % 4] : 1 )<< endl;
}