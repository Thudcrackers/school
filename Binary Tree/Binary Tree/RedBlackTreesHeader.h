#pragma once

#include <iostream>
#include <string>

using namespace std;

enum color { RED, BLACK };

struct Node {
	string key = "";
	Node* parent = NULL;
	Node* left = NULL;
	Node* right = NULL;
	color c = RED;
};

class BinaryTree {
public:
	Node* root;
	Node* nil = new Node;

	BinaryTree() {
		root = NULL;
		nil->left = nil->right = nil->parent = NULL;
		nil->key = "";
		nil->c = BLACK;
	}

	BinaryTree(string str) {
		root->key = str;
		root->parent = NULL;
		root->left = NULL;
		root->right = NULL;
		nil->left = nil->right = nil->parent = NULL;
		nil->key = "";
		nil->c = BLACK;
	}

	void printPreOrder(Node* current) {
		if (current) {
			cout << current->key << " ";
			printPreOrder(current->left);
			printPreOrder(current->right);
		}
	}

	void printInOrder(Node* current) {
		if (current) {
			printInOrder(current->left);
			cout << current->key << " ";
			printInOrder(current->right);
		}
	}

	void printPostOrder(Node* current) {
		if (current) {
			cout << current->key << " ";
			printPostOrder(current->left);
			printPostOrder(current->right);
		}
	}

	Node* treeSearch(Node* current, string word) {
		if (!current || word == current->key)
			return current;
		if (word < current->key)
			return treeSearch(current->left, word);
		else
			return treeSearch(current->right, word);
	}

	Node* iterativeTreeSearch(Node* current, string word) {
		while (current && word != current->key) {
			if (word < current->key)
				current = current->left;
			else
				current = current->right;
		}
		return current;
	}

	Node* treeMinimum(Node* current) {
		while (current->left)
			current = current->left;
		return current;
	}

	Node* treeMaximum(Node* current) {
		while (current->right)
			current = current->right;
		return current;
	}

	Node* treeSuccessor(Node* current) {
		if (current->right)
			return treeMinimum(current->right);
		Node* temp = current->parent;
		while (temp && current == temp->right) {
			current = temp;
			temp = temp->parent;
		}
	}

	void addWord(string word) {
		Node* y = NULL;
		Node* current = root;
		Node* newNode = new Node;
		newNode->key = word;

		while (current) {
			y = current;
			if (newNode->key < current->key)
				current = current->left;
			else
				current = current->right;
		}

		newNode->parent = y;

		if (!y)
			root = newNode;
		else if (newNode->key < y->key)
			y->left = newNode;
		else
			y->right = newNode;
	}

	void transplant(Node* node1, Node* node2) {
		if (!node1->parent)
			root = node2;
		else if (node1 == node1->parent->left)
			node1->parent->left = node2;
		else
			node1->parent->right = node2;
		if (node2)
			node2->parent = node1->parent;
	}

	void deleteWord(string word) {
		Node* newNode = root;
		newNode = iterativeTreeSearch(newNode, word);

		if (!newNode->left)
			transplant(newNode, newNode->right);
		else if (!newNode->right)
			transplant(newNode, newNode->left);
		else
			Node* temp = treeMinimum(newNode->right);
	}

	void leftRotate(Node* pivot) {
		Node* temp = pivot->right;
		pivot->right = temp->left;
		if (temp->left)
			temp->left->parent = pivot;
		temp->parent = pivot->parent;
		if (!pivot->parent)
			root = temp;
		else if (pivot == pivot->parent->left)
			pivot->parent->left = temp;
		else
			pivot->parent->right = temp;
		temp->left = pivot;
		pivot->parent = temp;
	}

	void rightRotate(Node* pivot) {
		Node* temp = pivot->left;
		pivot->left = temp->right;
		if (temp->right)
			temp->right->parent = pivot;
		temp->parent = pivot->parent;
		if (!pivot->parent)
			root = temp;
		else if (pivot == pivot->parent->right)
			pivot->parent->right = temp;
		else
			pivot->parent->left = temp;
		temp->right = pivot;
		pivot->parent = temp;
	}

