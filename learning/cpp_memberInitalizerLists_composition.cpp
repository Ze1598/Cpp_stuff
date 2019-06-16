// This file goes over member initializer lists and composition
/*
When a creating a new object for a class, there's a high chance that we
want to create said object with custom values for member variables by
passing arguments to the class constructor. However, in the example
	class SampleClass {
		public:
			SampleClass (int a, int b) {
				var1 = a;
				var2 = b;
			}
		private:
			int var1;
			int var2;
	}
is not only more verbose than the alternative member initializer lists
but will also throw an error if you're trying to feed the input values
to a `const`ant member variable.
So, what are member initializer lists? Simply put, they use consise
syntax to assign the input values from the constructor to member
variables. Simply add a colon (:) after the constructor's parameters,
followed by the `memberVar(parVal)` syntax, separating each member
with a comma. Look at the above example refactored with member
initializer lists:
	class SampleClass {
		public:
			SampleClass (int a, int b) : var1(a), var2(b) {}

		private:
			int var1;
			int var2;
	}
In this case, the constructor simply assigns the passed arguments as 
values to the class' member variables but you could, for example, output
the values or anything else you'd like.

Composition involves the use of classes as member variables for other
classes. For example, say we have a `Birthday` and a `Person` classes.
We can use the former to represent the birthday of a person and the latter
to represent a person, namely its birthday using a `Birthday` object.
*/

#include <iostream>
#include <string>
using namespace std;


// Example for member initializer lists
class Rectangle {
	public:
		// The constructor has three parameters: the first for the name\
		// of the rectange, and the remaining two for the dimensions.
		// We then use a member initializer list to assign said values\
		// to the class' member variables. Inside the constructor body\
		// we output a message to acknowledge the creation of a new object
		Rectangle (string a, double b, double c) :
			name(a), width(b), height(c) {
				cout << this->name << " has been created." << endl;
		}

		// Getter for the `name` member
		string getName (void) {
			return this->name;
		}

		// Calculate the rectangle's area
		double area (void) {
			return this->width * this->height;
		}

	private:
		string name;
		double width;
		double height;
};


// Example for composition
// Class for creating a single birthday date
class Birthday {
	public:
		// Class constructor that uses the arguments as values for the\
		// private member variables
		Birthday (string a, string b, string c) :
			bDay(a), bMonth(b), bYear(c) {
		}
		// Return a string built with the full birthday
		string getBday (void) {
			return this->bDay + "/" + this->bMonth + "/" + this->bYear;
		}
	private:
		string bDay;
		string bMonth;
		string bYear;
};
// Class for creating a person, that has a name and a birthday
class Person {
	public:
		// The constructor receives a string for the name and a `Birthday`\
		// object for the second member variable, so that we can access any\
		// (public) member variables or functions of that class
		Person (string a, Birthday b) :
			name(a), bDay(b) {
		}
		// Return a string with the birthday of this person by accessing the\
		// `getBday()` method of the `Birthday` class (we can do this because\
		// the `bDay` member is of type `Birthday`, that is, it holds a\
		// `Birthday` object)
		string printBday (void) {
			return this->bDay.getBday();
		}
		// Getter for `name`
		string getName (void) {
			return this->name;
		}
	private:
		string name;
		Birthday bDay;
};


int main () {
	// Member initializer lists example
	// -------------------------------------------------------------------------
	// Create a new `Rectangle` object
	// The constructor will output a message
	Rectangle myRect = Rectangle("myRect", 5.0, 6.4);
	// Print the area of the rectangle
	cout << myRect.getName() << " area is " << myRect.area() << "." << endl;
	// -------------------------------------------------------------------------

	// Composition example
	// -------------------------------------------------------------------------
	// Create a birthday date
	Birthday myBday = Birthday("9", "3", "1998");
	// Create a `Person` object whose birthday is that created with `myBday`
	Person myPerson = Person("José", myBday);
	// Print the birthday of the created person (using the `bDay` member\
	// variable which is a `Birthday` object, access its `getBday()`method\
	// to return the birthday as a string)
	cout << myPerson.getName() << "'s birthday is " << myPerson.printBday() << "." << endl;
	// -------------------------------------------------------------------------

	return 0;
}