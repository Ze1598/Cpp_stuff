// This file goes over dynamic memory, more specifically, it goes over\
// the `new` and the `delete` operators

/*
Syntax for `new`:
	Returns a pointer to the beginning of the new block of memory. To
	allocate memory for a single element of type `type`, use
	`pointerName = new type`; to allocate a block (an array) of memory
	use `pointerName = new type [numberOfElements]` (note the returned
	pointer will point to the first element of the array).
Syntax for `delete`:
	This operator works similarly to the `new` operator, except this
	one releases allocated memory. To release memory of a single
	element, use `delete pointerName`; to delete the memory of arrays
	use `delete[] pointerName`.
*/

#include <iostream>
#include <new> // nothrow
using namespace std;


int main() {

	// `nums` is the number of items the user wants to input
	int nums;
	// Prompt the user for the number of numbers it will want\
	to input and save the answer in the `nums` variable
	cout << "How many numbers would you like to type? ";
	cin >> nums;
	
	// Create a new pointer whose memory is allocated dynamically\
	// with the `new` operator. The pointer will point to an array\
	// of `int`s. The number of elements the array will hold is the\
	// user's input
	int * p = new (nothrow) int[nums];
	
	// Because we have used the `nothrow` object when allocating the\
	// pointer's memory, in case the memory allocation fails, the pointer\
	// will turn out to be a null pointer instead of raising errors
	if (p == nullptr) {
		cout << "Error: memory could not be allocated";
	}

	// If the memory allocation was successful, than proceed with the program
	else {

		// Ask the user for a number as many times as the user specified in the first\
		// prompt. Save the numbers in the created array
		for (int i=0; i<nums; i++) {
			cout << "Enter number: ";
			cin >> p[i];
		}

		// Now loop through the array to print the numbers input by the user
		cout << "You have entered: ";
		for (int i=0; i<nums; i++) {
			cout << p[i] << ", ";
		}

		// At the end, delete the created array to free memory
		delete[] p;
	}
}