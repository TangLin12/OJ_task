#include<iostream>
#include<string>
using namespace std;
#define SIZE 15
typedef struct Rich {
	string name;
	float money;
}Rich;

Rich peo[SIZE], now;

int main()
{
	int n, k;int count = 0;
	while (cin >> n >> k) {
		if (count) {								//����λ����ֱ����r(�s���t)�q
			cout << endl;
		}
		for (int i = 0;i < SIZE;i++) {
			peo[i].money = -1;
		}
		for (int i = 0;i < n;i++) {
			cin >> now.name >> now.money;
			for (int j = 0;j < SIZE;j++) {			//ֻ��¼������
				if (now.money > peo[j].money) {
					swap(now, peo[j]);
				}
			}
		}
		for (int i = 0;i < k;i++) {
			cout << peo[i].name << " " << peo[i].money << endl;
		}
		++count;
	}
	return 0;
}