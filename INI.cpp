#include "INI.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <algorithm>
using namespace std;

INI::INI() {
	char progPath[MAX_PATH];
	GetModuleFileNameA(NULL, progPath, MAX_PATH);
	TrimPath(progPath);
}

void INI::TrimPath(char path[]) {
	string cpdStr(path);
	string newStr;
	int CpdStrLength = cpdStr.length();
	int newStrLength = newStr.length();
	int spaceIterator = 0;

	// Convert \ to /
	while (spaceIterator != cpdStr.length()) { 
		if (cpdStr[spaceIterator] == '\\') {
			newStr += '/';
		}
		else {
			newStr += cpdStr[spaceIterator];
		}
		
		spaceIterator++;
	}

	// Trim executable name
	if (spaceIterator == cpdStr.length()) {
		newStr = newStr.substr(0, newStr.rfind("/"));
		newStr += "/Settings";
		progDir = newStr;
	}
}