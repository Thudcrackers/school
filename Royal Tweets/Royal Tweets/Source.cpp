#include <iostream>
#include <string>

using namespace std;

void main() {
	int numTweets;
	int loc;
	int monarchyCount = 0;
	string tweet;

	cin >> numTweets;

	for (int i = 0; i <= numTweets; i++) {
		getline(cin, tweet);
		
		for (int j = 0; j < tweet.length(); j++) {
			tweet[j] = tolower(tweet[j]);
		}
		
		loc = tweet.find("@britishmonarchy");
		if (loc >= 0)
			monarchyCount++;
	}

	cout << "The number of times @BritishMonarchy appears is " << monarchyCount << endl;
}