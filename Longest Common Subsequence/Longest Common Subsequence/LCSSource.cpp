#include "LCSHeader.h"

void main() {
	string s1, s2;
	cout << "Enter the first string: ";
	getline(cin, s1);
	cout << "Enter the second string: ";
	getline(cin, s2);
	
	printLCS(lcsLength(s1, s2), s1, s1.length(), s2.length());
	cout << endl;
}