// Ethorbit's very first C++ program

#include <iostream>
#include "DuplicateFind.h"
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 2) {
		DuplicateFind find(argv[2]);
	} else if (argc == 1) {
		cout << "No parameters found! Drag & drop a folder or type a directory path (C:/users/Bob/Desktop/SearchThis)" << endl;
	} else if (argc > 1) {
		cout << "Too many parameters! Only pass 1 parameter: a directory path. (C:/users/Bob/Desktop/SearchThis)" << endl;
	}

	system("pause");
}