#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class HashTable {
public:
	vector<vector<string>> hashTable;

	HashTable() {
		for (int i = 0; i < 26; i++) {
			vector<string> tmp;
			hashTable.push_back(tmp);
		}
	}

	int hash(string word) {
		return (int)(tolower(word[0])) % 26;
	}

	void addWord(string word) {
		hashTable[hash(word)].push_back(word);
	}

	bool search(string word) {
		for (int i = 0; i < hashTable[hash(word)].size(); i++) {
			if (hashTable[hash(word)][i] == word)
				return true;
		}
		return false;
	}

	bool deleteWord(string word) {
		bool found = false;
		for (int i = 0; i < hashTable[hash(word)].size(); i++) {
			if (hashTable[hash(word)][i] == word) {
				found = true;
				hashTable[hash(word)].erase(hashTable[hash(word)].begin() + i);
			}
		}
		return found;
	}
};