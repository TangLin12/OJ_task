#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef struct peo {
	string id;
	string sum;
	int len;
}King;

King king[1000];

bool cmp(King a, King b) {
	if (a.sum == b.sum) {
		return a.id < b.id;
	}
	else if (a.len == b.len) {
		return a.sum > b.sum;
	}
	
	else {
		return a.len > b.len;
	}

}

int main()
{
	int n;cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> king[i].id >> king[i].sum;
		king[i].len = king[i].sum.length();
	}
	sort(king, king + n, cmp);
	for (int i = 0;i < n;i++) {
		cout << king[i].id << endl;
	}
	
}