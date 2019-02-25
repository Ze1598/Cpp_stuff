// This file goes over class inheritance
#include <iostream>
#include <string>
using namespace std;

/*
A derived class is a class that uses another class as its base,
hence having access to the base class' public and protected
members. To create a derived class, use:
	class DerivedClass: baseClassAccessMod BaseClass {
		derived class body
	};
To inherit multiple classes, use:
	class DerivedClass: baseClassAccessMod1 BaseClass1, baseClassAccessMod2 BaseClass2, ... {
		derived class body
	};
A derived class inherits everything of the base class except its
constructor, copy constructor, destructor, overloaded operators
and friend functions.
A note about the access modifier of base classes: when set to
public, the access modifiers of the base class' members are
tranfered as is; when set to protected, public and protected
members of the base class become protected members of the derived
class; and when set to private, public and protected members of
the base class become private members of the derived class.
*/

class Square {

	// Derived classes have access to these
	public:
		// Setter for `length` and `width`
		void setDims (int l, int w) {
			length = l;
			width = w;
		};
		// Setter for `name`
		void setName (string sqName) {
			name = sqName;
		};
		// Getter for `name`
		string getName (void) {
			return name;
		}

	// Derived classes have access to these
	protected:
		int length;
		int width;

	// Derived classes don't have direct access to these
	private:
		// While the derived class won't get direct access to this member,\
		// it can still get its value using the respective public getter
		string name;
};

class Style {
	public:
		string color;
};

// Create a derived class of `Square` and `Style`. We set the access modifiers of\
// both base classes to public, so its access modifiers are inherited as is
class Cube: public Square, public Style {
	public:
		// Setter for `height`
		void setHeight (int h) {
			height = h;
		};
		// Function to calculate the volume of the cube (`length` and `width`\
		// are inherited protected member variables of the base class `Square`)
		int volume () {
			return length * width * height;
		};
		void setColor (string c) {
			color = c;
		}

	private:
		int height;
};



int main() {

	// Create a `Cube` object
	Cube myCube;
	// Use a public setter function of the `Square` base class for `length`\
	// and `width`
	myCube.setDims(5, 10);
	// Use a public setter function of the `Cube` derived class for `height`
	myCube.setHeight(7);
	// Access a public setter function of the `Square` base class for `name`
	myCube.setName("myCube");
	// Output the `Cube`'s name and volume (`getName()` is a public getter from\
	// the base class and `volume()` is a public function from the derived class)
	cout << "The volume of " << myCube.getName() << " is " << myCube.volume() << "\n";
	// Set the color of `myCube` (by accesing the public member variable of the base\
	// class `Style`)
	myCube.setColor("blue");
	// I purposely did not create a getter function for `color` to show that the derived\
	// class `Cube` has access to the public member `color` of the base class `Style`
	cout << myCube.getName() << " is " << myCube.color << "\n";


	return 0;
};