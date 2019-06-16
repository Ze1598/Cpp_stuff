// This file goes over exceptions
/*
In C++, exception handling is done using three keywords: `try`, `catch` and
`throw`.

A `try` block is a block of code that includes code which is usually
prone to raising exceptions. It's usually paired with a `catch` block.
A `catch` block when a particular exception is thrown or raised.
Lastly, `throw` is used to raise designated exceptions.
In the example:
	try {
		int a = 5;
		int b = 0;
		if (b == 0) {
			throw 0;
		}
	}
	catch (int x) {
		cout << "You cannot divide by " << x << endl;
	}

An exception is raised if the second variable is set to 0. When that happens,
we throw a 0, that is, an integer, which is caught by the `catch` block as
variable called `x`. Inside this block, we just output a message to detail
what hapenned.
*/

#include <iostream>
using namespace std;

int main() {
	try {
		int a = 5;
		int b = 0;
		// If the second number is 0, then throw an exception
		if (b == 0) {
			throw 0;
		}
		// Otherwise, output the result of dividing the two numbers
		else {
			cout << a / b << endl;
		}
	}
	// Catch an exception raised with an integer
	catch (int x) {
		cout << "Error: You cannot divide by " << x << endl;
	}

	return 0;
};