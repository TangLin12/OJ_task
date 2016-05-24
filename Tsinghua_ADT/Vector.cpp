#include"Vector.h"

template <typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];_size = 0;
	while (lo < hi) {
		_elem[_size++] = A[lo++];
	}
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V) {
	if (_elem) {
		delete [] _elem;
	}
	copyFrom(V._elem, 0, V.size());
	return *this;
}
template<typename T>
void Vector<T>::expand(){
	if (_size < _capacity)
		return;
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;
	T* oldElem = _elem;_elem = new T[_capacity <<= 1];
	for (int i = 0;i < _size;i++)
		_elem[i] = oldElem[i];
	delete[] oldElem;
}
template<typename T>
void Vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY<<1)
		return;
	if(_size<<2>_capa4)
}
template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {
	for (;lo < hi;lo++) {
		if (A[lo]>A[lo + 1]) {
			int tmp;
			tmp = A[lo];
			A[lo] = A[lo+1];
			A[lo + 1] = tmp;
		}
	}
	return true;
}
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {
	for (;lo < hi;lo++) {
		bubble(lo, hi);
	}
}

template <typename T>
T& Vector<T>::operator[](Rank r) const {
	return _elem[r];
}

template<typename T>
void swap(T& n1,T& n2) {
	T temp;temp = n1;n1 = n2;n2 = temp;
}

template<typename T>
void Vector<T>::unsort(Rank lo, Rank hi) {
	T* V = _elem + lo;
	for (Rank i = hi - lo;i > 0;i--) {
		swap(V[i - 1], V[rand() % i]);
	}
}

template<typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (_elem[hi] != e));
	return hi;
}

template<typename T>
Rank Vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size;i > r;i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	_size++;
	return r;
}

template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < _size)
		_elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;
}

template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template<typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		Rank j = find(_elem[i], 0, i);
		(0 > j) ? i++ : remove(j);
	}
}

template<typename T>
void Vector<T>::traverse(void(*visit)(T&)) {
	for (int i = 0;i < _size;i++)
		visit(_elem[i]);
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST& visit) {
	for (int i;i < _size;i++)
		visit(_elem[i]);
}

template<typename T>
int Vector<T>::disordered() const {
	int n = 0;
	for (inr i = 1;i < _size;i++)
		if (_elem[i - 1]>_elem[i])
			n++;
	return n;
}

template<typename T>
int Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size)
		if (_elem[i] != _elem[j])
			_elem[++i] = _elem[j];
	_size = ++i;shrink();
	return j - i;
}

template<typename T>
static Rank binSearchA(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		if (e < A[mi])
			hi = mi;
		else if (A[mi] < e)
			lo = mi + 1;
		else
			return mi;
	}
	return -1;
}

template<typename T>
static Rank binSearchB(T* A, T const& e, Rank lo, Rank hi) {
	while (1 < hi - lo) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi;
	}
	return (e == A[lo]) ? lo : -1;
}
template<typename T>
static Rank binSearchC(T* A, T const& e, Rank lo, Rank hi) {
	while (lo < hi) {
		Rank mi = (lo + hi) >> 1;
		(e < A[mi]) ? hi = mi : lo = mi + 1;
	}
	return --lo;
}

template<typename T>
static Rank fibSearch(T* A, T const e, Rank lo, Rank hi) {
	;//
}

template<typename T>
Rank Vector<T>::search(T const & e, Rank lo, Rank hi) const {
	if (rand() % 4) {
		;//
	}
}

template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T *A = _elem + lo;
	int lb = mi - lo;T* B = newT[lb];
	for (Rank i = 0;i < lb;B[i] = A[i++]);
	int lc = hi - mi;T* C = _elem + mi;
	Rank i, j, k;i = j = k = 0;
	while ((j < lb) && (k < lc)) {
		while ((j < lb) && B[j] <= C[k])
			A[i++] = B[j++];
		while ((k < lc) && C[k] <= B[j])
			A[i++] = C[k++];
	}
	whlie(j < lb)
		A[i++] = B[j++];
	delete[] B;
}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2)
		return;
	int mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}
int main() {
	Vector<int> V;
}
template<typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
	switch (rand() % 4) {
		case 1;bubbleSort(lo, hi);break;
		case 2:mergeSort(lo, hi);break;
		case 3:/*heapSort;*/break;
		default:quickSort(hi, lo);break;
	}
}