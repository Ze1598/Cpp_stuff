// This file goes over built-in arrays as well as arrays from the <array> header (briefly)
#include <iostream>
#include <string> // string types
#include <array>
using namespace std;


// Create a function to output the contents of an array one by one
// This function receives an array of `int`s, as well as a separate
// `int`, which is the length of the array
void printArray (int arg[], int length) {
	for (int i=0; i<length; i++) {
		cout << arg[i] << " ";
	}
	cout << "\n";
}


int main() {

	/*
	Arrays can be created using the syntax:
	type name [elements], where `type` identifies the data type of
	`elements`, `name` is the name of the array and `elements` is an
	integer that specifies the length of the array.
	When declared are always initialized (when declared outside any
	function).
	In any way, to initialize an array enclose the array elements
	with brackets.
	*/
	// Create an array that contains three `int`s
	int array1 [3] = {1, 2, 3};
	// Create an array that contains three `double`s
	bool array2 [3] = {true, false, false};
	// Create an array that contains three `string`s. The compiler\
	// can deduce the value of `elements` if the array is initalized when\
	// it is declared
	string array3 [] = {"a", "b", "c"};
	// Access items from the created arrays
	cout << "Second element of `array1` => " << array1[1] << "\n";
	cout << "Third element of `array3` => " << array3[2] << "\n";
	// Loop through an array
	for (int i=0; i<sizeof(array2); i++) {
		cout << "array2[" << i << "] => " << array2[i] << "\n";
	}

	/*
	Multidimensional arrays
	To creata an array with a dimensional bigger than one, simply add a new `elements`
	field to the array declaration. For example, to create a two-dimensional array
	(matrix) you'd use: type name [elementsRows][elementsColumns]
	*/
	// Create a matrix of two rows by three columns
	int matrix1 [2][3] = {
		{1, 2, 3},
		{4, 5, 6}
	};
	// Get the number of rows in the matrix
	int matrix1SizeRows = sizeof(matrix1) / sizeof(matrix1[0]);
	// Get the number of columns in the matrix
	int matrix1SizeColumns = sizeof(matrix1[0]) / sizeof(int);
	// Loop through each value in the matrix
	// Loop through the rows
	for (int row=0; row<matrix1SizeRows; row++) {
		// Loop through the columns
		for (int column=0; column<matrix1SizeColumns; column++) {
			cout << "matrix1[" << row << "][" << column << "] => " << matrix1[row][column] << "\n";
		}
	}

	// Create an array that contains five strings
	int sampleArray [2] = {1 , 2};
	// Call `printArray()` on `sampleArray` to print its contents
	cout << "sampleArray contents => ";
	printArray(sampleArray, sizeof(sampleArray)/sizeof(*sampleArray));

	// Create an array using the container library array
	array<int, 3> libArray = {10, 20, 30};
	// Loop through the array
	for (int i=0; i<libArray.size(); i++) {
		cout << "libArray[" << i << "] => " << libArray[i] << "\n";
	}

	// Since strings are character sequences, an array can be initialized with a string,\
	// either by separating each character into an array element or by initializing the\
	// array with a string.
	// Due note a null character is necessary as the last item of the array (when the\
	// individual characters are used in the array initialization; if a string is used\
	// then there's no need to worry about it)
	// Create an array where each item is a character from the string `"Hello"`
	// This is equivalent to `char stringArray [] = {"H", "e", "l", "l", "o", "\0"};`
	char stringArray [] = "Hello";
	cout << "stringArray => " << stringArray << "\n";

	cout << "END\n";
}