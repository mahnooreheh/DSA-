#include<iostream>
#include<stack>
#include<string>
using namespace std;
void reversestring(string s) {
	stack<string>s1; 
	for (int i = 0; i < s.size(); i++) {
		string el(1, s[i]); 
		s1.push(el); 
	}
	cout << "Reversed string: ";
	while (!s1.empty()) {
		string front = s1.top();
		cout << front;
		s1.pop(); 
	}
}
void deletemiddle(stack<int>&s) { 
	int mid = s.size() / 2;
	stack<int>s1;
	for (int i = 0; i < mid; i++) {
		int front = s.top(); 
		s1.push(front); 
		s.pop(); 
	}
	s.pop();
	while (!s1.empty()) {
		int front1 = s1.top();
		s.push(front1);
		s1.pop(); 
	}
}
int main() {
	string s; 
	cout << "Enter string: ";
	cin >> s;
	reversestring(s); 
	stack<int >s1;  
	int size;  
	cout << "\nEnter a size of string to delete middle: ";
	cin >> size; 
	int num; 
	for (int i = 0; i < size; i++) { 
		cout << "Enter number: ";
		cin >> num;
		s1.push(num);  
	}
	deletemiddle(s1); 
	while (!s1.empty()) {
		cout << s1.top() << " ";
		s1.pop();
	}
}