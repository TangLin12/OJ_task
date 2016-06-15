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

void degree(Node *T) {
	if (T->rt != NULL) {
		cout << "ERROR" ;					//no endl
	}
	else {
		T = T->lf;
		int i = 0;
		while (T != NULL) {
			i++;
			T = T->rt;
		}
		cout << i;
	}
}

int main()
{
	Tree tree;
	init(tree);
	degree(tree);
}