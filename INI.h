#pragma once
#include <string>

class INI
{
	public:
		INI();
		void TrimPath(char path[]);
	private:
		std::string progDir;
		std::string exeName;
};

