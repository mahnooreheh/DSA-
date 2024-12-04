#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool validparenthesis(string s) {
	stack<char>s1;
	for (char ch : s) {
		if (ch == '{' or ch == '[' or ch == '(') {
			s1.push(ch);   
		}
		else {
			if (s1.empty() or
				(ch == ']' and s1.top() != '[') or
				(ch == '}' and s1.top() != '{') or
				(ch == ')' and s1.top() != '(')) {
				return false; 
			}
			s1.pop(); 
		}
	}
	return true; 
}
int main() {
	string s; 
	cout << "Enter paranthesis: ";
	cin >> s;
	if (validparenthesis(s)) {
		cout << "\nBalanced"; 
	}
	else {
		cout << "Not Balanced";
	}
}