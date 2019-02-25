#include <bits/stdc++.h> // memset()
using namespace std;

int main() {
	// This will be the size of the array
	int arraySize = 10;
	// Create an array that contains `arraySize` `bool`s
	bool sampleArray[arraySize];
	// Set the first `arraySize` elements of `sampleArray` to\
	// `true`
	memset(sampleArray, true, arraySize);

	// Loop through the array: set the elements at even indices to\
	// `false`
	for (int i=0; i<arraySize; i++) {
		if (i%2 == 0) {
			sampleArray[i] = false;
		}
	}

	// Output the indices of elements that have a value of `true`\
	// (i.e., elements whose index is odd)
	cout << "Odd numbers between 0 and 10" << "\n";
	for (int i=0; i<arraySize; i++) {
		if (sampleArray[i] == true) {
			cout << i << "\n";
		}
	}
}