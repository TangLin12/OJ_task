#include<iostream>
#include<queue>
 
using namespace std;
 
typedef struct BiTNode
{
    char data;
    BiTNode *lchild, *rchild;
}BiTNode, *BiTree;//BinTree is BinNode*
 
 
void CreateBiTree(BiTree &T)
{
    char ch;
    cin >> ch;
    if (ch == '#')
        T = NULL;
    else
    {
        T = new BiTNode;
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
 
void Bfs(BiTree &root) {
    if (root == NULL)
        return ;
    int i = 1;
    queue<BiTree> bfs;
    bfs.push(root);
    while (bfs.size() != 0) {
        BiTree q;
        q = bfs.front();
        cout << q->data;
        if (q->lchild != NULL)
            bfs.push(q->lchild);
        if (q->rchild != NULL)
            bfs.push(q->rchild);
        bfs.pop();
    }
}
 
void solve() {
    BiTree T = NULL;
    CreateBiTree(T);
    Bfs(T);
}
 
int main(void)
{
    solve();
 
}