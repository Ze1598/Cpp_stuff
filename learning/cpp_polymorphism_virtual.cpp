// This file goes over polymorphism in C++
/*
Polymorphism means "having many forms". In the context of C++, this is
realized in the sense that a call to a member function will cause a
different function to be executed, depending on the type of object
that calls the function.

Another way of implementing polymorphism is using the `virtual` keyword
when declaring a new member function for the base class. Put simply,
add the `virtual` keyword to the target function's declartion in the base
class. Then, create a corresponding (with the same name) member function
in the inherited class.
	class BaseClass {
		public:
			virtual void virtualFunction (void) {
			}
	}
	class InheritedClass : public BaseClass {
		public:
			virtualFunction (void) {
				do something here
			}
	}
Virtual functions that are simply declared, are called pure virtual functions,
as it is expected that derived classes handle the function definition. In
these cases, the syntax is slightly different:
	virtual void virtualFunction() =0;
However, including a pure virtual function in a class makes it an abstract
class. Because of this, it then becomes ilegal to create objects for that
class.

For the following example, we'll use classes to represent enemy types in a
videogame. Each enemy has its own class implementation but, since they are
all enemies, they all inherit from the same class: `Enemy`.
*/

#include <iostream>
using namespace std;

// The base class from which all the enemies will inherit
class Enemy {
	protected:
		int attackPower;
	public:
		void setAttackPower (int a) {
			attackPower = a;
		}
		// Even though this same function is available to the inheriting\
		// classes, they have their own implementation of the function
		virtual void attack (void) {
			cout << "Enemy attack!" << endl;
		};

		// Here is a pure virtual function that is expected to be defined by\
		// the derived classes
		// virtual void printClassName() =0;
};

class Ninja : public Enemy {
	public:
		void attack (void) {
			cout << "Ninja - " << attackPower << endl;
		}
		// Here's the definition of what was a pure virtual function in the\
		// base class
		// void printClassName (void) {
		// 	cout << "Ninja!" << endl;
		// }
};

class Monster : public Enemy {
	public:
		void attack (void) {
			cout << "Monster - " << attackPower << endl;
		}
		// Here's the definition of what was a pure virtual function in the\
		// base class
		// void printClassName (void) {
		// 	cout << "Monster!" << endl;
		// }
};

int main() {
	// Create an object for each enemy type
	Ninja n;
	Monster m;
	Enemy e;
	// Create a pointer of the base class type that points to the Ninja and the\
	// Monster, respectively, as well as one for the base `Enemy`
	Enemy* e1 = &n;
	Enemy* e2 = &m;
	Enemy* e3 = &e;

	// Even though we are calling the same method of the Enemy class, since\
	// the pointers are pointing to objects of different types, the methods\
	// are executed for different classes (types)
	// In other words, while we could have called the methods directly on\
	// the objects, using pointers is more efficient and it demonstrates\
	// that we can use pointers of the base class type without knowing what\
	// is the data type of the object the pointer points to
	e1->setAttackPower(20);
	e2->setAttackPower(40);
	e3->setAttackPower(10);

	// This method will have different results for each call since it is\
	// called by different classes
	n.attack();
	m.attack();
	e.attack();

	// The pointers can, even if they are of the Base class' type, call\
	// the virtual member function `attack()` of the derived classes used\
	// by the variables they are pointing to, that is, each pointer calls\
	// the appropriate implementation of `attack()` depending on the type of\
	// data type the pointer points to
	e1->attack();
	e2->attack();
	e3->attack();

	// Call what was originally a pure virtual function in the base class but\
	// was later defined by the derived classes
	// n.printClassName();
	// m.printClassName();

	return 0;
};