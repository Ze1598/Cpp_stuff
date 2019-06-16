// This file goes over operator overloading
/*
Overloading can be extended to operators, specifically, most of C++'s
built-in operators. This allows the redefinition of the behavior of
the overloaded operator.
To overload an operator, we use the same syntax as in a function (method)
prototype, but follow the return type with the `operator` keyword and the
operator to be overloaded (+, -, *, /, %, &, etc.), which are then followed
by the function parameters.
For example, this is an example of how to overload the addition operator (+):
	myClass operator+ (myClass &obj) {
		return this->mem + obj.mem;
	}
*/

#include <iostream>
using namespace std;

// Create a class to represent a square (used for the operator overload/
// example)
class Square {

	public:
		// The side of the square
		double side;
		
		// When a new object is created, pass to it a length for the side	
		Square (double side_) {
			side = side_;	
		}

		// Overload the `+` operator so that when it is used with a Square\
		// object it adds up the sides of the two Squares and creates and\
		// returns a new Square with a side of that resulting length
		Square operator+ (Square& a) {
			// Sum the length of the sides of both squares
			double newSquareSide = this->side + a.side;
			// Create the new Square
			Square returnSquare(newSquareSide);
			return returnSquare;
		}

};
// --------------------------------------------------

// Abstract base clases to create derived classes (used for the\
// polymorphism example)
class Polygon {
	protected:
		int width, height;
	public:
		Polygon (int a, int b) : width(a), height(b) {}
		void setValues (int a, int b) {
			width = a;
			height = b;
		}
		// Responsible for making this an abstract base class (because\
		// this is a virtual function not defined)
		virtual int area() =0;
		// When this function is called, it will then call the `area()` method\
		// of the derived classes
		void printArea () {
			cout << this->area() << endl;
		}

};

class Rectangle: public Polygon {
	public:
		// Class constructor (it creates a new Polygon object with the passed\
		// parameters)
		Rectangle (int a, int b) : Polygon(a, b) {}
		// Accesses the member variables of the Polygon base class
		int area () {
			return width*height;
		}
};

class Triangle: public Polygon {
	public:
		// Class constructor (it creates a new Polygon object with the passed\
		// parameters)
		Triangle (int a, int b) : Polygon(a, b) {}
		// Accesses the member variables of the Polygon base class
		int area () {
			return (width*height) / 2;
		}
};

int main() {
	// Operator overload example
	// ------------------------------------------------------------------------

	// Create two squares
	Square a(5);
	Square b(7);
	// Add the length of the sides of the two squares to create a new Square
	Square c = a + b;
	cout << "Square c has a side of length " << c.side << endl << endl;

	// ------------------------------------------------------------------------

	// Polymorphism example
	// ------------------------------------------------------------------------

	// Create pointers of type Polygon to point towards a Rectange and a Triangle\
	// objects, respectively
	Polygon* pPoly1 = new Rectangle(4, 5);
	Polygon* pPoly2 = new Triangle(7, 2);
	// Then, access the `printArea()` methods of the Polygon class to print\
	// their areas (this method actually accesses the `area()` method of the\
	// Rectangle and Triangle classes)
	pPoly1->printArea();
	pPoly2->printArea();
	// Delete the pointers
	delete pPoly1;
	delete pPoly2;

	// ------------------------------------------------------------------------

	return 0;
}