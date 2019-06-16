/*
This file is a sample Header file to be used in combination with the
"cpp_headerSource_source.cpp" file.
In other words, this file contains only classes and functions prototypes
(declarations) that can be loaded/imported in the source file.
*/


// Create a condition for the preprocessor which makes it MYCLASS_H is defined\
// only if it hasn't been defined before
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
	public:
		MyClass();
	protected:
	private:
};

// End the conditional body for defining MYCLASS_H
#endif

