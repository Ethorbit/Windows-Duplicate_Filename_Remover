#include "DuplicateFind.h"
#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>
#include <regex>
#include "Wait.h"

DuplicateFind::DuplicateFind(const char path[], int FindType):FileDir(path) {
	std::string StrPath(path);
	/* Find all quotation marks and remove them: */
	for (int i = 0; i < StrPath.length(); i++) {
		char quot = '"';
		if (StrPath.at(i) == quot) {
			StrPath.erase(i, i + 1);
		}
	}

	std::string ArchivePath(StrPath);
	
	/* Check if the directory ends with a back or forward slash */
	if (StrPath.rfind("\\") == StrPath.length() - 1 || StrPath.rfind("/") == StrPath.length() - 1) {
		StrPath = StrPath + "*";
	} else {
		StrPath = StrPath + "\\*";
		ArchivePath = ArchivePath + "\\";
	}
	
	FileDir = ArchivePath;

	WIN32_FIND_DATAA FileData {};
	HANDLE FileHandle = FindFirstFileA(StrPath.c_str(), &FileData);

	try {
		if (FileHandle == INVALID_HANDLE_VALUE) {
			throw 109485;
		}
	} catch (int err) {
		std::cout << "ERROR: " << err << " - The directory passed in is either incorrect or the program has insufficient privileges to access it!" << std::endl;
		std::cout << "If you're using a command line, try drag & dropping the folder onto the program instead or relaunch the command line as administrator." << std::endl;
		return;
	}

	int ms = 2000;
	if (FindType == 0) {
		std::cout << "Files with (num) or - Copy will be ASSUMED as duplicate files! \n";
		std::cout << "Do CTRL + C to cancel and pass safe as the second argument for full-proof duplicate checking! \n";
		ms = 3000;
	}
	else {
		std::cout << "Using safe mode checking is much slower, consider using normal mode instead\n" << std::endl;
	}

	Wait wait(ms);

	std::cout << "Searching for duplicate files in: " << path << std::endl;

	while (FindNextFileA(FileHandle, &FileData) == 0) {
		std::cout << "Failed \n";
	}

	while (FindNextFileA(FileHandle, &FileData) != 0) {
		char CharFilename[FILENAME_MAX];
		wsprintfA(CharFilename, FileData.cFileName);
		std::string StrFilename(CharFilename);
		
		/* Identify filenames that have - Copy */
		std::smatch matches;
		std::regex findCopy("\\b - Copy\\b");
		std::regex_search(StrFilename, matches, findCopy);
		
		/* Remove the file extensions */
		int ExtensionStart = StrFilename.find(PathFindExtensionA(CharFilename));
		StrFilename.erase(ExtensionStart, StrFilename.length());
		
		/* Remove - Copy from string */
		if (StrFilename.length() > 1) { // If the string is empty it will cause a crash!
			if (matches.size() > 0) {
				if (FindType == 0) {
					std::cout << "Possible duplicate file found: " << CharFilename << "\n";
					DuplicateFiles.push_back(CharFilename);
				}

				while (StrFilename.rfind("Copy") == StrFilename.length() - 4) {
					StrFilename.erase(StrFilename.rfind("Copy") - 3, StrFilename.rfind("Copy"));
				}
			}
		}

		/* Identify filenames that end with (number) ex. (1) (3) (15) */
		if (StrFilename.length() > 1) { 
			if (StrFilename.at(StrFilename.length() - 1) == ')') {
				if (FindType == 0) {
					std::cout << "Possible duplicate file found: " << CharFilename << "\n";
					DuplicateFiles.push_back(CharFilename);
				}

				/* Remove the (number) from the string */ 
				int EraseAmount = 1;
				while (StrFilename.at(StrFilename.length() - EraseAmount) != '(') {
					EraseAmount++;
				}

				StrFilename.erase(StrFilename.length() - EraseAmount, StrFilename.length() - EraseAmount);
			}
		}
		
		if (FindType == 1) {
			for (int i = 0; i < AllFilenames.size(); i++) {
				if (AllFilenames.at(i) == StrFilename) {
					DuplicateFiles.push_back(CharFilename);
					std::cout << "Duplicate file found: " << CharFilename << "\n";
					break;
				}
			}

			AllFilenames.push_back(StrFilename);
		}
	}
}