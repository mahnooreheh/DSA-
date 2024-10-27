#include<iostream>
using namespace std;
class maxheap {
private:
	int* arr;
	int heapsize; //no of elements in the heap array 
	int maxsize;
public:
	maxheap(int s) {
		this->maxsize = s;
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
	int getmax() {
		return arr[0]; 
	}
	int curSize() {
		return heapsize; 
	}
	void insertkey(int x) {
		if (heapsize == maxsize) {
			cout << "Heap is filled!"; 
			return;
		}
		int i = heapsize - 1; 
		arr[heapsize - 1] = x;
		heapsize++;
		while (i != 0 && arr[i] > arr[parent(i)]) {
			swap(arr[i], arr[parent(i)]);
			i = parent(i); 
		}
	}
	void increasekey(int x, int newval) {
		if (x < 0 || x>= maxsize) {
			cout << "Invalid index.";
			return;  
		}
		arr[x] = newval;
		while (x != 0 && arr[x] > arr[parent(x)]) {
			swap(arr[x], arr[parent(x)]);
			x = parent(x);  
		}
	}
	void maxheapify(int i) {
		int lchild = leftchild(i);
		int rchild = rightchild(i);
		int paren = parent(i); 
		int largest = i;
		if (lchild<heapsize && arr[lchild]>arr[largest]) {
			largest = lchild;  
		}
		if (rchild<heapsize && arr[rchild]>arr[largest]) {
			largest = rchild;  
		}
		if (largest != i) {
			swap(arr[i], arr[largest]); 
			maxheapify(largest); 
		}
	}
	int removemax() {
		if (heapsize == 0) {
			return 0 ;
		}
		if (heapsize == 1) {
			heapsize--; 
			return arr[0]; 
		}
		arr[0] = arr[heapsize - 1];
		heapsize--;
		maxheapify(0); 
	}
	void deletekey(int i) {
		if (heapsize == 0) {
			cout << "Heap is empty.";
			return; 
		}
		if (i <0 || i>heapsize) {
			cout << "Invalid index!";
			return; 
		}
		increasekey(i, INT_MAX);
		removemax(); 
	}
};
int main() {
	maxheap h(15);
	int k, i, n = 6, arr[10];
	cout << "Entered 6 keys:- 3, 10, 12, 8, 2, 14 \n";
	h.insertkey(3); 
	h.insertkey(10); 
	h.insertkey(12); 
	h.insertkey(8); 
	h.insertkey(2); 
	h.insertkey(14); 
	cout << "The current size of the heap is "<< h.curSize() << "\n";

	cout << "The current maximum element is " << h.getmax()<< "\n";

	h.deletekey(2); 
	cout << "The current size of the heap is "<< h.curSize() << "\n";

	h.insertkey(15); 
	h.insertkey(5); 
	cout << "The current size of the heap is "<< h.curSize() << "\n"; 
	cout << "The current maximum element is " << h.getmax() << "\n"; 
} 