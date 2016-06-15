#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n;cin >> n;
	vector<int> ar(n);
	for (int i = 0;i < n;i++) {
		cin >> ar[i];
	}
	int tag;cin >> tag;
	int low = 0, high = n - 1, mid, count = 0, rec = -1;
	while (low <= high) {
		++count;mid = (low + high) / 2;
		if (ar[mid] < tag) {
			low = mid + 1;
		}
		else if (ar[mid]>tag) {
			high = mid - 1;
		}
		else {
			rec = mid;break;
		}
	}
	cout << rec << endl << count;
}