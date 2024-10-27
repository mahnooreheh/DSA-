#include<iostream>
using namespace std;
class minheap {
private:
	int* arr;
	int heapsize;
	int maxsize;
public:
	minheap(int s) {
		maxsize = s;
		arr = new int[maxsize];
		heapsize = 0; 
	}
	int parent(int i) {
		return (i - 1) / 2;
	}
	int leftchild(int i) {
		return (2 * i + 1);
	}
	int rightchild(int i) {
		return (2 * i + 2); 
	}
	int getmin() {
		if (heapsize == 0) {
			return 0; 
		}
		return arr[0]; 
	}
	int cursize() {
		return heapsize; 
	}
	void insertkey(int x) {
		if (heapsize == maxsize) {
			cout << "Heap is full.";
			return; 
		}
		heapsize++;  
		int i = heapsize - 1;
		arr[i] = x;
		while (i != 0 && arr[parent(i)] > arr[i]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i); 
		}
	}
	void decreasekey(int x, int newval) {
		if (heapsize == 0 || x<0 ||x>=heapsize) {
			cout << "invalid syntax or heap is empty!";
		}
		arr[x] = newval;
		while (x != 0 && arr[parent(x)] > arr[x]) {
			swap(arr[x], arr[parent(x)]);
			x = parent(x); 
		}
	}
	void minheapify(int i) {
		int lchild = leftchild(i);
		int rchild = rightchild(i); 
		int paren = parent(i); 
		int smallest = i;
		if (lchild < heapsize && lchild < arr[smallest]) {
			smallest = lchild;  
		}
		if (rchild < heapsize && rchild < arr[smallest]) {
			smallest = rchild;
		}
		if (i != smallest) {
			swap(arr[i], arr[smallest]);
			minheapify(smallest); 
		}
	}
	int removemin() {
		if (heapsize == 0) {
			cout << "Heap is empty!";
			return 0; 
		}
		if (heapsize == 1) {
			heapsize--;
			return arr[0]; 
		}
		int root = arr[0]; 
		arr[0] = arr[heapsize - 1];
		heapsize--;
		minheapify(0); 
		return root; 
	}
	void removekey(int i) {
		if (heapsize == 0 || i < 0 || i >= heapsize) {
			cout << "Invalid index or empty heap.";
			return; 
		}
		decreasekey(i, INT_MIN);
		removemin(); 
	}
};
int main() {
	minheap h(11);
	h.insertkey(3);
	h.insertkey(2);
	h.removekey(1); 
	h.insertkey(15);
	h.insertkey(5);
	h.insertkey(4);
	h.insertkey(45);
	cout << h.removemin() << " ";
	cout << h.getmin() << " ";
	h.decreasekey(2, 1); 
	cout << h.getmin(); 
}