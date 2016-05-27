/*
	（注：在排列中，求比某个数小的数的个数时，排除之前出现过的数）
	看例子：
	Sample Input

	8
	2 6 4 5 8 1 7 3

	Sample Output

	8227
	2 6 4 5 8 3 1 7
	tot=0；

	比2小的数有1个，则 tot+=1*7！；

	比6小的数有4个，则 tot+=4*6！；

	比4小的数有2个，则 tot+=2*5！；

	比5小的数有2个，则 tot+=2*4！；

	比8小的数有3个，则 tot+=3*3！；

	比1小的数有0个，则 tot+=0*2！；

	比7小的数有1个，则 tot+=1*1！；

	比3小的数没有；

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