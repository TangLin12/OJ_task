#include<iostream>

using namespace std;

int ar[1000];

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {							//����¼��
		cin >> ar[i];
	}
	int sum = 0;
	for (;n > 1;n--) {									//�����������ƣ�ÿ���ź�һ������Ҫ�����������
		int max = 0, idx = 0;
		for (int i = 0;i < n;i++) {						//�����
			if (ar[i] > max) {
				max = ar[i];idx = i;
			}
		}
		if (idx == 0) {									//���㷭һ�Σ�����ȥ��0��n-1����������
			sum++;
			for (int i = 0;i < n / 2;i++) {
				swap(ar[i], ar[n - 1 - i]);
			}
		}	
		else if (idx < n - 1) {							//��ȥǡ������ȷλ�ã��ײ㣩
			sum += 2;
			for (int i = 0;i < (idx + 1) / 2;i++) {		//���붥��
				swap(ar[i], ar[idx - i]);
			}
			for (int i = 0;i < n / 2;i++) {				//����ȥ
				swap(ar[i], ar[n - 1 - i]);
			}
		}
	}
	cout << sum << endl;
}