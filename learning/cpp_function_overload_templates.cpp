// This file goes over function overload and function templates
#include <iostream>
#include <string> // string types
using namespace std;

/*
Function overload: when two functions have the same name but are
still different functions because their parameters are different
(the parameters being of different type is enough to differentiate
the functions).
*/
// These functions have the same but the types of their parameters are\
// different and the body itself is also different between functions.\
// Thus, we have here two different (overloaded) functions
int overloadFunc (int a, int b) {
	return a+b;
}
int overloadFunc (double a, double b) {
	return a-b;
}

/*
Function template: allows the definition of a function using generic types.
This allows the application of function overload but the function needs to
be defined only once. To actually create a function using the template,
you just need to call the template with the necessary amount of arguments.
The type of the arguments can either be defined with the call or deduced by
the compiler, as long as the arguments are all of the same type.
The syntax to create a template is:
template <templateParameter1, templateParameter2, ...> functionDeclaration
The `templeteParameter`s can be any types you want, using `class` or
`typename`.
*/
// Create a function template used to add up two numbers
// We use a single parameter: `type1`, which will be the type of the value returned\
// by the function, as well as the type of each parameter received by the function
template <class type1>
type1 addNumbers (type1 a, type1 b) {
	return (a+b);
}
// Create a new function tempate
// The intended use is to compare two numbers
template <class T, class U>
bool areEqual (T a, U b) {
	return (a == b);
}
// Templates can also specify the exact data types to be used. In these cases, the\
// arguments are only passed as template parameters when creating functions, and never\
// as regular arguments
// Again, because we specify `N` is an `int`, it isn't included as a parameter
template <class T, int N>
int template_multiply (T a) {
	return a * N;
}



int main() {
	cout << "Function overload\n";
	// This one adds the arguments
	cout << "overloadFunc(5, 2): " << overloadFunc(5, 2) << "\n";
	// This one subtracts the arguments
	cout << "overloadFunc(3.5, 1.5): " << overloadFunc(3.0, 1.5) << "\n";
	// Apply the `addNumbers` template using `int` as the type and `10` and `20` as the\
	// function arguments
	// This is equivalent to: `addNumbers_a = addNumbers(10,20);` because both arguments are\
	// `int`s
	int addNumbers_a = addNumbers<int>(10,20);
	// This application of the template uses `double` as its templateParameter
	// In this case we let the compiler deduce what is the data type to use (`double`)
	double addNumbers_b = addNumbers(3.5, 1.5);
	// Use the `areEqual` template to create a function that compares the `int` 10 with the\
	// `double` 10.0
	bool areEqual_a = areEqual(10, 10.0);
	// Use the `areEqual` template to create a function that compares the `double` 5.1 with the\
	// `int` 5. In this case, we specify the data types to use be used
	bool areEqual_b = areEqual<double, int>(5.1, 5);
	// Use the `template_multiply` template to create a function that multiplies a `double` by 6
	int template_multiply_a = template_multiply<double, 6>(2.5);

	cout << "addNumbers template\n";
	cout << addNumbers_a << "\n";
	cout << addNumbers_b << "\n";
	cout << "areEqual template\n";
	cout << areEqual_a << "\n";
	cout << areEqual_b << "\n";
	cout << "template_multiply template\n";
	cout << template_multiply_a << "\n";
 	cout << "END\n";
}