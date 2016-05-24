#pragma once
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height:-1)
typedef enum { RB_RED, RB_BLACK }RColor;

template<typename T>
class BinNode {
public:
	T date;
	BinNodePosi(T) parent;
	BinNodePosi(T) lchild;
	BinNodePosi(T) rchild;
	int height;
	int npl;//NULL Path Lenght
	RColor color;
	//
	BinNode() :
		parent(NULL), lchild(NULL), rchild(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(
		T e,
		BinNodePosi(T) p=NULL,BinNodePosi(T) lc=NULL,BinNodePosi(T) rc=NULL,
		int h=0,inr l=1,RBColor c=RB_RED)
		:data(e),parent(p),lchild(lc),rchild(rc),height(h),npl(l),color(c){ }
	//


};