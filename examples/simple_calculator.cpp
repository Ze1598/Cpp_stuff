#include <iostream>
using namespace std;

int main()
{
	// `char` object to hold the user input
	char op;
	// `float` objects to hold the numbers input\
	// by the user
	float num1, num2;

	// Ask the user for an operator (a single character)
	cout << "Enter operator (+; -; *; /) : ";
	cin >> op;

	// Ask the user for two numbers
	cout << "Enter two operands: ";
	cin >> num1 >> num2;

	// Use a switch/case to handle execution depending on\
	// the operation chosen by the user
	switch(op)
	{
		case '+':
			cout << num1+num2;
			break;

		case '-':
			cout << num1-num2;
			break;

		case '*':
			cout << num1*num2;
			break;

		case '/':
			cout << num1/num2;
			break;

		default:
			// If the operator is other than +, -, * or /, output\
			// a special message
			cout << "Error! operator is not correct";
			break;
	}

	return;
}