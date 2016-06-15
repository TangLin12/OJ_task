#include<iostream>
#include<queue>
using namespace std;

typedef struct node {
	char date;
	node* lc;
	node* rc;
}Node, *BTree;

void create(BTree &root) {
	char ch;cin >> ch;
	if (ch == '#')
		root = NULL;
	else {
		root = new Node;
		root->date = ch;
		create(root->lc);
		create(root->rc);
	}
}

bool judge(BTree root) {
	queue<BTree> q;
	if (root != NULL) {
		q.push(root);
		BTree cur = NULL;
		bool flag = false;
		while (!q.empty()) {
			cur = q.front();q.pop();
			if (cur) {
				if (flag)
					return false;
				q.push(cur->lc);
				q.push(cur->rc);
			}
			else {
				flag = true;
			}
		}
		return true;
	}
	return true;
}

void solve() {
	BTree root = NULL;
	create(root);
	if (judge(root))
		cout << "Y";
	else
		cout << "N";
}

int main()
{
	solve();
}