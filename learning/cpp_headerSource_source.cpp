/*
Source and Header files allows us to define new classes in separate files.
The header file contains the class and function prototypes (declaration),
and they can be imported/loaded into the source file so that they can be
used right away (though you'll probably want to modify their body).
*/

// Load the MyClass header which was created in the\
// "cpp_headerSource_header.cpp" file
#include "cpp_headerSource_header.h"
#include <iostream>
using namespace std;

// Use regular syntax (scope resolution) to create the constructor for\
// the loaded class, as if the class was declared in this file
MyClass::MyClass() {
	cout << "Succeful Header inclusion!" << endl;
}

int main() {
	// Create an object of the `MyClass` type, which will output a messsage\
	// thanks to the defined constructor
	MyClass();
}