#pragma once
#include <vector>
#include <string>

class DuplicateFind
{	
	public:
		DuplicateFind(const char path[]);

		std::vector<std::string>* GetPossibleDuplicates() {
			return &PossibleDuplicates;
		}

		std::vector<std::string>* GetAllFilenames() {
			return &AllFilenames;
		}
	private:
		std::vector<std::string> PossibleDuplicates;
		std::vector<std::string> AllFilenames;
};

