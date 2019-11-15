#include "DuplicateFind.h"
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

DuplicateFind::DuplicateFind(const char path[]) {
	bool AllFilesScanned = false;
	string loadingAnim;
	ifstream fileIN(path);

	try {
		if (!fileIN.is_open()) {
			throw 109485;
		}
	}
	catch (int err) {
		cout << "ERROR: " << err << " - The directory passed in is either incorrect or the program has insufficient privileges to access it!" << endl;
		cout << "If you're using a command line, try drag & dropping the folder onto the program instead or relaunch the command line as administrator." << endl;
	}

	
	while (!AllFilesScanned) {
		cout << "Searching for duplicate files in " << path << endl;
	}
}