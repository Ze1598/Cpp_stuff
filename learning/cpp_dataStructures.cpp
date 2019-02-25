// This file goes over creating new data structures, including nested
// data structures, how to access its members and how to pass them as
// function arguments
#include <iostream>
#include <string>
#include <sstream> // stringstream()
using namespace std;

/*
To create a new data structure, use
	struct dStructureName {
		member1Type member1Name;
		member2Type member2Name;
		member3Type member3Name;
		...
	}

Pointers can also point to data structures. Given a pointer `myPointer`
which points to an object `objectA` of a data structure `myDStructure`,
use the usual syntax to create the pointer, except the data type will be
the data structure:
	myDStrucutre * myPointer;
	myPointer = &objectA;
Then, for the pointer to access the members of the object, the arrow (`->`)
operator is used. If `myDStructure` has a `year` member, it can be accessed
by the pointer as:
	myPointer -> year = 2019;
	(which is the same as `(*myPointer).year = 2019;` )
The arrow operator is a dereference operator to access the members of an
object a pointer points to.
*/

// Create a new structure called `movies` with two members:\
//	`title`, of type string\
//	`year`, of type int
struct movies {
	string title;
	int year;
};

// Create a new structure called `person` with three members:\
//	`name`, of type string\
//	`age`, of type int\
//	`favMovie`, which is actually an object of another datastructure,
// thus it can be called a nested datastructure
struct people {
	string name;
	int age;
	movies favMovie;
};

// Function to print the full movie information (title and year).\
// The function receives a `movies` object as an argument and then\
// accesses the object's members to print the relevant information
void printMovies (movies movie) {
	cout << "Movie: " << movie.title;
	cout << " (" << movie.year << ")\n";
};

// Function to print all the information of a `people` object. To print\
// the information of its third member (`favMovie`), call the `printMovies()`\
// function since that member is a `movies` object
void printPeople (people person) {
	cout << "My name is " << person.name << " and I'm " << person.age << "\n";
	cout << "My favorite movie is:\n";
	printMovies(person.favMovie);
};

int main() {

	// Create two `movies` objects
	movies a;
	movies b;
	// String to hold the input years for the `year` member
	string tempString;

	// Define the values of both of `a`'s members
	a.title = "Movie A";
	a.year = 2018;

	// Prompt the user for the `title` of the second object
	cout << "Movie title: ";
	getline(cin, b.title);
	// Prompt the user for the `year` of the second object. Since\
	// `getline()`'s second argument must be a string, we save the\
	// user input in a temporary string variable
	cout << "Movie year: ";
	getline(cin, tempString);
	// Then, we use `stringstream()` which allows us to use with a\
	// string the same operations we would use for input/output\
	// streams
	// With `stringstream()` we finally save the the `year` of the\
	// second `movies` object
	stringstream(tempString) >> b.year;

	// Finally, print the full informatin of each movie, with the help of\
	// the `printMovies()` function
	// When calling the `printMovies()` function, we pass it as argument a\
	// whole `movies` object so that the function can have access to all of\
	// the object's members
	cout << "First movie:\n";
	printMovies(a);
	/*
	cout << "Second movie:\n";
	printMovies(b);


	// It it also possible to create an array using a data structure such as `movies`
	movies moviesArray[3];

	cout << "\nGive me 3 more movies\n";
	// Prompt the user to give us information for three movies (each `title` and `year`\
	// pair correspond to an element of the `moviesArray` array)
	for (int i=0; i<3; i++) {
		cout << "Movie title: ";
		getline(cin, moviesArray[i].title);
		cout << "Movie year: ";
		getline(cin, tempString);
		stringstream(tempString) >> moviesArray[i].year;
	}
	cout << "\n";

	// Now print the information of each movie saved in `moviesArray`
	for (int i=0; i<3; i++) {
		printMovies(moviesArray[i]);
	}
	cout << "\n";
	*/


	// Create a new `people` object
	people jose;
	// Now set the values of each of its members
	jose.name = "José";
	jose.age = 20;
	// The third member of any `people` object is a `movies` object\
	// Thus, to access the members of it, just append the `favMovie`\
	// member with the name of the member of `movies` you want to access
	jose.favMovie.title = "Bohemian Rhapsody";
	jose.favMovie.year = 2018;
	// Now print all the information of `jose` with the help of the\
	// `printPeople()` function
	printPeople(jose);
	cout << "\n";

	movies c;
	movies * myPointer = &c;
	// Set the value of the member `title` of the object pointed to (`c`)
	myPointer -> title = "Movie Pointer";
	// Set the value of the member `year` of the object pointed to (`c`)
	myPointer -> year = 2020;
	// Pass the pointer to the `printMovies()` function to print the movie info
	printMovies(*myPointer);

	return 0;
}