/*
	��ע���������У����ĳ����С�����ĸ���ʱ���ų�֮ǰ���ֹ�������
	�����ӣ�
	Sample Input

	8
	2 6 4 5 8 1 7 3

	Sample Output

	8227
	2 6 4 5 8 3 1 7
	tot=0��

	��2С������1������ tot+=1*7����

	��6С������4������ tot+=4*6����

	��4С������2������ tot+=2*5����

	��5С������2������ tot+=2*4����

	��8С������3������ tot+=3*3����

	��1С������0������ tot+=0*2����

	��7С������1������ tot+=1*1����

	��3С����û�У�

*/
#include<iostream>
#include<algorithm>

using namespace std;

int permutations(int n) {			//compute n!
	int count = 1;
	for (int i = 1;i <= n;i++) {	//from 1 to n include n
		count *= i;
	}
	return count;
}
int ar[1000];
int main() {
	int n;cin >> n;
	for (int i = 0;i < n;i++) {		//stdin	
		cin >> ar[i];
	}
	int sum=0;
	for (int i = 0;i < n - 1;i++) {	//compute sum
		int count = 0;
		for (int j = i + 1;j < n;j++) {		//how many number is low,and it at the back of ar[i]
			if (ar[j] < ar[i])
				count++;
		}
		sum += count*permutations(n - i - 1);
	}
	cout << sum << endl;
	if (next_permutation(ar, ar + n)) {
		for (int i = 0;i < n;i++) {
			cout << ar[i] << " ";
		}
		cout << endl;
	}
}