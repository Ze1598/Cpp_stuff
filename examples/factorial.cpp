#include <iostream>
using namespace std;

// Function to compute the factorial of a given integer
int factorial (int x) {
	// If `x` is 1 or less, return 1
	if (x <= 1) {
		return 1;
	}
	// Else, return the product of `x` and the factorial of\
	// `x-1`, that is, `x` multiplied by all the integers
	// smaller than itself and larger than 0
	else {
		return x * factorial(x-1);
	}
};


int main() {
	// Output the factorial of the first five natural numbers
	for (int i=1; i<6; i++) {
		cout << i << "! = " << factorial(i) << "\n";
	}
}