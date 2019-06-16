// This file goes over templates for functions and classes
/*
Templates allow us to avoid the specification of a type in a function or
class, using placeholder types instead, that is, template type parameters.
template <class T>
T myFunc (T a, T b) {
	return a + b;	
};

The above function will work with both int and double inputs, because we
defined a template type `T` which is automatically replaced by the
corresponding data type when calling the function. To include multiple
types, simply separate them with a comma.

Templates can also be used with classes. But you need to keep in mind that
for functions defined outside the class body you need some special syntax.
Take a look at the following example, a method from the `myClass` defined
outside the class body.
template <class T>
T myClass<T>:someMethod() {
}

Template specialization allows for the definition of specific behavior
depending on the type passed as a template argument.
*/

#include <iostream>
using namespace std;

// This function will sum two given numbers, be it int or double, thanks\
// to the use of a template, that is, a placeholder for the data types in\
// play in the function
template <class T>
T sum (T a, T b) {
	return a + b;
};

// Function with two template types to check which of the two arguments is\
// bigger. The returned value will be of the type of the first argument
template <class T, class U>
T bigger (T a, U b) {
	return (a > b ? a : b);
};


// Create a template class
template <class T>
class Pair {
	private:
		T first, second;
	public:
		Pair (T a, T b) : 
		first(a), second(b) {
		}
		// Template method to be defined outside the class body
		T bigger();
};
// Define the template method outside the class body
template <class T>
T Pair<T>::bigger() {
  return (first>second ? first : second);
}

// Class to implement template specialization
template <class T>
class MyClass {
	public:
		MyClass (T x) {
			cout << x << " - is not a char" << endl;
		}
};
// This is the same class, but this time we define the behavior specific to\
// char
// The list of template parameters is empty because all types are known, the\
// line is included only as a formality
template <>
// Here we specify we'll be using this alternate code for the char type
class MyClass<char> {
	public:
		MyClass (char x) {
			cout << x << " - is a char" << endl;
		}
};

int main () {
	// Sum two integers or doubles
	cout << sum(5, 7) << endl;
	cout << sum(4.0, 6.0) << endl;

	// Check which number is bigger (it needs one integer and one double)
	cout << bigger(4, 3.0) << endl;
	cout << bigger(10, 15.0) << endl;

	// Because this object is using a template class, we need to specify\
	// the data type of the arguments for the constructor
	Pair <int> myObj(1, 2);
	cout << myObj.bigger() << endl;
	// This one uses doubles
	Pair <double> myObj2(1.0, 2.0);
	cout << myObj2.bigger() << endl;


	MyClass<int> obj3(8);
	MyClass<char> obj4('a');
};