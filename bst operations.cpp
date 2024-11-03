#include<iostream>
using namespace std;
template<typename T>
struct Node { 
	Node* left, * right; 
	T data;
	Node(T& val) {
		data = val;
		left = right = nullptr; 
	}
};
template<typename T>
struct Comparator { 
	bool operator()(T& a, T& b) {
		return a < b;  
	}
};
template<typename T, typename Comp = Comparator<T>> 
class BST {
private:
	Node<T*>root;  
	Comp comp;   
	Node<T*>insert(Node<T*>node, T& val) {
		if (node == nullptr) {
			return new Node<T*>(val);
		}
		if (comp(val, node->data)) {
			node->left = insert(node->left, val);  
		}
		if (comp(node->data, val)) {
			node->right = insert(node->right, val);  
		}
		return node; 
	}
	void inorder(Node<T*>node) {
		if (node == nullptr) {
			return; 
		}
		inorder(root->left);  
		cout << node->data << " ";   
		inorder(root->right); 
	}
	Node<T*>findMin(Node<T*>node) {
		while (node && node->left != nullptr) { 
			node = node->left; 
		}
		return node; 
	}
	Node<T*>remove(Node<T*>node, T& val) {
		
		if (node == nullptr) {
			return node; 
		}
		if (comp(val, node->data)) {
			node->left = remove(node->left, val); //updating left tree 
		}
		if (comp(node->data, val)) {
			node->right = remove(node->right, val);  //right tree updating
		}
		else {
			//no child
			if (node->left == nullptr && node->right == nullptr) {
				delete node; 
				return nullptr; 
			}
			//one child
			if (node->right == nullptr) {
				Node<T*>temp = node->left; 
				delete node;   
				return temp;  
			}
			if (node->left == nullptr) {
				Node<T*>temp = node->right; 
				delete node;  
				return temp; 
			}
			//two child
			Node<T*>temp = findMin(node->right);
			node->data = temp->data; 
			node->right = remove(node->right, temp->data); 
		}
		return node;  
	}
	Node<T>* findnode(Node<T>*node, int& val) { 
		if (node == nullptr) {
			return nullptr; 
		}
		if (node->data == val) {
			return node;
		}
		if (comp(val, node->data)) {
			return findnode(node->left, val); 
		}
		if (comp(node->data, val)) {
			return findnode(node->right, val);  
		}
	}
public: 
	BST() : root(nullptr) {} 

	// Insert a value into the BST
	void insert(const T& value) {
		root = insert(root, value);
	}

	// Remove a value from the BST
	void remove(const T& value) {
		root = remove(root, value);
	}

	// In-order traversal (sorted output)
	void inorder() const {
		inorder(root);
		cout << endl;
	}
	bool isBST(Node<T>* root, Node<T>* left= nullptr, Node<T>* right=nullptr) {
		if (root == nullptr) {
			return true; 
		}
		if (left != nullptr && root->data <= left->data) {
			return false; 
		}
		if (right != nullptr && root->data >= right->data) { 
			return false;
		}
		return isBST(root->left, left, root) && isBST(root->right,root ,right); 
	}
	int count = 0; 
	int countnodes(Node<T>* root, int l, int h) {
		if (root == nullptr) {
			return 0;
		}
		if (root->data <= h && root->data >= l) {
			count=1 ; 
		}
		return count + countnodes(root->left, l,h) + countnodes(root->right, l ,h); 
	}
};
int main() {
	BST<int> bst;

	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80); 
	//cout << "In-order traversal: ";
	//bst.inorder();  // Output should be sorted

	//cout << "Deleting 20\n";
	//bst.remove(20);
	//cout << "In-order traversal: ";
	//bst.inorder();

	//cout << "Deleting 30\n";
	//bst.remove(30);
	//cout << "In-order traversal: ";
	//bst.inorder();

	//cout << "Deleting 50\n";
	//bst.remove(50);
	//cout << "In-order traversal: ";
	//bst.inorder();
}