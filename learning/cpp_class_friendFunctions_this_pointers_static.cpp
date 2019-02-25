// This file goes over friend functions, the `this` keyword, class pointers
// and `static` members (variables and functions)
#include <iostream>
#include <string>
using namespace std;

/*

Friend functions (or classes) of a class are functions that, while not
being part of a class, still have access to their private and protected
members. To qualify a function as a friend function of a class, simply
add the `friend` keyword to the function prototype in the class body.
	class ExampleClass {
		typeMember1 member1;
		typeMember2 member2;
		...
		friend void friendFunction (ExampleClass exampleClassObj);
	}

	void friendFunction (ExampleClass exampleClassObj) {
		cout << exampleClassObj.member1;
	}
The above `friendFunction()` while not being part of the `ExampleClass`
class, can still access its private `member1` member because it is
qualified as a friend function.


The `this` keyword works as a pointer to the object whose member function
is being executed. Thus, `this` is used within a class' member function
to refer to the object itself. To access members of the object when using
`this`, the arrow operator (->) must be used.
	class sampleClass {
		paramType param = sampleValue;

		public:
			void printParam (void) {
				cout << "The value of `param` is: " << this->param << "\n";
			}
	};
	sampleClass sampleObj;
	sampleObj.printParam();


Class pointers work in the exact same way as they work for data structures.
	class sampleClass {
		public:
			paramType param = sampleValue;
	};
	sampleClass sampleObj;
	sampleClass* samplePointer;
	samplePointer = &sampleObj;
	cout <<< "`sampleObj` `param`: " << samplePointer->param << "\n";

Static members are member variables of a class whose value is shared by all objects
of the class. A static member is also known as a class variable and cannot be
initialized inside the class body. These members can even be called by the class
itself. Do note both member variables and member functions can be `static`.
	class sampleClass {
		public:
			int n;
			sampleClass () {
				n++;
			}
	};
	sampleClass::n = 0;
	sampleClass sampleObj1;
	sampleClass sampleObj2;
	cout << sampleClass::n << "\n"; // 2

*/

class Box {
	string boxName;
	double width;
	double length;
	double height;

	public:
		// Static member to be be incremented everytime a new `Box` object is created
		static int creationCounter;

		// Class constructor
		Box (string name, double w, double l, double h) {
			boxName = name;
			width = w;
			length = l;
			height = h;

			// Increment the static member
			creationCounter++;
		}

		// Function to calculate the volume of a `Box` object
		double boxVolume () {
			return width * length * height;
		}

		// Function to compare the volume of the current `Box` object and\
		// another `Box` received as input
		void compareVolume (Box boxObj) {
			double thisVol = this->boxVolume();
			double inputVol = boxObj.boxVolume();

			if (thisVol > inputVol) {
				cout << this->boxName << " has more volume than " << boxObj.boxName << "\n";
			}
			else if (thisVol < inputVol) {
				cout << this->boxName << " has less volume than " << boxObj.boxName << "\n";
			}
			else {
				cout << this->boxName << " has the same volume as " << boxObj.boxName << "\n";
			}

		}

		// Function to get the current value of the `static` member variable\
		// `creationCounter`
		static int getCreationCounter (void) {
			return creationCounter;
		}

		// Qualify `sampleFriendFunction()` as a friend function. It\
		// receives a `Box` object as input and then outputs the object's\
		// `boxName`
		friend void sampleFriendFunction (Box obj);
};
// Initialize the `static` member variable
int Box::creationCounter = 0;

// Receives a `Box` object as input and then outputs the object's `boxName`
// Note this function is does not belong to the `Box` class
void sampleFriendFunction (Box obj) {
	cout << "This `Box` object is called " << obj.boxName << "\n";
}


int main() {

	// Friend functions example
	// ----------------------------------------------------------------------------------
	
	// Create a `Box` object
	Box myBox1("myBox1", 1.5, 2.0, 3.3);
	// Now call the class' friend function to print the box's name
	sampleFriendFunction(myBox1);
	
	// ----------------------------------------------------------------------------------


	// `this` keyword example
	// ----------------------------------------------------------------------------------

	// Create another `Box`
	Box myBox2("myBox2", 4.0, 5.7, 1.0);
	// Now call the class' friend function to print the box's name
	sampleFriendFunction(myBox2);
	// Compare the volume of `myBox2` to that of `myBox1`
	myBox2.compareVolume(myBox1);

	// ----------------------------------------------------------------------------------


	// Class pointer example
	// ----------------------------------------------------------------------------------

	// Create a pointer to a `Box` object
	Box* myPtr = &myBox1;
	cout << "`myBox1` volume accessed through a pointer: " << myPtr->boxVolume() << "\n";
	
	// ----------------------------------------------------------------------------------


	// `static` members example
	// ----------------------------------------------------------------------------------

	// Since two `Box` objects have been created so far, the static `creationCounter` member\
	// must have a value of 2 by now
	// Because this is a static member (or a class variable) it can be accessed by the class name
	cout << "Number of `Box` objects created (using `static` member variable through the class itself): " << Box::creationCounter << "\n";
	// Same rules apply here, but this time we are accessing a `static` member function instead\
	// (which gets the value of the `creationCounter` member)
	cout << "Number of `Box` objects created (using `static` member function through the class itself): " << Box::getCreationCounter() << "\n";
	// Access the `static` member variable using an object
	cout << "Number of `Box` objects created (using `static` member variable through `myBox1`): " << myBox1.creationCounter << "\n";
	// Access the `static` member function using an object
	cout << "Number of `Box` objects created (using `static` member function through `myBox2`): " << myBox2.getCreationCounter() << "\n";

	// ----------------------------------------------------------------------------------

	return 0;
}