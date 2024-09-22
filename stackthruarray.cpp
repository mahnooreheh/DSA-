#include<iostream>
#include<stack>
using namespace std;
class stackk {
public:
	int* arr;
	int size;
	int top;
public:
	stackk(int s) {
		this->size = s;
		arr = new int[size];
		top = -1;
	}
	int sizee () {
		return top + 1;
	}
	bool isfull() {
		if (top == size-1) {
			return true;
		}
		return false;
	}
	bool isempty() {
		if (top == -1) {
			return true;
		}
		return false;
	}
	void push(int element) {
		if (isfull()) {
			cout << "List is full!";
			return;
		}
		top++;
		arr[top] = element;
	}
	int pop() { //top element remove karana hai
		if (isempty()) {
			return -1;
		}
		return arr[top--]; //return top and then decrements it
	}
	int peek() {
		if (!isempty()) {
			return arr[top];
		}
		else {
			return -1;
		}
	}
	void print() {
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << " ";
		}
	}

};
class doublestack {
public:
	int top1, top2;
	int size;
	int* arr;

	doublestack(int s) {
		this->size = s;
		top1 = -1;
		top2 = s; 
		arr = new int[size];
	}
	bool isfull1() { 
		if (top1+1 == top2) {
			return true;
		}
		return false;
	}
	bool isempty1() {
		if (top1 == -1 ) {
			return true;
		}
		return false;
	}
	bool isempty2() {
		if (top2 == size) {
			return true;
		}
		return false;
	}
	void push1(int element) {
		if (isfull1()) {
			cout << "Array is full.";
			return;
		}
		top1 += 1;
		arr[top1] = element; 
	}
	int pop1() {
		if (isempty1()) {
			return -1;
		}
		return arr[top1--]; 
	}
	void push2(int element) {
		if (isfull1()) {
			cout << "Stack overflow!";
			return;
		}
		top2 -= 1;
		arr[top2] = element; 
	}
	int pop2() {
		if (isempty2()) {
			return -1;
		}
		return arr[top2++]; //kyunke top2 ne pop hone ke bad right pe jana hai na 
	}
	int peek1() {
		if (isempty1()) {
			return -1;
		}
		return arr[top1];
	}
	int peek2() {
		if (isempty2()) {
			return -1;
		}
		return arr[top2];
	}
};
int main() {
	stackk s1(5);
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.print();
	cout << "The popped is: " << s1.pop() << endl;
	s1.print();
}