#include "BinaryTreeHeader.h"

void main() {
	BinaryTree tree;
	tree.printInOrder(tree.root);
	tree.addWord("chicken");
	tree.printInOrder(tree.root);
	cout << endl << endl;

	tree.addWord("lol");
	tree.addWord("filibuster");
	tree.printInOrder(tree.root);
	cout << endl << endl;

	tree.deleteWord("lol");
	tree.printInOrder(tree.root);
	cout << endl << endl;

	tree.deleteWord("chicken");
	tree.printInOrder(tree.root);
	cout << endl << endl;

	BinaryTree redBlack;
	redBlack.redBlackInsert("something");
	redBlack.printRBInOrder(redBlack.root);
	cout << endl << endl;

	redBlack.redBlackInsert("lenoir");
	redBlack.redBlackInsert("rhyne");
	redBlack.redBlackInsert("university");
	redBlack.printRBInOrder(redBlack.root);
	cout << endl << endl;

	redBlack.redBlackDelete("rhyne");
	redBlack.printRBInOrder(redBlack.root);
}