#include<iostream>

using namespace std;

int ar[1000];

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {							//数据录入
		cin >> ar[i];
	}
	int sum = 0;
	for (;n > 1;n--) {									//排序总数控制，每次排好一个后需要排序区域减少
		int max = 0, idx = 0;
		for (int i = 0;i < n;i++) {						//找最大
			if (ar[i] > max) {
				max = ar[i];idx = i;
			}
		}
		if (idx == 0) {									//顶层翻一次，翻下去，0与n-1换。。。。
			sum++;
			for (int i = 0;i < n / 2;i++) {
				swap(ar[i], ar[n - 1 - i]);
			}
		}	
		else if (idx < n - 1) {							//除去恰好在正确位置（底层）
			sum += 2;
			for (int i = 0;i < (idx + 1) / 2;i++) {		//翻与顶层
				swap(ar[i], ar[idx - i]);
			}
			for (int i = 0;i < n / 2;i++) {				//翻下去
				swap(ar[i], ar[n - 1 - i]);
			}
		}
	}
	cout << sum << endl;
}