#include "fixString.h"
#include <iostream>

fixString::fixString() {
}

void fixString::removeQuotes(std::string& originalTxt) {
	for (int i = 0; i < originalTxt.length(); i++) {
		char quot = '"';
		if (originalTxt.at(i) == quot) {
			originalTxt.erase(i, i + 1);
		}
	}
}

void fixString::removeSlash(std::string& originalTxt) {
	if (originalTxt.length() > 0) {
		if (originalTxt.at(originalTxt.length() - 1) == '/' || originalTxt.at(originalTxt.length() - 1) == '\\') {
			originalTxt.pop_back();
		}
	}
}