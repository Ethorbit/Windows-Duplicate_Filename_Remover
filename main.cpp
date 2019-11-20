// Ethorbit's very first C++ program

#include <iostream>
#include "DuplicateFind.h"
#include "AddressDuplicates.h"

DuplicateFind* find;
int main(int argc, char* argv[])
{
	if (argc == 2 || argc == 3) {
		int change = 0;
		if (argc == 3) { 
			if (std::string(argv[2]) == "safe") {
				change = 1;
			}	
		}

		find = new DuplicateFind(argv[1], change);
	} else if (argc == 1) {
		std::cout << "No parameters found! Drag & drop a folder or type a directory path (C:/users/Bob/Desktop/SearchThis)" << std::endl;
		std::cout << "Hit any key to exit" << std::endl;
		std::cin.get();
	} else if (argc > 3) {
		std::cout << "Too many parameters! Only pass 1 parameter: a directory path (C:/users/Bob/Desktop/SearchThis) \nor optionally another parameter: the word safe to ensure duplicate files found ARE duplicate." << std::endl;
		std::cout << "Hit any key to exit" << std::endl;
		std::cin.get();
	}


	AddressDuplicates addrDupes(*find);
	delete find;
}