#include <iostream>
#include<stack>

using namespace std;

int main(int argc, char const *argv[]) {
	int a, b;
	while (cin >> a >> b) {
		stack<char> ans;
		int c = a + b;
    if(c==0){                                     //0的情况
      cout<<"0"<<endl;
      continue;
    }
		bool sign = false;                            //符号
		(c < 0) ? (sign = true, c = -c) : 1;
		int counter = 0;
		while (c) {
			if (counter == 3) {
				ans.push(',');
			}
			ans.push(c%10+'0');
			c /= 10;
			counter++;
		}
		if (sign) {
			cout << "-";
		}
		while (!ans.empty()) {
			cout << ans.top();
			ans.pop();
		}
		cout << endl;
	}
	return 0;
}
