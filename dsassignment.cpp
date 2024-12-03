#include<iostream>
#include<vector>
#include<string>
using namespace std; 
struct Book {
	int ISSN;
	Book* next;
	Book* prev;
	string title;
	vector<string>authors;
	int refCopies;
	int issueCopies;

	Book(int i, string t, vector<string> a, int r, int is) {
		ISSN = i;
		title = t;
		authors = a;
		refCopies = r;
		issueCopies = is;
		next = prev = nullptr;
	}
};
//AVL struct that defines every node of AVL tree
struct AVLtree {
	int ISSN; //stores issn, which is unique and also, we have 
	//to sort the nodes on the basis of this
	Book* bookrecord; //points to the book node that has the record of the book that we want
	AVLtree* left; //left child 
	AVLtree* right; //right child 
	int height; //basically a balance factor for the avl tree

	AVLtree(int i, Book* record) {
		ISSN = i;
		bookrecord = record;
		height = 1;
		left = right = nullptr;
	}
};

//-> CREARING BOOK RECORD 

//function to get height of the node
int height(AVLtree* node) {
	return (node == nullptr) ? 0 : node->height;
}

int getbalance(AVLtree* node) {
	return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

//Creating a book record 
//basically inserting new book into doubly linked list and avl tree
//->STEPS: 
//1.insert into dll, according to issn
//2.insert new issn to avl and balance it 
Book* insertinList(Book*& head, int issn, string title, vector<string>authors, int ref, int issue) {
	Book* newbook = new Book(issn, title, authors, ref, issue);

	//if list if empty
	if (head == nullptr) {
		head = newbook;
		return newbook;
	}
	Book* current = head;
	//find the correct position
	while (current->next != nullptr && current->ISSN < issn) {
		current = current->next;
	}

	//if newbook's issn is less than current's issn, we insert newbook before current
	if (current->ISSN > issn) {
		newbook->next = current;
		//if currents prev is not null humen uske hisab se adjust karna hai newbook ko
		if (current->prev != nullptr) {
			current->prev->next = newbook;
			newbook->prev = current->prev;
		}
		//else if currents prev node is null i.e it is at the start we make newbook as the head
		else {
			head = newbook;
		}
		current->prev = newbook;
	}
	//inserting after current node 
	else {
		newbook->next = current->next;
		newbook->prev = current;
		//current node is not tail 
		if (current->next != nullptr) {
			current->next->prev = newbook;
		}
		current->next = newbook;
	}
	return newbook;
}

//right rotation for avl balancing
AVLtree* rightrotate(AVLtree* y) {
	AVLtree* x = y->left;
	AVLtree* T2 = x->right;
	x->right = y;
	y->left = T2;
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

// Left rotation for AVL balancing
AVLtree* leftRotate(AVLtree* x) {
	AVLtree* y = x->right;
	AVLtree* T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	return y;
}

//Insertion in AVL
AVLtree* insertinAVL(AVLtree* node, Book*& head, int i, string t, vector<string>a, int r, int is) {
	//insert in list in a sorted order 
	Book* newbook = insertinList(head, i, t, a, r, is);

	//if tree is empty/ leaf node is reached, a new node is created
	if (node == nullptr) {
		return new AVLtree(i, newbook);
	}

	if (i < node->ISSN) {
		node->left = insertinAVL(node->left, head, i, t, a, r, is);
	}
	else if (i > node->ISSN) {
		node->right = insertinAVL(node->right, head, i, t, a, r, is);
	}
	else {
		return node;
	}
	node->height = 1 + max(height(node->left), height(node->right));
	int balance = getbalance(node);

	//left left case
	if (balance > 1 && i < node->left->ISSN) {
		return rightrotate(node);
	}
	//right right case
	if (balance<-1 && i> node->right->ISSN) {
		return leftRotate(node);
	}
	//left right 
	if (balance > 1 && i > node->left->ISSN) {
		node->left = leftRotate(node->left);
		return rightrotate(node);
	}
	//right left
	if (balance < -1 && i < node->right->ISSN) {
		node->right = rightrotate(node->right);
		return leftRotate(node);
	}
	return node;
}

//->UPDATE BOOKRECORD 
void updateBookRecord(AVLtree* root, int issn, string newTitle, vector<string> newAuthors, int newRefCopies, int newIssueCopies) {
	// Base case: Tree empty ya ISSN not found
	if (root == nullptr) {
		cout << "Book record with ISSN " << issn << " not found!" << endl;
		return;
	}

	// Recursive search: Left or right subtree
	if (issn < root->ISSN) {
		updateBookRecord(root->left, issn, newTitle, newAuthors, newRefCopies, newIssueCopies);
	}
	else if (issn > root->ISSN) {
		updateBookRecord(root->right, issn, newTitle, newAuthors, newRefCopies, newIssueCopies);
	}
	else {
		// ISSN found, update the book record
		Book* book = root->bookrecord;
		book->title = newTitle;  // Update title
		book->authors = newAuthors;  // Update authors
		book->refCopies = newRefCopies;  // Update reference copies
		book->issueCopies = newIssueCopies;  // Update issuable copies

		cout << "Book record with ISSN " << issn << " updated successfully!" << endl;
	}
}

//-> REVIEW BOOK RECORD 
void reviewBookRec(AVLtree* root, int i) {
	if (root == nullptr) {
		cout << "Book record not found!";
		return;
	}
	if (i < root->ISSN) {
		reviewBookRec(root->left, i);
	}
	else if (i > root->ISSN) {
		reviewBookRec(root->right, i);
	}
	else {
		Book* book = root->bookrecord;
		cout << "Book record: \n";
		cout << "ISSN: " << book->ISSN << endl;
		cout << "Title" << book->title << endl;
		cout << "Authors: ";
		for (const string& author : book->authors) {
			cout << author << " ";
		}
		cout << endl;
		cout << "Reference: " << book->refCopies << endl;
		cout << "Issuable Copies: " << book->issueCopies << endl;
	}
}

//-> DELETE BOOK RECORD
//STEPS:
//search for the issn
//balance tree after deleting
//removing book from the linkedlist
AVLtree* minvalue(AVLtree* node) {
	AVLtree* current = node;
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}
void deletefromlist(Book*& head, Book* todelete) {
	if (head == nullptr) {
		return;
	}

	//if node to delete is head
	if (head == todelete) {
		head = todelete->next;
	}
	if (todelete->next != nullptr) {
		todelete->next->prev = todelete->prev;
	}
	if (todelete->prev != nullptr) {
		todelete->prev->next = todelete->next;
	}
	delete todelete;
}
AVLtree* deletebookrecord(AVLtree* root, Book*& head, int i) {
	if (root == nullptr) {
		return 0;
	}
	if (i < root->ISSN) {
		root->left = deletebookrecord(root->left, head, i);
	}
	else if (i > root->ISSN) {
		root->right = deletebookrecord(root->right, head, i);
	}
	else {
		deletefromlist(head, root->bookrecord);
	}
	if (root->left == nullptr || root->right == nullptr) {
		AVLtree* temp = root->left ? root->left : root->right;
		//no child
		if (temp == nullptr) {
			temp = root;
			root = nullptr;
		}
		//one child 
		else {
			*root = *temp; //copying root's data
		}
		delete temp;
	}
	//two children 
	else {
		AVLtree* temp = minvalue(root->right);
		root->ISSN = temp->ISSN;
		root->bookrecord = temp->bookrecord;
		root->right = deletebookrecord(root->right, head, temp->ISSN);
	}
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getbalance(root);

	//left left
	if (balance > 1 && getbalance(root->left) >= 0) {
		return rightrotate(root);
	}
	//left right
	if (balance > 1 && getbalance(root->left) < 0) {
		root->left = leftRotate(root->left);
		return rightrotate(root);
	}
	if (balance < -1 && getbalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getbalance(root->right) > 0) {
		root->right = rightrotate(root->right);
		return leftRotate(root);
	}
		return root;
}
int main() {
	AVLtree* root = nullptr;  // AVL tree root
	Book* head = nullptr;     // Doubly linked list head

	int choice, issn, refCopies, issueCopies;
	string title;
	vector<string> authors;
	string author;

	do {
		// Menu display
		cout << "\nLibrary Database System" << endl;
		cout << "1. Create a Book Record" << endl;
		cout << "2. Review a Book Record" << endl;
		cout << "3. Update a Book Record" << endl;
		cout << "4. Delete a Book Record" << endl;
		cout << "5. Exit" << endl;

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:  // Create a Book Record
			cout << "Enter ISSN: ";
			cin >> issn;
			cin.ignore();  // Ignore newline character

			cout << "Enter Title: ";
			getline(cin, title);

			cout << "Enter number of Authors: ";
			int numAuthors;
			cin >> numAuthors;
			cin.ignore();

			authors.clear();  // Clear previous authors
			for (int i = 0; i < numAuthors; ++i) {
				cout << "Enter Author " << (i + 1) << ": ";
				getline(cin, author);
				authors.push_back(author);
			}

			cout << "Enter number of Reference Copies: ";
			cin >> refCopies;

			cout << "Enter number of Issuable Copies: ";
			cin >> issueCopies;

			// Insert into AVL and linked list
			root = insertinAVL(root, head, issn, title, authors, refCopies, issueCopies);
			cout << "Book record created successfully!" << endl;
			break;

		case 2:  // Review a Book Record
			cout << "Enter ISSN to review: ";
			cin >> issn;
			reviewBookRec(root, issn);
			break;

		case 3:  // Update a Book Record
			cout << "Enter ISSN to update: ";
			cin >> issn;
			cin.ignore();

			cout << "Enter new Title: ";
			getline(cin, title);

			cout << "Enter number of new Authors: ";
			cin >> numAuthors;
			cin.ignore();

			authors.clear();
			for (int i = 0; i < numAuthors; ++i) {
				cout << "Enter Author " << (i + 1) << ": ";
				getline(cin, author);
				authors.push_back(author);
			}

			cout << "Enter new number of Reference Copies: ";
			cin >> refCopies;

			cout << "Enter new number of Issuable Copies: ";
			cin >> issueCopies;

			updateBookRecord(root, issn, title, authors, refCopies, issueCopies);
			break;

		case 4:  // Delete a Book Record
			cout << "Enter ISSN to delete: ";
			cin >> issn;
			root = deletebookrecord(root, head, issn);
			cout << "Book record deleted successfully!" << endl;
			break;

		case 5:  // Exit
			cout << "Exiting... Goodbye!" << endl;
			break;

		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 5);  // Loop until user chooses to exit

	return 0;
}
