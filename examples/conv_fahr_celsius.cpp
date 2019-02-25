#include <iostream>


int main() {
	// Declare a double variable (floating-point numbers)
	double user_temp;
	// Output a message to prompt the user for input
	std::cout << "Give me a temperature, in Fahrenheit: ";
	// Actually receive the input
	std::cin >> user_temp;
	// Be careful with mixing int and double variables in divisions!!!
	// Convert the user's Fahrenheit degrees to Celsius
	double user_temp_celsius = (user_temp - 32) * (5.0 / 9.0);
	// Finally, output the converted temperature
	std::cout << "Your " << user_temp << " degree Fahrenheit are converted to " << user_temp_celsius << " degree Celsius.\n\n";
}