/*
	求Sn=1!+2!+3!+4!+5!+…+n!之值，其中n是一个数字。
	输出Sn，Sn可能超出int范围，n（n<=20）
	用long long 即可
*/

#include<iostream>

using namespace std;

long long int fun(long long int n) {
	if (n == 1)
		return 1;
	else
		return n*fun(n - 1);
}

long long int sum(long long int n) {
	if (n == 1)
		return 1;
	else
		return sum(n - 1) + fun(n);
}


int main()
{
	long long int n;
	cin >> n;
	cout << sum(n) << endl;
}