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
class queue {
private:
	Node* front, *rear;
	int size ;
public:
	queue() {
		front = rear = nullptr;
		size = 0;
	}
	bool isempty() {
		return size == 0;
	}
	void enqueue(int d) {
		Node* newnode = new Node(d);
		if (isempty()) {
			front = rear = newnode;
			rear->next = nullptr;
		}
		rear->next = newnode;
		rear = newnode; //mistake 
		size++;
	}
	void dequeue() {
		if (isempty()) {
			cout << "list is empty";
			return;
		}
		if (size == 1) {
			front = rear = nullptr;
			size--;
			return;
		}
		Node* temp = front;
		front = front->next;  
		if (front == nullptr) {  
			rear = nullptr; 
		}
		delete temp;
		size--;
	}
	void print() {
		Node* temp = front;
		while (temp != nullptr) {
			cout << temp->data << "->";
			temp = temp->next; 
		}
		cout << "NULL";
	}
};
int main() {
	queue q1;
	q1.enqueue(1);
	q1.enqueue(2);
	q1.enqueue(3);
	q1.dequeue();
	q1.print();
}