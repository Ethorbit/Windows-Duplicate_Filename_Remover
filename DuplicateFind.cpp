#include "DuplicateFind.h"
#include <Windows.h>
#include <iostream>
#include <chrono>

DuplicateFind::DuplicateFind(const char path[]) {
	std::string StrPath(path);
	bool AllFilesScanned = false;
	std::string loadingAnim;

	WIN32_FIND_DATAA FileData{};
	HANDLE FileHandle = FindFirstFileA(StrPath.c_str(), &FileData);

	// Find all quotation marks and remove them:
	for (int i = 0; i < StrPath.length(); i++) {
		char test = '"';
		if (StrPath.at(i) == test) {
			StrPath.erase(i, i + 1);
		}
	}
	
	// Check if the directory ends with a backslash or forward slash:
	if (StrPath.rfind("\\") == StrPath.length() - 1 || StrPath.rfind("/") == StrPath.length() - 1) {
		StrPath = StrPath + "*";
	} else {
		StrPath = StrPath + "\\*";
	}
	
	try {
		if (FileHandle == INVALID_HANDLE_VALUE) {
			throw 109485;
		}
	} catch (int err) {
		std::cout << "ERROR: " << err << " - The directory passed in is either incorrect or the program has insufficient privileges to access it!" << std::endl;
		std::cout << "If you're using a command line, try drag & dropping the folder onto the program instead or relaunch the command line as administrator." << std::endl;
		return;
	}

	std::cout << "Searching for duplicate files in: " << path << std::endl;

	if (FindNextFileA(FileHandle, &FileData) == 0) {
		AllFilesScanned = true;
		std::cout << "All files successfully scanned. Total duplicate filenames: " << duplicateFiles << std::endl;

		if (duplicateFiles > 0) {
			GetUserOption(); // Give them options about what to do with these duplicate files
		}
	}

	while (FindNextFileA(FileHandle, &FileData) != 0) {
		char buffer[FILENAME_MAX];
		wsprintfA(buffer, FileData.cFileName);
		std::cout << "Filename: " << buffer << std::endl;
		duplicateFiles++;
	}
}

void DuplicateFind::GetUserOption() {
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
			
		break;
	}

	// They don't want to do anything with the duplicate files:
	if (userOption >= 3 || userOption < 1) {
		return;
	}
}

void DuplicateFind::MoveFiles() {
	std::string newPath;
	std::cout << "What directory path should the duplicate files be moved to?" << std::endl;
	std::cin >> newPath;
}

void DuplicateFind::RemoveFiles() {

}