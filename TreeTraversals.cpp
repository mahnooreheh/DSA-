#include<iostream>
#include<queue> 
using namespace std;
struct Node {
	int data;
	Node* left;
	Node*right; 
	Node(int val) {
		this->data = val;
		left = right = nullptr;
	}
};
void inorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	inorder(root->left);
	cout << root->data;  
	inorder(root->right); 
}
void preorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	cout << root->data;
	preorder(root->left);
	preorder(root->right); 
}
void postorder(Node* root) {
	if (root == nullptr) {
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data;  
}
void levelorder(Node* root) {
	if (root == nullptr) { 
		return;
	}
	queue<Node*>q;
	q.push(root); 
	while (q.empty() != true) {
		Node* curr = q.front(); 
		q.pop();
		cout << curr->data; 
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}
	}
}
void printleftboundary(Node* root) {
	if (root == nullptr) {
		return;
	}
	queue<Node*>q;
	root = root->left; 
	while (root!= nullptr) {
		q.push(root); 
		root = root->left;   
	}
	cout << "\nleft boundar: " ;
	while (!q.empty()) {
		cout << q.front()->data;
		q.pop(); 
	}
	cout << endl;
}
void printrightboundary(Node* root) {
	if (root == nullptr) {
		return;
	}
	queue<Node*>q;
	root = root->right;   
	cout << "\nright boundary: ";
	while (root != nullptr) {
		q.push(root);
		root = root->right;  
	}
	while (!q.empty()) {
		cout << q.front()->data;
		q.pop();
	}
	cout << endl; 
}
void printleafnodes(Node* root) {
	if (root == nullptr) {
		return; 
	}
	if (root->left == nullptr && root->right == nullptr) {
		cout << root->data;
		return;
	}
	printleafnodes(root->left);
	printleafnodes(root->right);
}
void boundarytraversal(Node* root) {
	if (root == nullptr) { 
		return;
	} 
	printleftboundary(root); 
	printrightboundary(root); 
	cout << "\nleaf nodes are: ";
	printleafnodes(root); 
}
int main() {
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(6);
	cout << "Level order traversal: ";
	levelorder(root);
	cout << endl;
	boundarytraversal(root);
	return 0;
}