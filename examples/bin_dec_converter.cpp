// # Contains a function to convert a decimal number to binary and another to make
// the reverse conversion
#include <iostream>
#include <string>
#include <cmath> // pow()
using namespace std;

// Convert a decimal number into a binary number (returned as a string with a\
// `0b` prefix)
string binConverter (int num) {

	// String to hold the converted number
	string result = "";

	// While the input number is larger than 0, divide it by 2\
	// and add the remainder of each division to the result string
	while (num > 0) {
		result = to_string(num%2) + result;
		num /= 2;
	}

	// Prefix the resulting string with `0b` to denote it's a binary number
	return "0b" + result;
}

// Convert a string with a binary number (prefixed with `0b`) to a decimal\
// integer
int decConverter (string num) {

	// The converted number
	int result = 0;
	// Convert the string with the binary number to a long integer, without\
	// the `0b` prefix
	long binNum = stol(num.substr(2));
	// The power to which to raise 2 to when converting a bit to a decimal value\
	// (incremented with every iteration of the loop to denote we are moving to the\
	// next bit)
	int factor = 0;

	// Loop while the binary number is larger than 0
	while (binNum > 0) {
		// Divide the binary number by 10 and multiply the remainder by the result\
		// of raising 2 to the power of factor
		result += (binNum%10) * pow(2, factor);
		// Save the result of dividing the binary number by 10
		binNum /= 10;
		// Increment the factor to move to the next bit
		factor++;
	}

	return result;
}


int main () {
	cout << "10: " << binConverter(10) << endl;
	cout << "143: " << binConverter(143) << endl;
	cout << "0b1010: " << decConverter("0b1010") << endl;
	cout << "0b10001111: " << decConverter("0b10001111") << endl;
}