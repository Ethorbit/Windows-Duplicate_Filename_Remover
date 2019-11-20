// Ethorbit's very first C++ program

#include <iostream>
#include "DuplicateFind.h"
#include "AddressDuplicates.h"

DuplicateFind* find;

int main(int argc, char* argv[])
{	
	if (argc == 2) {
		find = new DuplicateFind(argv[1]);
	} else if (argc == 1) {
		std::cout << "No parameters found! Drag & drop a folder or type a directory path (C:/users/Bob/Desktop/SearchThis)" << std::endl;
	} else if (argc > 1) {
		std::cout << "Too many parameters! Only pass 1 parameter: a directory path. (C:/users/Bob/Desktop/SearchThis)" << std::endl;
	}

	AddressDuplicates addrDupes(*find);
	delete find;

	std::cin.get();
}