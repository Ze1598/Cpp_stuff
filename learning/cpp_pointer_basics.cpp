// This file goes over the basics of pointers creation and referencing
#include <iostream>
using namespace std;

/*
	& -> prefixed to a variable to denote the variable is refering to an address
in memory (hence it's called the address of operator)
	* -> prefixed to a variable to denote the variable is refering to the value
held at the address in memory of said variable (hence it's called the dereference
operator)
	type * pointerName -> to define a pointer, first state the type of the value
to which it will point, followed by an asterisk (it's just syntax, not to be
confused with the dereference operator), followed by the name of the pointer.
*/

int main() {
	// Declare int variables
	int a = 2;
	int b = 3;
	int c;

	// Declare a new int pointer
	int * myPointer;
	// Point `myPointer` to the address of `a`
	myPointer = &a;
	// Since `myPointer` is pointing to the address of `a`, assigning the value\
	// of the address (*) to 5 means `a` now has a value of 5 as well
	*myPointer = 5;
	cout << "Value of `a`: " << a << "\n";
	// Prefix `myPointer` with the asterisk otherwise `myPointer` outputs the\
	// address it points to
	cout << "Current value of `myPointer`: " << *myPointer << "\n";
	
	// Now point `myPointer`to the address of `b`
	myPointer = &b;
	// Assign the value of the current address of `myPointer` (which is the\
	// address of `b`) the value of 1574
	*myPointer = 1574;
	cout << "Value of `b`: " << b << "\n";
	cout << "Current value of `myPointer`: " << *myPointer << "\n";

	// Declare a second pointer
	int * myPointer2;
	// Point `myPointer` to the address of `c`
	myPointer = &c;
	// Point `myPointer2` to the address `myPointer` points to (the address of `c`)
	myPointer2 = myPointer;
	// Assign the address `myPointer` points to the value of 0 (this modifies the\
	// value of `b` and `*myPointer` since they are all stored in the same address)
	*myPointer2 = 0;
	// Even though `c` was never initialized directly, since `myPointer2` modified\
	// the value of its address, `c` currently holds that value
	cout << "Value of `c`: " << c << "\n";
	cout << "Current value of `myPointer`: " << *myPointer << "\n";
	cout << "Current value of `myPointer2`: " << *myPointer2 << "\n\n";


	// Declare a five-integer array
	int numbers[5];
	// Declare a new int pointer
	int * p;
	// Point `p` to `numbers` (remember that an array can be used as a pointer to\
	// its first element)
	// Note: arrays can always be implicitly converted to a pointer of the proper\
	// type (int in this case)
	p = numbers;
	// Since `p` is now pointing to `numbers`, which itself points to its first\
	// item, we can change its value like this
	*p = 10; // Equivalent to numbers[0] = 10;
	// `p` now points to the next address (which is the second value of `numbers`)
	p++;
	*p = 20; // numbers[1] = 20;
	// Make `p` point directly to the address of `numbers`' third element
	p = &numbers[2];
	// And change its value (numbers[2] = 30;)
	*p = 30;
	// Now make `p` point to the third address after the address of (the first\
	// element of) `numbers` (effectively,point to the fourth element of `numbers`)
	p = numbers + 3;
	*p = 40; // numbers[3] = 40;
	// Point `p` back to numbers (' first element) again
	p = numbers;
	// Change the value at the address four addresses after `numbers` (effectively,\
	// the value of the fifth element of `numbers`)
	*(p+4) = 50; // numbers[4] = 50;
	// Output the contents of `numbers`
	for (auto i=0; i<5; i++) {
		cout << "numbers[" << i << "]: " << numbers[i] << ", ";
	}
}