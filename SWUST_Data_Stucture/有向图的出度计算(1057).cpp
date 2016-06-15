#include<iostream>

using namespace std;

typedef struct node {
	int v;
	node *next;
	node() :v(-1), next(NULL) {}
}node;

node ver[100];

int main()
{
	int n, e;cin >> n >> e;
	for (int i = 0;i < e;i++) {
		int start, to;cin >> start >> to;
		node* tmp = &ver[start];
		while (tmp->v != -1) {
			tmp = tmp->next;
		}
		tmp->next = new node;
		tmp->v = to;
	}
	for (int i = 0;i < n;i++) {
		int ans = 0;
		node *p = &ver[i];
		while (p->v != -1) {
			++ans;p = p->next;
		}
		cout << ans << endl;
	}
}