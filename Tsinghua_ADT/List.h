typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template<typename T>
class ListNode {
public:
	//
	T data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;
	//
	ListNode() {}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
		:data(e), pred(p), succ(s) {}
	//
	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};


template<typename T>
class List {

private:
	int _size;
	ListNodePosi(T) header;
	ListNodePosi(T) trailer;

protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);
	void merge(ListNodePosi(T)&, int, List<T>&, int);
	void mergeSort(ListNodePosi(T)&, int);
	void selectionSort(ListNodePosi(T), int);
	void insertionSort(ListNodePosi(T), int);

public:
//
	List() { init(); }
	List(List<T> const& L);
	List(List<T> const& L, Rank r, int n);
//
	~List();
//
	Rank size() const { return _size; }
	bool empty() const { return _size <= 0; }
	ListNodePosi(T) operator[](int r) const;
	ListNodePosi(T) first() const { return header->succ; }
	ListNodePosi(T) last() const { return trailer->pred; }
	bool valid(ListNodePosi(T) p){
		return p && (trailer != p) && (header != p);
	}
};
