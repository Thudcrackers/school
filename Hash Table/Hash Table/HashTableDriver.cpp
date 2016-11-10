#include "HashTableHeader.h"


void main() {
	HashTable hash;
	int choice = 0;

	while (choice != 4) {
		cout << "Please choose an option:\n";
		cout << "1. Add a word\n";
		cout << "2. Search for a word\n";
		cout << "3. Delete a word\n";
		cout << "4. Exit.\n";
		cin >> choice;

		string word;
		switch (choice) {
		case 1:
			cout << "Please enter the word to add: ";
			cin >> word;
			hash.addWord(word);
			break;
		case 2:
			cout << "Please enter the word to search for: ";
			cin >> word;
			if (hash.search(word))
				cout << "Word found!\n";
			else
				cout << "Word not found.\n";
			break;
		case 3:
			cout << "Please enter the word to delete: ";
			cin >> word;
			if (hash.deleteWord(word))
				cout << "Deleted successfully!\n";
			else
				cout << "Word not found.\n";
			break;
		}
	}
}