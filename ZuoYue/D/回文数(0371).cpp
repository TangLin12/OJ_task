#include<iostream>

using namespace std;

int main()
{
	int n;
	while (cin >> n) {
		long long count = 0;
		while (n > 2 * count) {				//��λ��
			count = count * 10 + 9;
		}
		if (n > count + count / 10) {		//λ��Ϊż
			n -= count;						//�õ��ڼ�λ��
			cout << n;
			while (n > 0) {
				cout << n % 10;
				n /= 10;
			}
		}
		else {								//λ��Ϊ����
			n -= count / 10;				//ȥ����ӵĲ���
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

