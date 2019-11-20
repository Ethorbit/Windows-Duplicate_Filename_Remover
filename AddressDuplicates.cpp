#include "AddressDuplicates.h"
#include <iostream>

AddressDuplicates::AddressDuplicates(DuplicateFind &finder) {
	int duplicateFiles = 0;
	std::vector<std::string> *checkFiles = finder.GetPossibleDuplicates();
	std::vector<std::string> *allFiles = finder.GetAllFilenames();
	
	if (duplicateFiles > 0) {
		GetUserOption(); // Give them options about what to do with these duplicate files
	}

	for (int a = 0; a < checkFiles->size(); a++) {
		
		for (int b = 0; b < allFiles->size(); b++) {
			std::cout << checkFiles->size() << checkFiles->at(a) << "\n";
		}
	}

	std::cout << "All files successfully scanned. Total duplicate filenames: " << duplicateFiles << std::endl;
}

void AddressDuplicates::GetUserOption() {
	int userOption = 0;
	std::cout << "Press 1. to move them to a different folder" << std::endl;
	std::cout << "Press 2. to delete them" << std::endl;
	std::cout << "Press 3. to do nothing and exit" << std::endl;
	std::cin >> userOption;

	switch (userOption) {
		// They want the files to be sent to a new directory:
		case 1:
			MoveFiles();
		break;

		// They want the duplicate files removed:
		case 2:
			RemoveFiles();
		break;
	}

	// They don't want to do anything with the duplicate files:
	if (userOption >= 3 || userOption < 1) {
		return;
	}
}

void AddressDuplicates::MoveFiles() {
	std::string newPath;
	std::cout << "What directory path should the duplicate files be moved to?" << std::endl;
	std::cin >> newPath;
}

void AddressDuplicates::RemoveFiles() {
}