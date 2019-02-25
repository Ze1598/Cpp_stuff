/*
This file covers variable declaration and initialization, user input,
output and flow control (if/else, switch/case and loops (including 
the `break` and `continue` statements))
*/

#include <iostream>
#include <string>
// This using declaration allows all elements in the `std` namespace to\
// be accessed in an unqualified manner (i.e., without the `std::` prefix)
// using namespace std 

int main() {
	// This is a single-line comment
	/* This is a multi-line
	comment */

	// Variable declaration and initalization
	// ---------------------------------------------------------------------------------------
	
	// Declare a variable
	double a;
	// Initialize a declared variable (c-like initalization)
	a = 3.14;
	// Declare and initialize a variable (constructor initalization)
	std::string b ("Hello");
	// Type cast (convert) `a` to int and save the result in a new variable
	int c = int(a);
	// Chain outputs
	std::cout << a << " " << b << "\n";
	// Get the size, in bytes, of `b`
	std::cout << sizeof(b) << "\n";
	// Output `c`
	std::cout << c << "\n\n";

	// ---------------------------------------------------------------------------------------


	// Define constants (`#define` and `const`)
	// ---------------------------------------------------------------------------------------

	// In C++, constants can be defined either using the `#define` preprocessor or the `const`\
	// keyword
	
	// `#define identifier value` (no semi-colon at the end)
	#define myConst1 10
	#define myConst2 3
	std::cout << "myConst(1,2) product: " << myConst1 * myConst2 << "\n";

	// const valueType identifier = value;
	const std::string myConst3 = "a";
	const std::string myConst4 = "b";
	std::cout << "myConst(3,4) concatenation: " << myConst3 + myConst4 << "\n";


	// ---------------------------------------------------------------------------------------


	// Selection statements (Conditionals): if/else
	// ---------------------------------------------------------------------------------------

	// Write a conditional clause to evaluate the `cond_var` variable
	int cond_var = 10;
	if (cond_var < 10) {
		std::cout << "Less than 10\n";
	}
	else if (cond_var > 10) {
		std::cout << "More than 10\n";
	}
	else {
		std::cout << "Ten\n";
	}

	// Write a conditional ternary operator to evaluate the `cond_var2` variable
	int cond_var2 = 7;
	// If `cond_var2` is bigger than five then output 5, else output 7
	std::cout << ( (cond_var2 > 5) ? 5 : 7) << "\n\n";

	// ---------------------------------------------------------------------------------------


	// Input
	// ---------------------------------------------------------------------------------------
	
	// To get input which is made up of more than one word, number, ..., that has\
	// spaces, use getline(cin, <save_input_var>) to get the whole line of input
	std::string input_str;
	std::cout << "Give me a full name: ";
	getline(std::cin, input_str);
	std::cout << "Your name is " << input_str << "\n";

	// Save multiple values from a single input
	int input_a;
	int input_b;
	std::cout << "Give me two numbers: ";
	// In this case, the program is looking for two inputs: it can either be two\
	// space-separated values (each one will be saved in a different variable) or\
	// two separate inputs. If more than two values are given in a single input,\
	the remaining values will be saved for following input prompts in the program...\
	// (because right here we can only save two values)
	std::cin >> input_a;
	std::cin >> input_b;
	std::cout << "First number: " << input_a << " Second number: " << input_b << "\n\n";

	// ---------------------------------------------------------------------------------------


	// Selection statements (Conditionals): switch/case
	// ---------------------------------------------------------------------------------------

	// Write a switch-case clause for the `pokedex` variable
	int pokedex = 4;
	switch(pokedex) {

		// pokedex == 1
		case 1:
			std::cout << "Bulbasaur\n\n";
			break;

		// pokedex == 4
		case 4:
			std::cout << "Charmander\n\n";
			break;

		// pokedex == 7
		case 7:
			std::cout << "Squirtle\n\n";
			break;

		// else (optional)
		default:
			std::cout << "Unknown\n\n";
			break;
	}

	// ---------------------------------------------------------------------------------------


	// Loops: while
	// ---------------------------------------------------------------------------------------

	// Write a while loop
	// Variable to be used for user input
	int guess;
	// Number of tries (equivalent to the number of loop iterations\
	in this case)
	int tries = 0;
	std::cout << "Please guess a number between 1-10 in ten or less tries: ";
	std::cin >> guess;
	std::cout << "\n";
	// Keep the loop running while the user doesn't guees the number 8 and\
	it has used less than three guesses (tries)
	while (guess != 8 && tries < 3) {
		std::cout << "Wrong guess, try again: ";
		std::cin >> guess;
		tries++;
		std::cout << "\n";
	}
	std::cout << "\n\n";

	// ---------------------------------------------------------------------------------------


	// Loops: do-while
	// The do-while loops are preferred over a while loop when the statements inside the loop\
	// need to be executed at least once before verifying the condition
	// ---------------------------------------------------------------------------------------

	do {
		std::cout << "DO-WHILE\n\n";
	} while (1 > 2);

	// ---------------------------------------------------------------------------------------


	// Loops: for
	// ---------------------------------------------------------------------------------------

	// Write a for loop to print the integers from 0 to 9
	for (int i=0; i < 10; i++) {
		std::cout << "i: " << i << "\n";
	}
	std::cout << "\n\n";

	// ---------------------------------------------------------------------------------------


	// Loops: range-based for loop

	// ---------------------------------------------------------------------------------------

	// Loop through all the elements in a range, in this case, all the characters in the\
	// `b` string. Each iteration, the element is saved in a temporary variable `letter`,
	// which makes use of the `auto` type (i.e., it deducts automatically the correct\
	// type to use, which is `char` in this case (a single character from a string))
	for (auto letter : b) {
		std::cout << letter << "\n";
	}
	// ---------------------------------------------------------------------------------------


	// Loop statements
	// ---------------------------------------------------------------------------------------

	// break statement: leave a loop prematurely, instead of waiting\
	// for the loop condition to end/return false
	int break_counter = 0;
	while (true) {
		std::cout << "break_counter: " << break_counter << "\n";
		// break out of this infinite loop if this is the third\
		// iteration
		if (break_counter == 2) {
			break;
		}
		break_counter ++;
	}


	// continue statement: causes a loop to skip the rest of the current\
	// iteration to start the next one right away
	for (int i=0; i<5; i++) {
		// If `i` is even then skip the rest of the loop and start\
		// the next iteration
		if (i%2 == 0) {
			continue;
		}
		// If `i` is odd, then the loop reaches this point and outputs\
		// a message
		std::cout << "i: " << i << "\n";
	}

	// ---------------------------------------------------------------------------------------

	std::cout << "\nEND;\n";
}