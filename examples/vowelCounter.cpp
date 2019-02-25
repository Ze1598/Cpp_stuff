// Find the frequency of each vowel in a given string and save the results
// in an unordered map (unordered_map)
#include <iostream>
#include <string> // string
#include <unordered_map> // unordered_map<>
#include <vector> // vector<>
#include <algorithm> // find()
using namespace std;

// Loop through a string to extract the frequency of each vowel,\
// returning an unordered map where each key-value pair represents a\
// vowel and its frequency
unordered_map<char, int> vowelCounter (string word) {
	
	// Create the hash map
	unordered_map<char, int> vowelCounts = {};
	// Create an array with all vowels
	char vowels [5] = {'a', 'e', 'i', 'o', 'u'};

	// Loop through the word
	for (int i=0; i<word.length(); i++) {
		// Save the current character
		char letter = word[i];
		
		// If the character is a vowel (i.e., the character is present in\
		// the `vowels` array)
		if ( find(begin(vowels), end(vowels), letter) != end(vowels) ) {
		
			// If the vowel is in the map, increment its frequency (value)
			if (vowelCounts.find(letter) != vowelCounts.end()) {
				vowelCounts[letter] += 1;
			}
		
			// Else, add it as a new key with a value of 1
			else {
				vowelCounts[letter] = 1;
			}
		}
	}

	// Return the map
	return vowelCounts;
	
}


// Return a vector with all the keys of a given unordered map
vector<char> getKeys (unordered_map<char, int> uMap) {
	// Declare a new empty vector	
	vector<char> vowels;
	// Loop through the map to extract its keys
	for (auto key_value : uMap) {
		// Append the current key (`.first`) to the vector
		vowels.push_back(key_value.first);
	}
	// Return the vector
	return vowels;
}

// Function responsible for calling other functions to extract the frequency of\
// vowels in the target string (as an `unordered_map`), create a vector with\
// the keys of the map, and lastly print the frequencies (values) of each vowel\
// (key)
void printKeyValues (string word) {
	cout << "Target string: \"" << word << "\"" << endl;
	// Return an unordered map where each key-value pair represents a vowel\
	// and its frequency in the string
	unordered_map<char, int> counted = vowelCounter(word);
	// Return a vector with all the vowels (keys) in the above map
	vector<char> vowelsFound = getKeys(counted);
	// Now loop through the vector to print the value (frequency) of each key\
	// (vowel) in the map
	cout << "Frequency of vowels:" << endl;
	for (int i=0; i<vowelsFound.size(); i++) {
		cout << vowelsFound[i] << ": " << counted[vowelsFound[i]] << endl;
	}
}

int main () {
	string a = "banaena";
	// This function will call the necessary functions so that we only need to\
	// pass it the target string
	printKeyValues(a);
}