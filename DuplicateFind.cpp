#include "DuplicateFind.h"
#include <iostream>
#include <Windows.h>
#include <Shlwapi.h>
#include <regex>

DuplicateFind::DuplicateFind(const char path[]) {
	std::string StrPath(path);
	std::string loadingAnim;

	/* Find all quotation marks and remove them: */
	for (int i = 0; i < StrPath.length(); i++) {
		char quot = '"';
		if (StrPath.at(i) == quot) {
			StrPath.erase(i, i + 1);
		}
	}
	
	/* Check if the directory ends with a back or forward slash */
	if (StrPath.rfind("\\") == StrPath.length() - 1 || StrPath.rfind("/") == StrPath.length() - 1) {
		StrPath = StrPath + "*";
	} else {
		StrPath = StrPath + "\\*";
	}
	
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

	std::cout << "Searching for duplicate files in: " << path << std::endl;

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
		
		/* Identify filenames that end with (number) ex. (1) (3) (15) */
		if (StrFilename.length() > 1) { // If the string is empty it will cause a crash!
			if (matches.size() > 0 || StrFilename.at(StrFilename.length() - 1) == ')') {
				std::cout << "Added possible duplicate to list for further checking: " << CharFilename << "\n";
				PossibleDuplicates.push_back(CharFilename);
			}
		}
		
		AllFilenames.push_back(CharFilename);
	}
}