// Ethorbit's very first C++ program

#include <iostream>
#include "DuplicateFind.h"

int main(int argc, char* argv[])
{	
	if (argc == 2) {
		DuplicateFind find(argv[1]);
	} else if (argc == 1) {
		std::cout << "No parameters found! Drag & drop a folder or type a directory path (C:/users/Bob/Desktop/SearchThis)" << std::endl;
	} else if (argc > 1) {
		std::cout << "Too many parameters! Only pass 1 parameter: a directory path. (C:/users/Bob/Desktop/SearchThis)" << std::endl;
	}

	system("pause");
}