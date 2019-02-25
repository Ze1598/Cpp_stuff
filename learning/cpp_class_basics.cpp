// This file goes over the fundamentals of classes: creation, access
// modifiers, class constructors, destructors and copy constructors
#include <iostream>
#include <string>
using namespace std;

/*
A class can be defined with as little as the following syntax
	class className {
		classMember1Type classMember1;
		classMember2Type classMember2;
		classMember3Type classMember3;
		...
	};

An object of the class `className` is created using
	className myObject;

The members inside a class can be grouped with class access modifiers,
which, as the name implies, define what type of access the members have.
There are three access modifiers: `public`, `private` and `protected`.
	`public`: public members can be accessed from anywhere within the
program. The values of these members can be set and get without any
member function.
	`private`: private members cannot be accessed or even viewed from
outside the class. Only the class and friend functions can access these
members. This is the default modifier for class members.
	`protected`: protected members are very similar to their private
counterparts, but they provide the ability to access these members
within child classes.
	
	The class constructor, just like member functions, can be declared
either inside or outside the class body. Inside the class body it looks
like this:
	className (parameters) {
		constructor body
	}
To declare it outside the class body, inside the body include the constructor
declaration (just like any member function declared outside the body):
	className (parameters);
And declare the constructor outside:
	className::className (parameters) {
		constructor body
	};
The class destructor works, syntactically, just like the constructor, except
the constructor name must be prefixed by a tilde (~) and it can neither receive
arguments nor return any values. Since the syntax is the same, I will only
exemplify here the declaration inside the class body:
	~className () {
		destructor body
	}
The destructor is executed whenever an object of its class goes out of scope or
whenever the `delete` expression is applied to a pointer of the object of its
class.

A copy constructor creates an object by initializing it with an object of the
same class that has been created beforehand. The copy constructor can be used
to copy an object to be used as an argument to a function and to be returned
by a function. To define a copy constructor use:
	className (const className &obj) {
		copy constructor body
	}

*/


// Create a new class to represent a box
class Box {
	// Since this member is declared before any modifiers, it will keep\
	// the default access: private
	// Note: this member was created just to exemplify the behavior of\
	// members declared before any access modifiers
	string brand = "";

	// The dimensions of the box will be public, that is, they can be\
	// modified at will, as well as the setter and getter functions for\
	// the color
	public:
		// Class constructor
		// Whenever an object of this class is created, it must pass the\
		// constructor a string, so that it can set the value of the `boxName`
		// member with it
		Box (string box_name) {
			boxName = box_name;

			// Initialize the private pointer `ptr` as a new string object
			ptr = new string;
			// And set the pointer's value to be the `boxName` member
			*ptr = boxName;
		}
		// To define the class constructor outside the class body, only the\
		// following line is needed (just like normal functions), with the\
		// constructor itself being defined outside
		// Box (string box_name);

		// Class destructor
		// Everytime an object of this class is `delete`d, output a message
		~Box () {
			cout << boxName << " has been destroyed.\n";
		}
		// To define the class destructor outside the class body, do it just like with\
		// the constructor
		// ~Box ();

		// Copy constructor
		// This will be used whenever an object of this class is passed as an argument\
		// or returned by a function
		Box (const Box &obj) {
			// Inside the copy constructor create another pointer so that we get access\
			// to the value of the pointer initialized in the class constructor
			ptr = new string;
			// The value of this new pointer is the value of the `ptr` pointer of the `Box`\
			// object
			*ptr = *obj.ptr;
			cout << "A copy of the object has been created.\n";
		}
		// To define the class copy constructor outside the class body, do it like the constructor\
		// and the destructor
		// Box (const Box &obj);

		// Public member variables
		double length;
		double width;
		double height;

		// Public member functions
		void setColor (string col);
		string getColor (void);
		// This function could be declared outside the class body just like\
		// the other functions
		// Function to calculate the area of the box's base
		double baseArea (void) {
			return length * width;
		};
		// Define setter and getter functions for the box name
		void setBoxName (string box_name) {
			boxName = box_name;
		};
		string getBoxName (void) {
			return boxName;
		};
		// Function to return the value of the pointer created in the class\
		// constructor
		string returnPtr (void) {
			return *ptr;
		}

	// The color of the box will be private, that is, it can only be modified\
	// with friend functions (or inside the class itself)
	private:
		// The color member is declared with an initial value of `green`
		string color = "green";
		// Declare a member for the name of the box (private as well since it\
		will only be accessed or modified using getter and setter functions)
		string boxName;
		// Declare a new pointer to be used to point to the `boxName` member
		string* ptr;
};

// Definition of member functions (these could be defined inside the class body\
// just like `baseArea()`)
// Setter function for the color
void Box::setColor (string col) {
	color = col;
}
// Getter function for the color
string Box::getColor (void) {
	return color;
}
// Definition of the class constructor, destructor and copy constructor outside the\
// class body
/*
// Example of a class constructor defined outside the class body
Box::Box (string box_name) {
	boxName = box_name;
}
// Example of a class destructor defined outside the class body
Box::~Box () {
	cout << boxName << " has been destroyed.\n";
}
// Example of a class copy constructor defined outside the class\
// body
Box::Box (const Box &obj) {
	ptr = new string;
	*ptr = *obj.ptr;
	cout << "A copy of the object has been created.\n";
}
*/


// Create a function (not related to the definition of the `Box` class) to print\
// the name of a given `Box` object. The function receives a `Box` object as an\
// argument and then calls one of its methods to obtain the object's `boxName`
void printBoxName (Box obj) {
	cout << "This function is copying the box " << obj.returnPtr() << ".\n";
}


int main() {
	// Create a new `Box` object called `myBox`
	Box myBox("myBox");
	// ---------------------------------------------------------------------------------------------

	// This raises an error since `brand` is a private member
	// cout << myBox.brand << "\n";
	// Set the dimensions of the new box
	myBox.length = 5.9;
	myBox.width = 2.0;
	myBox.height = 4.5;
	// Save the name of the box (`boxName` member) in a new string
	string nameOfMyBox = myBox.getBoxName();
	// Calculate the volume of the box and save it in a new variable
	double volume = myBox.length * myBox.width * myBox.height;
	// Output a couple of informations of the object
	cout << "The " << myBox.getColor() << " box " << nameOfMyBox << " has a volume of " << volume << " units.\n";
	// Output the area of the base of the box (the returned value of the member function `baseArea()`)
	cout << "The base of " << nameOfMyBox << " has " << myBox.baseArea() << " units of area.\n";
	// ---------------------------------------------------------------------------------------------

	// Set the color of the box using the defined member function (thus overwritting the\
	// default value of `green`)
	myBox.setColor("blue");
	cout << "Changed my mind, now " << nameOfMyBox << " is " << myBox.getColor() << ".\n";
	// ---------------------------------------------------------------------------------------------

	// Call the `printBoxName()` function to print the name of a `Box` object. The function receives\
	// a `Box` object as an argument, rather, a copy of that object created with the class' copy\
	// constructor. Then it obtains the object's `boxName` through a class member function
	printBoxName(myBox);
	// ---------------------------------------------------------------------------------------------


	// If not deleted before, `myBox` will be deleted at the end of program, thus triggering\
	// the class' destructor (it is also called once the copy of `myBox` created by passing the\
	// object to the `printBoxName()` function is deleted, i.e., when the function ends)

}