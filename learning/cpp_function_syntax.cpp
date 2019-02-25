// This file goes over function definitions
#include <iostream>
#include <cstdio> // printf()
#include <string> // string types
#include <cmath> // pow()
using namespace std;

/* 
Function syntax:
type func_nam (type_arg1 arg1, type_arg2 arg2, ...) {
	statements
}
-type: type of the value returned by the function 
-func_name: name of the function 
-type_arg: type of the argument
-arg: name of the argument
-statements: body of the function
*/
int addition (int x, int y) {
	return x + y;
}

// A function of type `void` is a function that returns nothing
void printString (string out_string) {
	cout << out_string << "\n";
}

// A function that takes void as a single parameter is a function\
// that actually takes no parameters
void printMessage (void) {
	cout << "Void Function!" << "\n";
}

// Instead of passing arguments by value as usual, that is, the function\
// is passed the values of variables external to the function, here we are\
// passing values by reference: the function is being fed the actual external\
// variables. This means that when the arguments are modified, the variables\
// are modified as well outside the function. The names of the arguments inside\
// function work simply as aliases.
// To be passed by reference, the arguments' types are prefixed with an ampersand\
// (&)
void square_num (int& x, int& y) {
	x = pow(x, 2);
	y = pow(y, 2);
}

// Return the square root of a number. While we are passing parameters by reference,\
// because we also use the `const`, the function receives a reference to a variable\
// directly, but modifies a copy of it instead (that is returned at the end). In other\
// words, the function is using the variable from the global scope but modifies a copy\
// of the it instead
// By initializing the parameter `exponent`, we are defining that it has a default\
// value (0.5)
int root_num (const int& x, double exponent = 0.5) {
	return pow(x, exponent);
}

// Example of a recursive function
long factorial (long x) {
	if (x > 1) {
		return x * factorial(x-1);
	}
	else {
		return 1;
	}
}

int main() {
	int a = 5;
	int b = 2;
	// Add the two arguments
	int c = addition(a, b);
	cout << "addition(a, b) => " << c << "\n";
	string sample_string = "Hello World";
	// Output the string passed as argument
	printString(sample_string);
	// Output a string
	printMessage();
	// This function squares `a` and `b` by passing them by reference to\
	// function
	printf("Current values of `a` and `b`: %d and %d.\n", a, b);
	square_num(a, b);
	printf("New values of `a` and `b`: %d and %d.\n", a, b);
	// Print the square root of a number
	printf("Square root of %d: %d.\n", a, root_num(a));
	// Print the fourth root of a number
	printf("Fourth root of %d: %d.\n", 16, root_num(16, 0.25) );
	// Compute the factorial of 5
	printf("5!: %d.\n", factorial(5));
	// Compute the factorial of 10
	printf("10!: %d.\n", factorial(10));
	cout << "END\n";
}