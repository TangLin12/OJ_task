#include<iostream>

using namespace std;

typedef struct node {
	char date;
	node *lf, *rt;
}Node,*Tree;

void init(Tree &root) {
	char ch;cin >> ch;
	if (ch == '#')
		root = NULL;
	else {
		root = new Node;
		root->date = ch;
		init(root->lf);
		init(root->rt);
	}
}

Node* FindNode(Tree T, char n) {
	if (T == NULL) {
		return NULL;
	}
	else if (T->date == n) {
		return T;
	}
	else {
		Node* p;p = FindNode(T->lf, n);
		if (p != NULL) {
			return p;
		}
		else {
			return FindNode(T->rt, n);
		}
	}
}

int main()
{
	Tree tree;
	init(tree);
	char n;cin >> n;
	Node* T = FindNode(tree, n);
	if (T->lf == NULL) {
		cout << "L:#,";
	}
	else {
		cout << "L:" << T->lf->date << ",";
	}
	if (T->rt == NULL) {							//notice
		cout << "R:#";
	}
	else {
		cout << "R:" << T->rt->date;
	}
}