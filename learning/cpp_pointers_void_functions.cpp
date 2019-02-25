// This file goes over void pointers, function pointers and inline functions
#include <iostream>
#include <string>
#include <array>
using namespace std;

/*
	Note: the increment/decrement (++/--) operators can be prefixed or sufixed to
an expression. When prefixed, the operation happens before the expression is
evaluated; when suffixed, the operation happens after the expression is evaluated
(e.g. for `a=5;`, `a = ++a*2;` results in 12 ((5+1)*2). but `a= a++*2;` results
in 11(5*2+1)).

	Pointers are subject to two operations only: incrementation and decrementation.
Both these operations are responsible for changing the memory locations the pointers
point to. Thus, pointers can be combined with the increment (++) and decrement (--)
operators to create the following scenarios:
		*p++ -> increment the pointer and dereference the unincremented address
		*++p -> increment the pointer and dereference the incremented address
		++*p -> dereference the pointer and increment the value it points to
		(*p)++ -> dereference the pointer and post-increment the value it points to 
For example, given `*p++ = *q++;`, what happens is that `*p` is assigned the value of 
`*q` before being incremented, and then both `p` and `q` are incremented.
	
	To create a read-only pointer, qualify it upon declaration with `const`. However,
this only means the pointer can't modify the contents of the address it points to., i.e.,
the pointer itself can be changed (incremented or decremented). To make the pointer itself
const, use `const` before the name of the pointer:
		const int * pointer1; // Pointer that can only read pointed values but can be
modified itself.
		const int * const pointer1; // Pointer that can only read pointed values and can't
be modified.
Note that for the pointer to be const, it doesn't require that the pointer is also
const-qualified (i.e., the second `const` can be used without the first one).

	Pointers can also point to other pointers, which, in turn, point to other data or even
other pointers. When declaring a pointer, include an asterisk (*) for each level of
indirection (e.g., for a char pointer `p` that points to pointers which always point to data
declare `p` as `char ** p`).


	Inline functions are functions that the compiler substitutes the function call for the
actual function body whenever the function is called at compile time. Note class functions
are inline functions by default. To qualify a function as inline, simply prefix the function
with `inline` upon declaration:
	inline int myFunction (paramaters) {
		function body
	};
*/


// Function to print the integer passed through a void pointer
void printNum(void * argPointer) {
	// Use a void pointer for the sole parameter of the function
	// Then create a new int pointer, which casts the type of void\
	// of `argPointer` to int (void pointers can't be dereferenced\
	// on their own)
	int * typedPointer = (int *)argPointer;
	// Output the value of the pointer passed as argument
	cout << "typedPointer value: " << *typedPointer << "\n";
}


// Add two numbers
int addition (int a, int b) {
	return (a+b);
}
// Subtract two numbers
int subtraction (int a, int b) {
	return (a-b);
}
// Receive three parameters: two integers and a function. The function\
// is received as a pointer so that the function can then be called\
// inside this function
int operation (int x, int y, int (*functocall)(int,int)) {
	// This variable will hold the result of calling the function passed\
	// as an argument
	int g;
	// Call the function, passing as arguments the arguments that were passed\
	// to this function itself originally
	// When dereferencing a function, the name should prefixed by an asterisk\
	// and enclosed in parentheses
	g = (*functocall)(x,y);
	return (g);
}


// Whenever a call to this function appears, the compiler will substitute the call\
// by the whole function
inline int maxNum (int x, int y) {
	return (x > y)? x : y;
};


int main () {
	int a = 5;
	// `myPointer` cannot modify the value of the address it points to, i.e., it\
	// cannot modify `a`
	const int * myPointer = &a;
	// This raises an error since `myPointer` was declared with `const`
	// *myPointer = 6;

	// Create another pointer to `a`
	int * myPointer2 = &a;
	// Create a new pointer which points to pointers that point to data
	// Make this new pointer point to the address of the `myPointer2` pointer
	int ** lvl2Pointer = &myPointer2;
	// To find the actual data `lvl2Pointer` points to, dereference it twice:\
	// once for itself and another for `myPointer2`; this will access the value\
	// of `a`, which where `myPointer2` points
	cout << "lvl2Pointer: " << **lvl2Pointer << "\n";

	// Create a sample variable
	int voidSample = 10;
	// Create a void pointer
	void * voidPointer;
	// Point `voidPointer` to `voidSample`
	voidPointer = &voidSample;
	// Create a new int pointer to use the void pointer with
	int * newPointer;
	newPointer = (int *)voidPointer;
	cout << "newPointer value: " << *newPointer << endl;
	// Call the function to print the value of a variable by giving it an\
	// address to be used by the function's pointers
	printNum(&voidSample);

	// Declare a pointer to the `subtraction` function
	int (*minus)(int,int) = subtraction;
	// Declare two variables to hold the results of calling two functions
	int m,n;
	// Use this to call the `addition` function with 7 and 5 as parameters
	m = operation(7, 5, addition);
	cout << "m=operation(7, 5, addition): " << m << "\n";
	// Use this to call `minus`, that is, `subtraction` with parameters 20
	// and `m`
	n = operation(20, m, minus);
	cout << "operation(20, m, minus): " << n << "\n";

	// Call an inline function three times
	cout << "maxNum (20,10): " << maxNum(20,10) << "\n";
	cout << "maxNum (0,200): " << maxNum(0,200) << "\n";
	cout << "maxNum (100,1010): " << maxNum(100,1010) << "\n";
}