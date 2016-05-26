#include<iostream>
#include<string>
using namespace std;

int dfs(int m, int n, int k) {
	if (n == 0)
		return m == k;
	int sum = 0;
	if (m != 1)
		sum += dfs(m - 1, n - 1, k);
	if (m != 100)
		sum += dfs(m + 1, n - 1, k);
	return sum;
}

int main() {
	int m,n,k;
	while (cin >> m >> n >> k) {
		cout << dfs(m, n, k)<<endl;
	}
}