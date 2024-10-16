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
bool find(Node* root, int key) {
	if (root == nullptr) {
		return false;
	}
	queue <Node*>q;
	q.push(root);
	Node* curr;
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		if (key == curr->data) {
			return true;
		}
		if (curr->right) {
			q.push(curr->right);
		}
		if (curr->left) {
			q.push(curr->left);
		}
	}
	return false; 
}
void insertnode(Node* root, int data) {
	Node* newnode = new Node(data);
	if (root == nullptr) {
		return; 
	}
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if (temp->left == nullptr) {
			temp->left = newnode;
			return; 
		}
		else {
			q.push(temp->left);
		}
		if (temp->right == nullptr) {
			temp->right = newnode;
			return;
		}
		else {
			q.push(temp->right);
		}
	}
}
b
void deletDeepest(struct Node* root, struct Node* d_node)
{
	queue<struct Node*> q;
	q.push(root);

	// Do level order traversal until last node
	struct Node* temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp == d_node) {
			temp = NULL;
			delete (d_node);
			return;
		}
		if (temp->right) {
			if (temp->right == d_node) {
				temp->right = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->right);
		}

		if (temp->left) {
			if (temp->left == d_node) {
				temp->left = NULL;
				delete (d_node);
				return;
			}
			else
				q.push(temp->left);
		}
	}
}
Node* deletion(struct Node* root, int key) 
{
	if (root == NULL)
		return NULL;

	if (root->left == NULL && root->right == NULL) {
		if (root->data == key)
			return NULL;
		else
			return root;
	}
	queue<struct Node*> q; 
	q.push(root);
	struct Node* temp;
	struct Node* key_node = NULL;
	while (!q.empty()) {
		temp = q.front();
		q.pop();

		if (temp->data == key)
			key_node = temp;

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}

	if (key_node != NULL) {
		int x = temp->data;
		key_node->data = x;
		deletDeepest(root, temp);
	}
	return root;
}
void print(Node* root) {
	if (root == nullptr) {
		return;
	} 
	queue<Node*>q;
	q.push(root);
	while (!q.empty()) {
		Node* curr = q.front(); 
		cout << q.front()->data << " ";
		q.pop(); 
		if (curr->left) {
			q.push(curr->left);
		}
		if (curr->right) {
			q.push(curr->right);
		}
	}
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
