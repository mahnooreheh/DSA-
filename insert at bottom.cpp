#include<iostream>
#include<stack>
#include<string>
using namespace std;
void insertatbottom(stack<int>&s, int n) {
	stack<int>s1; 
	while (!s.empty()) {
		s1.push(s.top());
		s.pop(); 
	}
	s.push(n); 
	while (!s1.empty()) {
		s.push(s1.top());
		s1.pop(); 
	}
}
int main() {
	int size; 
	stack<int>s1;  
	cout << "Enter a size "; 
	cin >> size;  
	int num; 
	for (int i = 0; i < size; i++) { 
		cout << "Enter number: ";
		cin >> num; 
		s1.push(num);  
	}
	int n;
	cout << "Enter the number that you want to insert: ";
	cin >> n; 
	insertatbottom(s1, n); 
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
}