	void redBlackInsert(string word) {
		Node* newNode = new Node;
		newNode->key = word;

		Node* y = NULL;
		Node* x = root;

		while (x) {
			y = x;
			if (newNode->key < x->key)
				x = x->left;
			else
				x = x->right;
		}

		newNode->parent = y;

		if (!y)
			root = newNode;
		else if (newNode->key < y->key)
			y->left = newNode;
		else
			y->right = newNode;

		newNode->left = NULL;
		newNode->right = NULL;
		newNode->c = RED;
		redBlackInsertFixup(newNode);
	}

	void redBlackInsertFixup(Node* newNode) {
		while (newNode->parent && newNode->parent->c == RED) {
			if (newNode->parent->parent && newNode->parent == newNode->parent->parent->left) {
				Node* y = newNode->parent->parent->right;
				if (y && y->c == RED) {
					newNode->parent->c = BLACK;
					y->c = BLACK;
					newNode->parent->parent->c = RED;
					newNode = newNode->parent->parent;
				}
				else if (newNode == newNode->parent->right) {
					newNode = newNode->parent;
					leftRotate(newNode);
				}
				else {
					newNode->parent->c = BLACK;
					newNode->parent->parent->c = RED;
					rightRotate(newNode->parent->parent);
				}
			}
			else
				//what the fuck
				if (newNode->parent->parent && newNode->parent == newNode->parent->parent->right) {
					Node* y = newNode->parent->parent->left;
					if (y && y->c == RED) {
						newNode->parent->c = BLACK;
						y->c = BLACK;
						newNode->parent->parent->c = RED;
						newNode = newNode->parent->parent;
					}
					else if (newNode == newNode->parent->left) {
						newNode = newNode->parent;
						rightRotate(newNode);
					}
					else {
						newNode->parent->c = BLACK;
						newNode->parent->parent->c = RED;
						leftRotate(newNode->parent->parent);
					}
				}
			root->c = BLACK;
		}
	}

	void redBlackTransplant(Node* node1, Node* node2) {
		if (!node1->parent)
			root = node2;
		else if (node1 == node1->parent->left)
			node1->parent->left = node2;
		else
			node1->parent->right = node2;
		node2->parent = node1->parent;
	}

	void redBlackDelete(string word) {
		Node* x = new Node;

		Node* newNode = root;
		newNode = iterativeTreeSearch(newNode, word);

		Node* y = newNode;
		color originalcolor = y->c;

		if (!newNode->left) {
			x = newNode->right;
			redBlackTransplant(newNode, newNode->left);
		}
		else if (!newNode->right) {
			x = newNode->left;
			redBlackTransplant(newNode, newNode->left);
		}
		else {
			y = treeMinimum(newNode->right);
			originalcolor = y->c;
			x = y->right;
			if (y->parent == newNode)
				x->parent = y;
			else {
				redBlackTransplant(y, y->right);
				y->right = newNode->right;
				y->right->parent = y;
			}
			redBlackTransplant(newNode, y);
			y->left = newNode->left;
			y->left->parent = y;
			y->c = newNode->c;
		}
		if (originalcolor == BLACK)
			redBlackDeleteFixup(x);
	}

	void redBlackDeleteFixup(Node* x) {
		while (x != root && x->c == BLACK) {
			if (x == x->parent->left) {
				Node* w = x->parent->right;
				if (w->c == RED) {
					w->c = BLACK;
					x->parent->c = RED;
					leftRotate(x->parent);
					w = x->parent->right;
				}
				if (w->left->c == BLACK && w->right->c == BLACK) {
					w->c = RED;
					x = x->parent;
				}
				else if (w->right->c == BLACK) {
					w->left->c = BLACK;
					w->c = RED;
					rightRotate(w);
					w = x->parent->right;
				}
				else {
					w->c = x->parent->c;
					x->parent->c = BLACK;
					w->right->c = BLACK;
					leftRotate(x->parent);
					x = root;
				}
			}
			else {
				Node* w = x->parent->left;
				if (w->c == RED) {
					w->c = BLACK;
					x->parent->c = RED;
					leftRotate(x->parent);
					w = x->parent->left;
				}
				if (w->right->c == BLACK && w->left->c == BLACK) {
					w->c = RED;
					x = x->parent;
				}
				else if (w->left->c == BLACK) {
					w->right->c = BLACK;
					w->c = RED;
					rightRotate(w);
					w = x->parent->left;
				}
				else {
					w->c = x->parent->c;
					x->parent->c = BLACK;
					w->left->c = BLACK;
					leftRotate(x->parent);
					x = root;
				}
			}
		}
	}
};