#include "AddressDuplicates.h"
#include <iostream>
#include <Windows.h>
#include "fixString.h"

AddressDuplicates::AddressDuplicates(DuplicateFind &finder):objRef(finder) {
	int duplicateAmount = finder.GetDuplicates()->size();
	std::cout << "Total duplicate filenames: " << duplicateAmount << "\n\n";
	if (duplicateAmount > 0) {
		GetUserOption();
	}

	std::cout << "Hit any key to exit" << std::endl;
	std::cin.get();
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
	char newPath[FILENAME_MAX] = "";
	std::string strToFix(newPath);

	std::cout << "What directory path should the duplicate files be moved to?" << std::endl;
	while (strlen(newPath) == 0) {
		std::cin.getline(newPath, sizeof(newPath));
		strToFix = newPath;
		fixString fixStr;
		fixStr.removeQuotes(strToFix);
		fixStr.removeSlash(strToFix);
	}

	WIN32_FIND_DATAA FileData;
	HANDLE FileHandle = FindFirstFileA(strToFix.c_str(), &FileData);
	
	while (FileHandle == INVALID_HANDLE_VALUE && strlen(newPath) > 0) {
		std::cout << "The directory: " << strToFix << " didn't work!" << std::endl;
		std::cout << "What directory path should the duplicate files be moved to?" << std::endl;
		std::cin.getline(newPath, sizeof(newPath));
		strToFix = newPath;
		fixString fixStr;
		fixStr.removeQuotes(strToFix);
		fixStr.removeSlash(strToFix);
		FileHandle = FindFirstFileA(strToFix.c_str(), &FileData);
	}

	for (int i = 0; i < objRef.GetDuplicates()->size(); i++) {
		std::string fixNewPath(strToFix);
		std::string FilePath = objRef.getDir() + objRef.GetDuplicates()->at(i);
		std::string NewPath = fixNewPath + "/" + objRef.GetDuplicates()->at(i);

		LPCSTR FixedPath = FilePath.c_str();
		LPCSTR FixedNewPath = NewPath.c_str();
		BOOL FileMove = MoveFileExA(FixedPath, FixedNewPath, MOVEFILE_COPY_ALLOWED);
		
		if (FileMove != 0) {
			std::cout << "Moved " << objRef.GetDuplicates()->at(i) << " to " << NewPath << "\n";
		} 
	}
}

void AddressDuplicates::RemoveFiles() {
	std::string userResp;
	std::cout << "ARE YOU SURE? This will delete all files that the program deems as duplicate.\n";
	std::cout << "If you are unsure, do CTRL + C to cancel and rerun the program but choose the move option instead." << std::endl;
	std::cout << "Type yes to start deletions" << std::endl;
	std::cin >> userResp;

	if (userResp == "yes") {
		for (int i = 0; i < objRef.GetDuplicates()->size(); i++) {
			std::string FilePath = objRef.getDir() + objRef.GetDuplicates()->at(i);
			LPCSTR FixedPath = FilePath.c_str();
			BOOL DelFile = DeleteFileA(FixedPath);
			if (DelFile != 0) {
				std::cout << "Deleted " << objRef.GetDuplicates()->at(i) << " from " << FilePath << "\n";
			}
		}
	}

	std::cout << "Hit any key to exit" << std::endl;
	std::cin.get();
}