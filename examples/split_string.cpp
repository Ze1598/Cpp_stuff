/*
	Get a vector of strings by splitting a given string at the desired
delimiter.
*/

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<string> splitString (string inputString, char delim) {
	// Create a string stream using the input string
	istringstream ss(inputString);
	// Variable to hold the contents of each split in the loop
	string token;
	// Vector to contain the string splits
	vector<string> splitVector;

	// Split the input string at spaces and obtain a vector with the existing\
	// "words" and/or numbers
	while (getline(ss, token, delim)) {
		// Append the new split to the vector
		splitVector.push_back(token);
	}

	return splitVector;
};

int main() {
	// Split the following string at spaces (get a vector where each element\
	// is a letter from the string)
	string testString1 = "a b c d e";
	vector<string> splits1 = splitString(testString1, ' ');
	for (int i=0; i<splits1.size(); i++) {
		cout << splits1[i] << endl;
	}
	cout << endl;

	// Split the following string at commas (get a vector where each element\
	// is a digit from the string (as a string datatype))
	string testString2 = "1,2,3,4,5";
	vector<string> splits2 = splitString(testString2, ',');
	for (int i=0; i<splits2.size(); i++) {
		cout << splits2[i] << endl;
	}

	return 0;
}