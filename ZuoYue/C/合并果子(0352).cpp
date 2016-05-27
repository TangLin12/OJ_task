#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		priority_queue<int, vector<int>, greater<int> > q;
		for (int i = 0;i < n;i++) {
			int t;cin >> t;q.push(t);
		}
		int sum = 0;
		for (int i = 0;i < n - 1;i++) {
			int guo1 = q.top();q.pop();
			int guo2 = q.top();q.pop();
			int tmp = guo1 + guo2;sum += tmp;
			q.push(tmp);
		}
		cout << sum << endl;
	}
}
