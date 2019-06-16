// This file goes over file processing
/*
In C++, to work with files you need to include the fstream library.
This library includes three new data types:
	ofstream: output file stream that creates and writes information to files.
	ifstream: input file stream that reads information from files.
	fstream: general file stream, with both `ofstream` and `ifstream`
capabilities that allow it to create, read and write information to files.

Useful methods
	.open(): opens a file. If it doesn't exist, creates the file. 
	.close(): closes an opened file.
	stream input/output operators: read and write, respectively to te file.
	.isopen(): check if the file is open or not (returns a boolean).
	getline (fileObject, lineVar): reads a line of `fileObject` and saves it
in the `lineVar` string variable.

These are the available options when opening files:
	ios:app - append to the file
	ios::ate - go to the end of the file on opening
	ios::binary - open the file in binary mode
	ios::in - open the file in read-mode
	ios::out - open the file in write-mode
	ios::trunc - delete the contents of the file if it exists
*/

#include <iostream>
#include <fstream> // File operations
#include <string>
using namespace std;

int main() {
	// Create a new object for file processing (this one reads the contents\
	// of an already existing file)
	fstream myFile;
	// Open a .txt file to be read
	myFile.open("cpp_sample_file.txt");

	// Read each line from the file
	// The text of each line is saved in the `line` variable
	string line;
	// If the file is indeed open, read its contents until the end\
	// (and check it's open with `.is_open()`)
	if (myFile.is_open()) {
		while (!myFile.eof()) {
			myFile >> line;
			cout << line << endl;
		}
	}
	
	// Now close the file
	myFile.close();



	// Create a second file object (this one will create a new .txt file)
	fstream myFile2;
	// Open a new file (this one doesn't exist, so we are effectively\
	// creating a new file). We open the file in write-mode and, if it\
	// exists, its contents are deleted upon opening
	myFile2.open("cpp_sample.txt", ios::out | ios::trunc);
	// Alternatively, the file could be opened with the following syntax,\
	// allows the specification of the file path
	// myFile("cpp_sample.txt")
	
	// Write contents to the file	
	myFile2 << "This file was created with a C++ script" << endl;

	// Close the second file
	myFile2.close();

	return 0;
};