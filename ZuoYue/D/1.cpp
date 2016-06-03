#include<iostream>

using namespace std;

typedef struct Node {
	int loc;
	Node *next;
}Node;
Node node[1001], *head, *tmp;

int rec[1001];

bool test(int start, int end) {
	rec[start] = 1;
	if (start == end) {
		return true;
	}
	else {
		tmp = &node[start];
		while (tmp->next != NULL) {
			tmp = tmp->next;
			if (rec[tmp->loc] == 0) {
				if (test(tmp->loc, end))
					return true;
			}
		}
		return false;
	}
}

int main()
{
	int n;cin >> n;
	for (int i = 0;i < 1000;i++) {
		node[i].loc = i;
		node[i].next = NULL;
	}
	for (int i = 0;i < n;i++) {
		int num;cin >> num;
		for (int j = 1;j < num;j++) {
			int v;cin >> v;
			if (j == 1) {
				head = &node[v];
			}
			else {
				tmp = new Node;
				tmp->loc = v;tmp->next = NULL;
				head->next = tmp;head = tmp;
			}
		}
	}
	for (int i = 0;i < n;i++) {
		int x, y;cin >> x >> y;
		for (int j = 0;j < 1000;j++) {
			rec[j] = 0;
		}
		if (test(x, y)) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
}