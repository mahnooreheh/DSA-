#include<iostream>
using namespace std;
class Node {
public:
	int data; 
	Node* next;

	Node(int d) {
		this->data = d;
		next = nullptr;
	}
};
class linkedlist {
public:
	Node* top;

	linkedlist() {
		top = nullptr;
	}
	void push(int element) {
		Node* newnode = new Node(element);
		if (top == nullptr) {
			top = newnode;
		}
		newnode->next = top;
		top = newnode; 
	}
	int pop() {
		if (top == nullptr) {
			cout << "empty";
			return;
		}
		int val = top->data; 
		Node* temp = top->next;
		delete top; 
		top = temp; 
		return val;
	}
	int peek() {
		if (top == nullptr) {
			return -1;
		}
		return top->data;
	}
};
int main() {

}