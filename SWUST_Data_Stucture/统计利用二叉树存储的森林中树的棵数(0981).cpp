#include<iostream>

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
int sum = 1;
void find(BTree &root) {
	if (root->rc != NULL) {
		sum++;
		find(root->rc);
	}
}

void solve() {
	BTree root = NULL;
	create(root);
	find(root);
	cout << sum;
}

int main()
{
	solve();
}