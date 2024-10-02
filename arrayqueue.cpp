#include<iostream>
using namespace std;
template<typename t>
class queue {
private:
	t* arr; 
	int front, back, size, capacity;
public:
	queue(int siz) {
		this->size = siz;
		arr = new t[size];
		capacity = 0;
		front = 0;
		back = -1;
	}
	bool isfull() {
		return size == capacity;
	}
	bool isempty() {
		return capacity == 0;
	}
	void enqueue(t val) {
		if (isfull()) {
			cout << "array is full!";
			return;
		}
		//so that arrays empty spaces can be used when filled 
		back = (back + 1) % size;
		arr[back] = val;
		capacity++;
	}
	void dequeue() {
		if (isempty()) {
			cout << "array is empty!";
			return;
		}
		front = (front + 1) % size;  
		capacity--;
	}
	void print() {
		if (isempty()) {
			cout << "array is empty!";
			return;
		}
		for (int i = front; i <back+1; i++) {
			cout << arr[i] << "->";
		}
	}
	~queue() {
		delete[]arr;
	}
};
int main() {
	queue<int> q1(5);
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.dequeue();
	q1.print();

}