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

Node* Parent(Tree T, char ch) {
	if (T == NULL) {
		return NULL;
	}
	if (T->lf != NULL&&T->lf->date == ch || T->rt != NULL&&T->rt->date == ch) {
		return T;
	}
	Node* p = Parent(T->lf, ch);
	if (p != NULL) {
		return p;
	}
	else {
		return Parent(T->rt, ch);
	}
}

int main()
{
	Tree tree;
	init(tree);
	char n;cin >> n;
	Node *p = Parent(tree, n);
	if (p != NULL) {
		cout << p->date;
	}
	else {
		cout << "#";
	}
}