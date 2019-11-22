#pragma once
#include <iostream>

class fixString
{
	public:
		fixString();
		void removeQuotes(std::string& originalTxt);
		void removeSlash(std::string& originalTxt);
};

