// This file goes over the definition of type aliases, the creation of unions
// and the creation of enumerated types
#include <iostream>
#include <string>
using namespace std;


/*
Type aliases allow you to use C++ data types by other names. To define a new
type alias, the syntax is:
	typedef existingType newTypeName;
This does not change the name of the original data type, it simply creates a
synonym for it which can be used anytime. Alternatively, a type alias can
be created with the `using` keyword:
	using newTypeName = existingType;
`typedef` and `using` are equivalent, it's just a matter of syntax (though
`typedef` has certain limitations in the context of templates).
After defining a new type alias, it can be used just like any other data type.


Unions allow a single portion of memory to hold various values of different
data types. It works similarly to data structures except here the union sets
that a portion of memory for a set of values. However, due this means it can
only save one value at any given time. The syntax to define an union is:
	union unionName {
	member1Type member1Name;
	member2Type member2Name;
	member3Type member3Name;
	...
	}
So, for example, if you have a union such as this
	union myUnion {
		int a;
		double b;
		string c;
	}
And you want to use an `int` value, then set the value of `a` (`myUnion.a`) and
use it however you need before setting `b` or `c`; otherwise `myUnion` will no
longer hold an `int` value (until you set `a` once again).
If a union is created in the context of a class or data structure, it can be
created without a name (hence called an anonymous union).
	struct book2_t {
		string title;
		string author;
		union {
			float dollars;
			int yen;
		};
	} book2;
While this means both the `dollars` and the `yen` members can be accessed in the
same way as the other members, don't forget these two share the same memory
location, thus only one of them can defined at any given time.


It is also possible to create enumerated types, types defined with a set of values:
	enum typeName {
		value1,
		value2,
		value3,
		...
	};
This creates the type `typeName` which can have a value of `value1`, `value2`, 
`value3`, etc. Given a real example
	enum colors {white, black, blue};
`colors` can have a value of `white`, `black` or `blue`. Internally, each value,
is assigned an integer (almost like an index in an array), with the first value
equating to 0, the second to 1, and so on. It's possible to set these integers
values. For example, if we recreate `colors`:
	enum colors {white=1, black, blue};
Instead, the first value now is equivalent to 1 and, since the remaining values
are not specified, it is assumed that for `black` the integer is incremented by
1 (2) and for `blue` it is incremented once again (3). Thus, colors can have a
value of `white`, `black` or `blue`, or their equivalents, 1, 2 or 3.
*/


int main() {

	// Define `integer` as an alias for the `int` data type
	typedef int integer;
	// Create an `integer` (`int`) variable
	integer myAliasInt = 8;
	cout << myAliasInt << "\n\n";


	// Create a union which is able to store three different data types: int,\
	// double or char
	union sampleUnion {
		int a;
		double b;
		char c;
	};
	// Create an union variable of data type `sampleUnion`
	union sampleUnion myUnion;
	// Set an `int` value for the variable and print it
	myUnion.a = 7;
	cout << "myUnion `int` value: " << myUnion.a << "\n";
	// Set a `double` value for the variable and print it
	myUnion.b = 10.5;
	cout << "myUnion `double` value: " << myUnion.b << "\n";
	// After setting a `double`, try to print the `int` value once again (bad idea)
	cout << "myUnion `int` value after setting `double`: " << myUnion.a << "\n";
	// Set a `char` value for the variable and print it
	myUnion.c = 'c';
	cout << "myUnion `char` value: " << myUnion.c << "\n";
	cout << "\n";

	// Create a data structure that contains a union as a member
	// Note that while it has both a `dollars` and a `yen` member, only one of them\
	// can be defined at any given time because they are defined inside a union
	struct book {
		string title;
		string author;
		// Since it is inside a data structure, the union can remain nameless, that\
		// is, it is an anonymous union
		union {
			float dollars;
			int yen;
		};
	};
	// Create a new `book` object and set values for all its members
	book myBook;
	myBook.title = "My Book";
	myBook.author = "Me";
	// Here we choose to define the value of the `dollars` member and not the `yen` member
	myBook.dollars = 7.99;
	// Print all the information of `myBook`
	cout << "The book " << myBook.title << " written by " << myBook.author << " costs " << myBook.dollars << "\n\n";


	// Create an enumerated type, whose first value starts with an integer of 1
	enum colors {
		white=1,
		black,
		blue
	};
	// Create a new `colors` variable and assing it a value of `black`
	colors myColor = black;
	// If the color of `myColor` is `black` (which, as an integer, is represent with 2), then
	// print that value
	if (myColor == 2) {
		// If we print the variable itself it will print the integer representation (2)
		cout << "myColor: " << "black" << "\n";
	}

}